# Created by: Yarema <yds@CoolRat.org>
# $FreeBSD$

PORTNAME=	courier
PORTVERSION=	0.65.3
PORTREVISION=	1
CATEGORIES=	mail ipv6
MASTER_SITES=	SF

MAINTAINER=	bsd@dino.sk
COMMENT=	Courier SMTP IMAP POP3 HTTP mail server suite

BUILD_DEPENDS=	courierauthconfig:${PORTSDIR}/security/courier-authlib-base
LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre
RUN_DEPENDS=	courierauthconfig:${PORTSDIR}/security/courier-authlib-base \
		${LOCALBASE}/share/sysconftool/sysconftool:${PORTSDIR}/devel/sysconftool \
		${LOCALBASE}/etc/mime.types:${PORTSDIR}/misc/mime-support \
		p5-Net-CIDR>=0:${PORTSDIR}/net-mgmt/p5-Net-CIDR \
		ca_root_nss>=3.*:${PORTSDIR}/security/ca_root_nss

CONFLICTS=	courier-imap-2.* couriermlm-0.* \
		exim-4.* maildrop-1.* \
		postfix-1.* postfix-2.* \
		qmail-*-1.* qmail-1.* \
		sendmail-*-8.* sendmail-8.* \
		smail-3.* sqwebmail-3.* \
		zmailer-2.*

.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
IS_INTERACTIVE=	yes
.endif

#
# User-serviceable variables
#
# [ There's no need to add trailing ``/''s ]
#
# set IMAGEURL to where on the web server URL the images are found
# set CACHEOWN to who you'd like to own the cache files
# set MAILDROPDEFAULT to what you'd like the $DEFAULT in maildrop to be
#     recomended values are: /var/mail, ./Mailbox or ./Maildir
#
IMAGEURL?=	/webmail
CACHEOWN?=	pop
MAILDROPDEFAULT?=./Maildir
# End of user-serviceable variables
MAILOWN=	courier
MAILGRP=	courier
MAILUID=	465
MAILGID=	465
ETCDIR=		${PREFIX}/etc
SYSCONFDIR=	${ETCDIR}/courier
LIBEXECDIR=	${PREFIX}/libexec
LOCALSTATEDIR=	/var/spool/courier
CACHEDIR=	/var/spool/webmail
CALENDIR=	/var/spool/calendar
MIMETYPES=	${LOCALBASE}/etc/mime.types
WITH_TRANSPORT=	local esmtp dsn

USE_AUTOTOOLS=	libtool aclocal
AUTOMAKE_ARGS=	--add-missing
USE_BZIP2=	yes
USE_GCC=	any
USE_FAM=	yes
USES=		gettext
USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_PERL5=	yes
USE_SUBMAKE=	yes

USE_RC_SUBR=	courier

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV:=	${CONFIGURE_ENV}

CONFIGURE_ARGS=	--disable-root-check \
		--with-db=db \
		--enable-syslog=1 --enable-use-flock \
		--program-transform-name=s,^,, \
		--enable-utf7-folder-encoding \
		--enable-unicode \
		--with-mailuser=${MAILOWN} \
		--with-mailgroup=${MAILGRP} \
		--with-mailuid=${MAILUID} \
		--with-mailgid=${MAILGID} \
		--with-etcdir=${ETCDIR} \
		--sysconfdir=${SYSCONFDIR} \
		--datadir=${DATADIR} \
		--libexecdir=${LIBEXECDIR} \
		--localstatedir=${LOCALSTATEDIR} \
		--enable-mimetypes=${MIMETYPES} \
		--enable-imageurl=${IMAGEURL} \
		--with-cachedir=${CACHEDIR} \
		--with-cacheowner=${CACHEOWN} \
		--with-calendardir=${CALENDIR} \
		--with-certsdir=${SYSCONFDIR} \
		--with-transport='${WITH_TRANSPORT}' \
		--with-default-maildrop=${MAILDROPDEFAULT} \
		--with-paranoid-smtpext \
		--enable-workarounds-for-imap-client-bugs \
		--cache-file=${WRKDIR}/courier.cache

INSTALL_TARGET=	install-strip install-perms

PLIST_SUB+=	BINOWN="${BINOWN}" BINGRP="${BINGRP}" \
		MAILOWN="${MAILOWN}" MAILGRP="${MAILGRP}" \
		MAILUID="${MAILUID}" MAILGID="${MAILGID}" \
		CACHEOWN="${CACHEOWN}" CACHEDIR="${CACHEDIR}" \
		CALENDIR="${CALENDIR}" LOCALSTATEDIR="${LOCALSTATEDIR}"
SUB_LIST:=	${PLIST_SUB}
SUB_FILES+=	pkg-install pkg-message crontab sharedindexupdate

OPTIONS_DEFINE=	LDAP GNUPG PROCMAIL SENDFAX UUCP IPV6 MAILDROPFLAGS \
		WEBMAILFLAGS WEBMAILRSENT
OPTIONS_GROUP=	EXPERIMENTAL
OPTIONS_GROUP_EXPERIMENTAL=	WEBMAILXFACE
OPTIONS_RADIO=	ALIASES SPELL
OPTIONS_RADIO_ALIASES=	SYSTEMALIASES EMPTYALIASES
OPTIONS_RADIO_SPELL=	ASPELL ISPELL

OPTIONS_DEFAULT=WEBMAILRSENT SYSTEMALIASES

LDAP_DESC=	LDAP-based mail aliasing support
GNUPG_DESC=	GNU Privacy Guard support for WebMail
ASPELL_DESC=	ASpell support for WebMail
ISPELL_DESC=	ISpell support for WebMail
PROCMAIL_DESC=	Procmail local delivery support
SENDFAX_DESC=	mgetty+sendfax support
UUCP_DESC=	UUCP support
MAILDROPFLAGS_DESC=	maildrop set flags patch
WEBMAILFLAGS_DESC=	webmail show flags patch
WEBMAILXFACE_DESC=	experimental webmail X-Face patch
WEBMAILRSENT_DESC=	enable Autorename Sent folder
SYSTEMALIASES_DESC=	symlink system /etc/aliases
EMPTYALIASES_DESC=	create empty aliases file

.include <bsd.port.options.mk>
.include "${.CURDIR}/Makefile.doc"
.include "${.CURDIR}/Makefile.man"
.include "${.CURDIR}/Makefile.own"

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	yes
WITH_AUTH_LDAP=	yes
RUN_DEPENDS+=	${LOCALBASE}/lib/courier-authlib/libauthldap.so:${PORTSDIR}/net/courier-authlib-ldap
CONFIGURE_ARGS+=--with-ldapaliasd
PLIST_SUB+=	WITHLDAP=""
SUB_LIST+=	WITHLDAP=""
.else
CONFIGURE_ARGS+=--without-ldapaliasd
PLIST_SUB+=	WITHLDAP="@comment "
SUB_LIST+=	WITHLDAP="@comment "
.endif

.if ${PORT_OPTIONS:MSYSTEMALIASES}
PLIST_SUB+=	WITHSYSTEMALIASES=""
SUB_LIST+=	WITHSYSTEMALIASES=""
.else
PLIST_SUB+=	WITHSYSTEMALIASES="@comment "
SUB_LIST+=	WITHSYSTEMALIASES="@comment "
.endif

.if ${PORT_OPTIONS:MEMPTYALIASES}
PLIST_SUB+=	WITHEMPTYALIASES=""
SUB_LIST+=	WITHEMPTYALIASES=""
.else
PLIST_SUB+=	WITHEMPTYALIASES="@comment "
SUB_LIST+=	WITHEMPTYALIASES="@comment "
.endif

.if exists(${.CURDIR}/../../security/courier-authlib/Makefile.dep)
.include "${.CURDIR}/../../security/courier-authlib/Makefile.dep"
.endif

.if ${PORT_OPTIONS:MGNUPG}
BUILD_DEPENDS+=	gpg:${PORTSDIR}/security/gnupg
RUN_DEPENDS+=	gpg:${PORTSDIR}/security/gnupg
.endif

.if ${PORT_OPTIONS:MASPELL}
BUILD_DEPENDS+=	aspell:${PORTSDIR}/textproc/aspell
RUN_DEPENDS+=	aspell:${PORTSDIR}/textproc/aspell
CONFIGURE_ARGS+=--with-ispell=${LOCALBASE}/bin/aspell
.elif ${PORT_OPTIONS:MISPELL}
BUILD_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
RUN_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
CONFIGURE_ARGS+=--with-ispell=${LOCALBASE}/bin/ispell
.else
CONFIGURE_ARGS+=--without-ispell
.endif

.if ${PORT_OPTIONS:MPROCMAIL}
BUILD_DEPENDS+=	procmail:${PORTSDIR}/mail/procmail
RUN_DEPENDS+=	procmail:${PORTSDIR}/mail/procmail
.endif

.if ${PORT_OPTIONS:MSENDFAX}
USE_GHOSTSCRIPT=yes
SENDFAX_DEPENDS=sendfax:${PORTSDIR}/comms/mgetty+sendfax \
		pnmscale:${PORTSDIR}/graphics/netpbm
BUILD_DEPENDS+=	${SENDFAX_DEPENDS}
RUN_DEPENDS+=	${SENDFAX_DEPENDS}
WITH_TRANSPORT+=fax
PLIST_SUB+=	WITHFAX=""
SUB_LIST+=	WITHFAX=""
.else
PLIST_SUB+=	WITHFAX="@comment "
SUB_LIST+=	WITHFAX="@comment "
.endif

.if ${PORT_OPTIONS:MUUCP}
.if !exists(/usr/bin/uux)
BUILD_DEPENDS+=	uux:${PORTSDIR}/net/freebsd-uucp
RUN_DEPENDS+=	uux:${PORTSDIR}/net/freebsd-uucp
.endif
WITH_TRANSPORT+=uucp
PLIST_SUB+=	WITHUUCP=""
.else
PLIST_SUB+=	WITHUUCP="@comment "
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=--with-ipv6
.else
CONFIGURE_ARGS+=--without-ipv6
.endif

.if ${PORT_OPTIONS:MMAILDROPFLAGS}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-maildrop__maildir.C
.endif

.if ${PORT_OPTIONS:MWEBMAILXFACE}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-webmail__msg2html.c
.endif

.if ${PORT_OPTIONS:MWEBMAILFLAGS}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-webmail__folder.c ${FILESDIR}/extra-patch-webmail__maildir.c
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-webmail__maildir.h ${FILESDIR}/extra-patch-webmail__images__sqwebmail.css
.endif

.if ${PORT_OPTIONS:MWEBMAILRSENT}
CONFIGURE_ARGS+=--enable-autorenamesent
.else
CONFIGURE_ARGS+=--disable-autorenamesent
.endif

pre-everything::
	@${ECHO_MSG} "===> --------------------------------------------------------"
	@${ECHO_MSG} "===>	Run 'make config' to (re)configure ${PKGNAME}"
	@${ECHO_MSG} "===> --------------------------------------------------------"

pre-patch:
	@${CP} ${TEMPLATES}/config.guess ${TEMPLATES}/config.sub ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e 's|^PROG=\./|PROG=exec ./|g' \
		${WRKSRC}/courier/module.*/courier.config
	@${REINPLACE_CMD} -e 's|@mydatadir@|@sysconfdir@|g' \
		${WRKSRC}/*/mk*cert.* \
		${WRKSRC}/*/*/mk*cert.*
	@${REINPLACE_CMD} -e 's|^\(TLS_CERTFILE=\)@mydatadir@|\1@sysconfdir@|g' \
		${WRKSRC}/*/*.dist.in \
		${WRKSRC}/*/*/*.dist.in
	@${REINPLACE_CMD} -e 's|^\(RANDFILE[[:space:]]*=[[:space:]]*\)@mydatadir@|\1@sysconfdir@|g' \
		${WRKSRC}/*/*.cnf.openssl.in \
		${WRKSRC}/*/*/*.cnf.openssl.in
	@${REINPLACE_CMD} -e 's|$$(INSTALL_DATA) \(.$$$$file.\)|${INSTALL_MAN} \1|' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/*/Makefile.in \
		${WRKSRC}/*/*/Makefile.in \
		${WRKSRC}/*/*/*/Makefile.in
	@${REINPLACE_CMD} -e 's|^\(INSTALL_STRIP_PROGRAM=\).*$$|\1"${INSTALL_PROGRAM} -s"|' \
			-e 's|; ldapaliasd="yes"||' \
		${WRKSRC}/configure \
		${WRKSRC}/*/configure \
		${WRKSRC}/*/*/configure \
		${WRKSRC}/*/*/*/configure
	@${REINPLACE_CMD} -E -e 's/(root|bin)[[:space:]]*bin/root	wheel/g' \
		${WRKSRC}/courier/perms.sh.in

pre-configure:
	@if [ -f "${WRKDIR}/courier.cache" -a -s "${WRKDIR}/courier.cache" ]; then \
		${RM} -f "${WRKDIR}/courier.cache"; \
	fi
	@cp ${LOCALBASE}/share/gettext/po/Makefile.in.in ${WRKSRC}/pcp/po
	@cp ${LOCALBASE}/share/libtool/config/ltmain.sh ${WRKSRC}
.for oldlt in . bdbobj cgi courier courier/libs courier/filters courier/filters/perlfilter courier/module.dsn courier/module.esmtp courier/module.local courier/module.uucp gdbmobj gpglib http11 imap ldapaddressbook libhmac liblock maildir maildrop makedat md5 numlib pcp random128 rfc822 rfc1035 rfc2045 sha1 tcpd unicode webmail
	@cd ${WRKSRC}/${oldlt} && ${SETENV} ${SCRIPTS_ENV} ${SH} /usr/local/bin/aclocal
.endfor

post-build:
	@${PERL} -pi -e 's|^(auth)\s+(required).*|$$1\t\t$$2\tpam_unix.so\ttry_first_pass|g;' \
		     -e 's|^(account)\s+(required).*|$$1 \t$$2\tpam_unix.so|g;' \
		     -e 's|^(session)\s+(required).*|$$1 \t$$2\tpam_permit.so|g;' \
		${WRKSRC}/*/*.authpam* \
		${WRKSRC}/*/*/*.authpam*
	@${LN} -f ${WRKSRC}/gpglib/README.html		${WRKSRC}/gpglib/README.gpglib.html
	@${LN} -f ${WRKSRC}/imap/BUGS			${WRKSRC}/imap/BUGS.imap
	@${LN} -f ${WRKSRC}/imap/BUGS.html		${WRKSRC}/imap/BUGS.imap.html
	@${LN} -f ${WRKSRC}/imap/README			${WRKSRC}/imap/README.imap
	@${LN} -f ${WRKSRC}/imap/README.html		${WRKSRC}/imap/README.imap.html
	@${LN} -f ${WRKSRC}/maildrop/README.html	${WRKSRC}/maildrop/README.maildrop.html
	@${LN} -f ${WRKSRC}/pcp/README.html		${WRKSRC}/pcp/README.pcp.html
	@${LN} -f ${WRKSRC}/webmail/BUGS		${WRKSRC}/webmail/BUGS.webmail
	@${LN} -f ${WRKSRC}/webmail/BUGS.html		${WRKSRC}/webmail/BUGS.webmail.html
	@${LN} -f ${WRKSRC}/webmail/SECURITY		${WRKSRC}/webmail/SECURITY.webmail
	@${LN} -f ${WRKSRC}/webmail/SECURITY.html	${WRKSRC}/webmail/SECURITY.webmail.html

post-install:
	@${LN} -f ${SYSCONFDIR}/maildrop ${SYSCONFDIR}/maildropfilter
	@${INSTALL_DATA} /dev/null ${SYSCONFDIR}/locallowercase
	@${INSTALL_DATA} ${WRKDIR}/crontab ${SYSCONFDIR}/
	@${INSTALL_SCRIPT} ${WRKDIR}/sharedindexupdate ${DATADIR}/
.for file in ${OWNER0}
	@-${CHOWN} -Rh ${BINOWN}:${BINGRP} ${PREFIX}/${file}
.endfor
	@${GREP} '^@exec ' ${TMPPLIST} \
		| ${SED} -e 's:^@exec ::' -e 's:%D:${PREFIX}:g' \
		> ${WRKDIR}/.PLIST.exec \
		&& ${SH} ${WRKDIR}/.PLIST.exec
.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL} ${_DOCOWNGRP} -d ${DOCSDIR}/html
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.for f in ${HTMLDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/html
.endfor
	@${INSTALL_DATA} ${DATADIR}/htmldoc/* ${DOCSDIR}/html
.endif
	@${RM} -rf ${DATADIR}/htmldoc
	@-${CHOWN} -Rh ${SHAREOWN}:${SHAREGRP} ${DATADIR}
	@${CHMOD} -R a+r ${DATADIR}/courierwebadmin
	@${CHMOD} -R a-w ${DATADIR} ${LIBEXECDIR}/courier
	@${CHMOD} 550 ${LIBEXECDIR}/courier/modules/esmtp/courieresmtp*
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}
.if defined(BATCH) || defined(PACKAGE_BUILDING)
	@${ECHO_MSG} "	To activate Courier in /etc/mail/mailer.conf or to"
	@${ECHO_MSG} "	replace {sendmail,mailq,newaliases} with Courier"
	@${ECHO_MSG} "	versions execute the following as root user:"
	@${ECHO_MSG}
	@${ECHO_MSG} "PKG_PREFIX=\"${PREFIX}\" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL"
	@${ECHO_MSG}
.else
	@PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.mk>
