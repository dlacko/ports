# New ports collection makefile for:	gnomesystemtools
# Date created:				17 May 2004
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/gnome-system-tools/Makefile,v 1.103 2010/10/25 09:44:29 kwm Exp $
#

PORTNAME=	gnome-system-tools
PORTVERSION=	2.32.0
PORTREVISION=	2
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Tools to configure workstations

LIB_DEPENDS=	oobs-1.5:${PORTSDIR}/devel/liboobs \
		polkit-gtk-1.0:${PORTSDIR}/sysutils/polkit-gnome

USE_BZIP2=	yes
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
USES=		gettext
USE_LDCONFIG=	yes
GNOME_DESKTOP_VERSION=2
USE_GNOME=	gnomehack gnomeprefix intlhack nautilus2
USE_AUTOTOOLS=	libtool
INSTALLS_OMF=	yes
CONFIGURE_ARGS=	--enable-services
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.system-tools.gschema.xml

.include <bsd.port.mk>
