# New ports collection makefile for:	asapm
# Date created:		6 Aug 1998
# Whom:			Brian Handy <handy@physics.montana.edu>
#
# $FreeBSD$
#

PORTNAME=	asapm
PORTVERSION=	3.1
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.tigr.net/afterstep/download/asapm/

MAINTAINER=	gamato@users.sf.net
COMMENT=	Laptop battery status display for X11

ONLY_FOR_ARCHS=	i386

USE_XORG=	xpm
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install install.man

MAN1=		asapm.1
PLIST_FILES=	bin/asapm

.include <bsd.port.mk>
