# New ports collection makefile for:    FDclone
# Date created:         20 Feb 1996
# Whom:                 Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $FreeBSD$
#

PORTNAME=	fd
PORTVERSION=	3.01a
CATEGORIES=	shells net
MASTER_SITES=	http://hp.vector.co.jp/authors/VA012337/soft/fd/ \
		ftp://ftp.unixusers.net/src/fdclone/
DISTNAME=	FD-${PORTVERSION}

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A CUI-based file and directory management tool

MANLANG=	"" ja
MAN1=		fd.1 fdsh.1
MAKE_ENV=	LANG=ja
MAKE_ARGS=	CC="${CC}" CONFDIR="${PREFIX}/etc"
MAKE_JOBS_SAFE=	yes

DOCS_EN=	FAQ.eng \
		LICENSES.eng \
		README.eng \
		TECHKNOW.eng \
		ToAdmin.eng
DOCS_JA=	FAQ \
		HISTORY \
		LICENSES \
		README \
		TECHKNOW \
		ToAdmin

post-configure:
	${REINPLACE_CMD} -E -e 's|^(#[[:space:]]*define[[:space:]]+EXTENDCCOPT[[:space:]]+"([^"]+ )?)-O(["[:space:]])|\1${CFLAGS}\3|' ${WRKSRC}/machine.h

post-install:
	@${ECHO} "Updating /etc/shells"
	@-${CP} /etc/shells /etc/shells.bak; \
		(${GREP} -v ${PREFIX}/bin/fdsh /etc/shells.bak; \
		${ECHO_CMD} ${PREFIX}/bin/fdsh) > /etc/shells; \
		${RM} -f /etc/shells.bak
	@${INSTALL_DATA} ${WRKSRC}/_fdrc.orig ${PREFIX}/etc/fd2rc.dist
	@${INSTALL_DATA} ${WRKSRC}/_fdrc ${PREFIX}/etc/fd2rc.sample
	if [ ! -f ${PREFIX}/etc/fd2rc ]; then \
		${CP} -p ${PREFIX}/etc/fd2rc.sample ${PREFIX}/etc/fd2rc; \
	fi
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${PREFIX}/share/doc/ja/${PORTNAME}
	@for i in ${DOCS_EN}; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${DOCSDIR}; \
	done
	@for i in ${DOCS_JA}; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/doc/ja/${PORTNAME}; \
	done
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc: tzfile.h: No such file or directory
.endif

.include <bsd.port.post.mk>
