# Created by: Martin Wilke (miwi@FreeBSD.org)
# $FreeBSD$
#

PORTNAME=	xfce4-time-out-plugin
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	x11-clocks xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	A timer out plugin for Xfce

USE_BZIP2=	yes
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
USES=		gettext pkgconfig pathfix
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 intltool intlhack
USE_XFCE=	configenv libmenu libutil panel

.include <bsd.port.mk>
