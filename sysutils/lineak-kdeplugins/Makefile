# New ports collection makefile for:	lineak-kdeplugins
# Date created:		2004-12-29
# Whom:			Kay Lehmann <kay_lehmann@web.de>
#
# $FreeBSD$
#

PORTNAME=	lineak-kdeplugins
PORTVERSION=	0.9
PORTREVISION=	6
CATEGORIES=	sysutils deskutils
MASTER_SITES=	SF/lineak/lineak_kdeplugins/${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	lineak

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE plugins for lineakd

LIB_DEPENDS=	lineak.8:${PORTSDIR}/sysutils/lineakd

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--program-prefix=''

MAN1=		lineak_kdeplugins.1
#MANCOMPRESSED=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/configure

.include <bsd.port.mk>
