# Created by: Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
# $FreeBSD$
#

PORTNAME=	integrit
PORTVERSION=	4.1
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	jos@catnook.com
COMMENT=	File integrity verification program

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes
ALL_TARGET=	${PORTNAME} utils

PLIST_FILES=	bin/i-ls sbin/i-viewdb sbin/integrit
MAN1=		i-ls.1 i-viewdb.1 integrit.1
INFO=		integrit

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.include <bsd.port.post.mk>
