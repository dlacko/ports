# New ports collection makefile for:	id3lib
# Date Created:				26 Oct 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	id3lib
PORTVERSION=	3.8.3
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	kaeru@inigo-tech.com
COMMENT=	Library for manipulating ID3v1/v1.1 and ID3v2 tags

USE_AUTOTOOLS=	libtool
USES=		iconv
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-extract:
	@${RM} -rf ${WRKSRC}/zlib

post-patch:
	@${REINPLACE_CMD} '/main/s/unsigned int/int/' \
		${WRKSRC}/examples/demo_*.cpp
	@${REINPLACE_CMD} 's/\(iomanip\)\.h/\1/' ${WRKSRC}/configure
	@${REINPLACE_CMD} '/include.*/{ p; s//include <cstring>/; n;n;n; }' \
		${WRKSRC}/include/id3/id3lib_strings.h \
		${WRKSRC}/include/id3/writers.h

.include <bsd.port.mk>
