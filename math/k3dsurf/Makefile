# Created by: thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	k3dsurf
PORTVERSION=	0.6.2.4
CATEGORIES=	math graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}_Linux/${PORTVERSION:R}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Visualize and manipulate Mathematical surfaces or curves

LICENSE=	GPLv2

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_GL=		yes
USE_QT_VER=	3
QTDIR=		${QT_PREFIX}
MAKE_ENV=	QMAKESPEC="${LOCALBASE}/share/qt/mkspecs/freebsd-g++"	\
		QTDIR="${QTDIR}" PTHREAD_LIBS="${PTHREAD_LIBS}"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/k3dsurf

pre-build:
	cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} qmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/k3dsurf ${PREFIX}/bin

.include <bsd.port.mk>
