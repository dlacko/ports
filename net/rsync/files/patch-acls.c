--- /dev/null	2011-10-20 23:09:29.000000000 -0700
+++ ./acls.c	2011-10-20 23:11:41.000000000 -0700
@@ -79,20 +79,35 @@
 	uchar other_obj;
 } rsync_acl;
 
+typedef struct nfs4_acl {
+	char *nfs4_acl_text;
+	ssize_t nfs4_acl_len;
+} nfs4_acl;
+
 typedef struct {
 	rsync_acl racl;
 	SMB_ACL_T sacl;
 } acl_duo;
 
+typedef struct {
+	nfs4_acl nacl;
+	SMB_ACL_T sacl;
+} nfs4_duo;
+
 static const rsync_acl empty_rsync_acl = {
 	{NULL, 0}, NO_ENTRY, NO_ENTRY, NO_ENTRY, NO_ENTRY
 };
+static const nfs4_acl empty_nfs4_acl = {
+	NULL, -1
+};
 
 static item_list access_acl_list = EMPTY_ITEM_LIST;
 static item_list default_acl_list = EMPTY_ITEM_LIST;
+static item_list nfs4_acl_list = EMPTY_ITEM_LIST;
 
 static size_t prior_access_count = (size_t)-1;
 static size_t prior_default_count = (size_t)-1;
+static size_t prior_nfs4_count = (size_t)-1;
 
 /* === Calculations on ACL types === */
 
@@ -188,6 +203,17 @@
 	return racl;
 }
 
+static nfs4_acl *create_nfs4_acl(void)
+{
+	nfs4_acl *nacl = new(nfs4_acl);
+
+	if (!nacl)
+		out_of_memory("create_nfs4_acl");
+	*nacl = empty_nfs4_acl;
+
+	return nacl;
+}
+
 static BOOL ida_entries_equal(const ida_entries *ial1, const ida_entries *ial2)
 {
 	id_access *ida1, *ida2;
@@ -212,6 +238,11 @@
 	    && ida_entries_equal(&racl1->names, &racl2->names);
 }
 
+static BOOL nfs4_acl_equal(const nfs4_acl *nacl1, const nfs4_acl *nacl2)
+{
+	return (strcmp(nacl1->nfs4_acl_text, nacl2->nfs4_acl_text) == 0);
+}
+
 /* Are the extended (non-permission-bit) entries equal?  If so, the rest of
  * the ACL will be handled by the normal mode-preservation code.  This is
  * only meaningful for access ACLs!  Note: the 1st arg is a fully-populated
@@ -245,6 +276,13 @@
 	*racl = empty_rsync_acl;
 }
 
+static void nfs4_acl_free(nfs4_acl *nacl)
+{
+	if (nacl->nfs4_acl_text)
+		free(nacl->nfs4_acl_text);
+	*nacl = empty_nfs4_acl;
+}
+
 void free_acl(stat_x *sxp)
 {
 	if (sxp->acc_acl) {
@@ -257,6 +295,11 @@
 		free(sxp->def_acl);
 		sxp->def_acl = NULL;
 	}
+	if (sxp->nfs4_acl) {
+		nfs4_acl_free(sxp->nfs4_acl);
+		free(sxp->nfs4_acl);
+		sxp->nfs4_acl = NULL;
+	}
 }
 
 #ifdef SMB_ACL_NEED_SORT
@@ -487,6 +530,26 @@
 	return *match;
 }
 
+static int find_matching_nfs4_acl(const nfs4_acl *nacl, const item_list *nfs4_acl_list)
+{
+	static int nfs4_match = -1;
+	int *match = &nfs4_match;
+	size_t count = nfs4_acl_list->count;
+
+	if (*match == -1)
+		*match = nfs4_acl_list->count - 1;
+	while (count--) {
+		nfs4_acl *base = nfs4_acl_list->items;
+		if (nfs4_acl_equal(base + *match, nacl))
+			return *match;
+		if (!(*match)--)
+			*match = nfs4_acl_list->count - 1;
+	}
+
+	*match = -1;
+	return *match;
+}
+
 static int get_rsync_acl(const char *fname, rsync_acl *racl,
 			 SMB_ACL_TYPE_T type, mode_t mode)
 {
@@ -551,6 +614,21 @@
 /* Return the Access Control List for the given filename. */
 int get_acl(const char *fname, stat_x *sxp)
 {
+	if (sys_acl_get_brand_file(fname, &sxp->brand) < 0)
+		return -1;
+
+	if (sxp->brand == SMB_ACL_BRAND_NFS4) {
+		SMB_ACL_T sacl;
+		if ((sacl = sys_acl_get_file(fname, SMB_ACL_TYPE_NFS4)) == NULL)
+			return -1;
+
+		sxp->nfs4_acl = create_nfs4_acl();
+		sxp->nfs4_acl->nfs4_acl_text = acl_to_text(sacl, &sxp->nfs4_acl->nfs4_acl_len);
+
+		sys_acl_free_acl(sacl);
+		return 0;
+	}
+
 	sxp->acc_acl = create_racl();
 
 	if (S_ISREG(sxp->st.st_mode) || S_ISDIR(sxp->st.st_mode)) {
@@ -748,6 +826,25 @@
 	}
 }
 
+void send_nfs4_acl(int f, nfs4_acl *nacl, item_list *nfs4_list)
+{
+	int ndx = find_matching_nfs4_acl(nacl, nfs4_list);
+
+	/* Send 0 (-1 + 1) to indicate that literal ACL data follows. */
+	write_varint(f, ndx + 1);
+
+	if (ndx < 0) {
+		nfs4_acl *new_nacl = EXPAND_ITEM_LIST(&nfs4_acl_list, nfs4_acl, 1000);
+
+		write_varint(f, nacl->nfs4_acl_len);
+		write_buf(f, nacl->nfs4_acl_text, nacl->nfs4_acl_len);
+
+		*new_nacl = *nacl;
+		*nacl = empty_nfs4_acl;
+	}
+}
+
+
 /* Send the ACL from the stat_x structure down the indicated file descriptor.
  * This also frees the ACL data. */
 void send_acl(int f, stat_x *sxp)
@@ -757,6 +854,12 @@
 		return;
 	}
 
+	if (sxp->brand == SMB_ACL_BRAND_NFS4) {
+		write_varint(f, SMB_ACL_TYPE_NFS4);
+		send_nfs4_acl(f, sxp->nfs4_acl, &nfs4_acl_list);
+		return;
+	}
+
 	if (!sxp->acc_acl) {
 		sxp->acc_acl = create_racl();
 		rsync_acl_fake_perms(sxp->acc_acl, sxp->st.st_mode);
@@ -764,12 +867,14 @@
 	/* Avoid sending values that can be inferred from other data. */
 	rsync_acl_strip_perms(sxp);
 
+	write_varint(f, SMB_ACL_TYPE_ACCESS);
 	send_rsync_acl(f, sxp->acc_acl, SMB_ACL_TYPE_ACCESS, &access_acl_list);
 
 	if (S_ISDIR(sxp->st.st_mode)) {
 		if (!sxp->def_acl)
 			sxp->def_acl = create_racl();
 
+		write_varint(f, SMB_ACL_TYPE_DEFAULT);
 		send_rsync_acl(f, sxp->def_acl, SMB_ACL_TYPE_DEFAULT, &default_acl_list);
 	}
 }
@@ -1046,15 +1151,58 @@
 	return ndx;
 }
 
+
+static int recv_nfs4_acl(int f, item_list *nfs4_acl_list, struct file_struct *file)
+{
+	nfs4_duo *duo_item;
+	int ndx = read_varint(f);
+
+	if (ndx < 0 || (size_t)ndx > nfs4_acl_list->count) {
+		rprintf(FERROR_XFER, "recv_nfs4_index: %s ACL index %d > %d\n",
+			str_acl_type(SMB_ACL_TYPE_NFS4), ndx, (int)nfs4_acl_list->count);
+		exit_cleanup(RERR_STREAMIO);
+	}
+        
+	if (ndx != 0)
+		return ndx - 1;
+
+	ndx = nfs4_acl_list->count;
+	duo_item = EXPAND_ITEM_LIST(nfs4_acl_list, nfs4_duo, 1000);
+	duo_item->nacl = empty_nfs4_acl;
+
+	duo_item->nacl.nfs4_acl_len = read_varint(f);
+	duo_item->nacl.nfs4_acl_text = new_array(char, duo_item->nacl.nfs4_acl_len + 1);
+	if (!duo_item->nacl.nfs4_acl_text)
+		out_of_memory("recv_nfs4_acl");
+
+	read_buf(f, duo_item->nacl.nfs4_acl_text, duo_item->nacl.nfs4_acl_len);
+	duo_item->nacl.nfs4_acl_text[duo_item->nacl.nfs4_acl_len] = 0;
+
+	duo_item->sacl = NULL;
+	return ndx;
+}
+
+
 /* Receive the ACL info the sender has included for this file-list entry. */
 void receive_acl(int f, struct file_struct *file)
 {
+	int ndx;
+	SMB_ACL_TYPE_T type;
+
 	if (protocol_version < 30) {
 		old_recv_acl(file, f);
 		return;
 	}
 
-	F_ACL(file) = recv_rsync_acl(f, &access_acl_list, SMB_ACL_TYPE_ACCESS, file->mode);
+	type = read_varint(f);
+	if (type == SMB_ACL_TYPE_NFS4){
+		ndx = recv_nfs4_acl(f, &nfs4_acl_list, file);
+		F_ACL(file) = ndx;
+		return;
+	}	
+
+	ndx = recv_rsync_acl(f, &access_acl_list, SMB_ACL_TYPE_ACCESS, file->mode);
+	F_ACL(file) = ndx;
 
 	if (S_ISDIR(file->mode))
 		F_DIR_DEFACL(file) = recv_rsync_acl(f, &default_acl_list, SMB_ACL_TYPE_DEFAULT, 0);
@@ -1078,10 +1226,37 @@
 	return ndx;
 }
 
+static int cache_nfs4_acl(nfs4_acl *nacl, item_list *nfs4_list)
+{
+	int ndx;
+
+	if (!nacl)
+		ndx = -1;
+	else if ((ndx = find_matching_nfs4_acl(nacl, nfs4_list)) == -1) {
+		nfs4_duo *new_duo;
+		ndx = nfs4_list->count;
+		new_duo = EXPAND_ITEM_LIST(nfs4_list, nfs4_duo, 1000);
+		new_duo->nacl = *nacl;
+		new_duo->sacl = NULL;
+		*nacl = empty_nfs4_acl;
+	}
+
+	return ndx;
+}
+
+
 /* Turn the ACL data in stat_x into cached ACL data, setting the index
  * values in the file struct. */
 void cache_tmp_acl(struct file_struct *file, stat_x *sxp)
 {
+	if (sxp->brand == SMB_ACL_BRAND_NFS4) {
+		if (prior_nfs4_count == (size_t)-1)
+			prior_nfs4_count = nfs4_acl_list.count;
+
+		F_ACL(file) = cache_nfs4_acl(sxp->nfs4_acl, &nfs4_acl_list);
+		return;
+	}
+
 	if (prior_access_count == (size_t)-1)
 		prior_access_count = access_acl_list.count;
 
@@ -1111,6 +1286,21 @@
 	}
 }
 
+static void uncache_nfs4_acls(item_list *nfs4_list, size_t start)
+{
+	nfs4_duo *nfs4_item = nfs4_list->items;
+	nfs4_duo *nfs4_start = nfs4_item + start;
+
+	nfs4_item += nfs4_list->count;
+	nfs4_list->count = start;
+
+	while (nfs4_item-- > nfs4_start) {
+		nfs4_acl_free(&nfs4_item->nacl);
+		if (nfs4_item->sacl)
+			sys_acl_free_acl(nfs4_item->sacl);
+	}
+}
+
 void uncache_tmp_acls(void)
 {
 	if (prior_access_count != (size_t)-1) {
@@ -1122,6 +1312,10 @@
 		uncache_duo_acls(&default_acl_list, prior_default_count);
 		prior_default_count = (size_t)-1;
 	}
+	if (prior_nfs4_count != (size_t)-1) {
+		uncache_nfs4_acls(&nfs4_acl_list, prior_nfs4_count);
+		prior_nfs4_count = (size_t)-1;
+	}
 }
 
 #ifndef HAVE_OSX_ACLS
@@ -1274,6 +1468,7 @@
 	return 0;
 }
 
+
 /* Given a fname, this sets extended access ACL entries, the default ACL (for a
  * dir), and the regular mode bits on the file.  Call this with fname set to
  * NULL to just check if the ACL is different.
@@ -1293,6 +1488,32 @@
 		return -1;
 	}
 
+	if (sxp->brand == SMB_ACL_BRAND_NFS4) {
+		ndx = F_ACL(file);
+		if (ndx >= 0 && (size_t)ndx < nfs4_acl_list.count) {
+			nfs4_duo *duo_item = nfs4_acl_list.items;
+			duo_item += ndx;
+			changed = 1;
+
+			if (!duo_item->sacl) {
+				duo_item->sacl = acl_from_text(duo_item->nacl.nfs4_acl_text);
+				if (!duo_item->sacl)
+					return -1;
+			}
+
+			if (!dry_run && fname) {
+				if (sys_acl_set_file(fname, SMB_ACL_TYPE_NFS4, duo_item->sacl) < 0) {
+					rsyserr(FERROR_XFER, errno, "set_acl: sys_acl_set_file(%s, %s)",
+						fname, str_acl_type(SMB_ACL_TYPE_NFS4));
+					return -1;
+				}
+
+				return changed;
+			}
+		}
+	}
+
+
 	ndx = F_ACL(file);
 	if (ndx >= 0 && (size_t)ndx < access_acl_list.count) {
 		acl_duo *duo_item = access_acl_list.items;
