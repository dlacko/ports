# ex:ts=8
# Ports collection makefile for:	gaul
# Date created:			Oct 28, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gaul
PORTVERSION=	0.1849.0
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-devel/0.1849
DISTNAME=	${PORTNAME}-devel-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Genetic Algorithm Utility Library

LIB_DEPENDS=	slang.2:${PORTSDIR}/devel/libslang2

MAKE_JOBS_SAFE=  yes

USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lcurses
USE_LDCONFIG=	yes

.include <bsd.port.mk>
