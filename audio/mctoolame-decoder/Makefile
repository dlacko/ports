# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mctoolame
PORTVERSION=	0.1.a
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}d/${PORTNAME}d-01a
PKGNAMESUFFIX=	-decoder
DISTNAME=	${PORTNAME}d-${PORTVERSION:C/\.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MPEG Layer II audio decoder with multi-channel support

USE_GMAKE=	yes
ALL_TARGET=	#
MAKE_ARGS=	CC="${CC}" OPTIM="${CFLAGS}"
PLIST_SUB=	PKGNAMESUFFIX="${PKGNAMESUFFIX}"

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|$$(ARCH)||' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -E \
		's|gets *\(([^,)]+)\)|fgets(\1, sizeof(\1), stdin)|' \
			${WRKSRC}/musicout.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mctoolamed ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}${PKGNAMESUFFIX}/html
	${INSTALL_DATA} ${WRKSRC}/html/* ${DOCSDIR}${PKGNAMESUFFIX}/html
.endif

.include <bsd.port.mk>
