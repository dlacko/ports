# Created by: Vanilla I. Shu <vanilla@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/glib20/Makefile,v 1.229 2012/12/09 20:42:55 kwm Exp $
# !! DON'T FORGET ABOUT devel/gio-fam-backend !!

PORTNAME=	glib
PORTVERSION=	2.34.3
PORTREVISION?=	0
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Some useful routines of C programming (current stable version)

LICENSE=	LGPL20

LATEST_LINK=	glib20
USE_XZ=		yes
PORTSCOUT=	limitw:1,even

.if !defined(REFERENCE_PORT)

LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre \
		ffi:${PORTSDIR}/devel/libffi

USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USES=		pkgconfig gettext iconv
USE_GNOME=	gnomehack ltverhack
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_PYTHON=	2.5+
USE_PERL5_BUILD=	yes
CONFIGURE_ARGS=	--enable-static --with-libiconv=gnu \
		--disable-gtk-doc --with-html-dir=${PREFIX}/share/doc \
		--disable-man --without-xml-catalog \
		--with-pcre=system \
		--disable-fam
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

OPTIONS_DEFINE=	COLLATION_FIX DEBUG
COLLATION_FIX_DESC=	fix string collation

.include <bsd.port.pre.mk>

# doesn't build yet
#.if (${OSVERSION} < 800000) \
#	|| (${OSVERSION} >= 800000 && ${OSVERSION} < 802000)
#	|| (${OSVERSION} >= 900000 && ${OSVERSION} < 900021)
CONFIGURE_ARGS+=--disable-dtrace
#.else
#CONFIGURE_ARGS+=--enable-dtrace
#.endif

.if ${ARCH} == powerpc64
EXTRA_PATCHES=	${FILESDIR}/extra-arch-powerpc64
.endif

# Let glib use asm code for implementing atomic ops on i386 and amd64.
.if ${ARCH} == "i386"
GLIB_ARCH=	i486
.elif ${ARCH} == "amd64"
GLIB_ARCH=	x86_64
.else
GLIB_ARCH=	${ARCH}
.endif
CONFIGURE_TARGET=${GLIB_ARCH}-portbld-freebsd${OSREL}

.if ${PORT_OPTIONS:MCOLLATION_FIX}
LIB_DEPENDS+=	icui18n:${PORTSDIR}/devel/icu
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-glib_Makefile.in \
		${FILESDIR}/extra-patch-glib_gunicollate.c
# Disable it until someone can figure why it causes net-im/pidgin crashed.
#CONFIGURE_ENV+=	CFLAGS="-D__STDC_ISO_10646__"
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug=yes \
			--disable-silent-rules
.else
CONFIGURE_ARGS+=	--disable-modular-tests
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g ; \
		s|/usr/share/locale/locale|${LOCALBASE}/share/locale/locale|g' \
			${WRKSRC}/glib/gutils.c
	@${REINPLACE_CMD} -e 's|/lib/dbus/machine-id|/db/dbus/machine-id|g' \
		${WRKSRC}/gio/gdbusaddress.c ${WRKSRC}/gio/gdbusprivate.c \
		${WRKSRC}/po/*.po
	@${REINPLACE_CMD} -e 's|inotify_support=yes|inotify_support=no| ; \
		s|#define HAVE_SYS_INOTIFY_H 1||' ${WRKSRC}/configure

post-install:
	@${MKDIR} ${PREFIX}/share/GConf/gsettings
	-${PREFIX}/bin/gio-querymodules ${PREFIX}/lib/gio/modules

.include <bsd.port.post.mk>

.endif
