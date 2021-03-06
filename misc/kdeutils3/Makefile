# New ports collection makefile for:	kdeutils3
# Date created:				3 November 2001
# Whom:					will@cvs.kde.org
#
# $FreeBSD$
#

PORTNAME=	kdeutils
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	10
CATEGORIES?=	misc kde
MASTER_SITES=		${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
DIST_SUBDIR=	KDE

MAINTAINER?=	ports@FreeBSD.org
COMMENT=	Utilities for the KDE integrated X11 desktop

LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp \
		netsnmp:${PORTSDIR}/net-mgmt/net-snmp
RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg \
		gtar:${PORTSDIR}/archivers/gtar

CONFLICTS=	kgpg-[0-9]* superkaramba-[0-9]*

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_KDELIBS_VER=3
USE_KDEBASE_VER=3

USE_PYTHON=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
DO_NOT_COMPILE+=klaptopdaemon kmilo
CONFIGURE_ENV+=	DO_NOT_COMPILE="${DO_NOT_COMPILE}"
CONFIGURE_ARGS+=--with-pythondir=${LOCALBASE}

USE_LDCONFIG=	yes

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"

post-patch:
	${REINPLACE_CMD} -e 's|>tar<|>gtar<|g' ${WRKSRC}/ark/ark.kcfg
	${REINPLACE_CMD} -e 's|%%PYTHON_VER%%|${PYTHON_VER}|g' \
		-e 's|%%LTMAIN%%|${LTMAIN}|g' \
		-e 's|%%LIBTOOL%%|${LIBTOOL}|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
