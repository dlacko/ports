# Created by: Alejandro Pulver <alepulver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	egl
PORTVERSION=	0.3.1
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://freebsd.nsu.ru/distfiles/
DISTNAME=	${PORTNAME}-v${PORTVERSION}-stable-src
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} egl.pkz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Enhanced OpenGL-only Quake II engine

USE_ZIP=	yes
USE_DOS2UNIX=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile
NO_WRKSUBDIR=	yes

MAKE_ENV=	LIBDIR="${LIBDIR}" PTHREAD_LIBS="${PTHREAD_LIBS}"
PLIST_SUB=	LIBDIR="${LIBDIR:S/${PREFIX}\///}"
LIBDIR=		${PREFIX}/lib/${PORTNAME}

OPTIONS_DEFINE=	CLIENT DEDICATED GAME OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=	CLIENT DEDICATED GAME OPTIMIZED_CFLAGS

CLIENT_DESC=	Build client
DEDICATED_DESC=	Build dedicated server
GAME_DESC=	Build main game (default mod)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLIENT}
LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png
USE_GL=		gl
CFLAGS+=	-I${LOCALBASE}/include/libpng15
MAKE_ENV*=	CFLAGS="${CFLAGS}"
PLIST_SUB+=	CLIENT=""
EGL_BIN+=	egl
.else
MAKE_ENV+=	BUILD_CLIENT=NO \
		BUILD_CGAME=NO
PLIST_SUB+=	CLIENT="@comment "
.endif

.if ${PORT_OPTIONS:MDEDICATED}
PLIST_SUB+=	DEDICATED=""
EGL_BIN+=	eglded
.else
MAKE_ENV+=	BUILD_DEDICATED=NO
PLIST_SUB+=	DEDICATED="@comment "
.endif

.if ${PORT_OPTIONS:MGAME}
PLIST_SUB+=	GAME=""
.else
MAKE_ENV+=	BUILD_GAME=NO
PLIST_SUB+=	GAME="@comment "
.endif

.if ! ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
MAKE_ENV+=	WITH_OPT_CFLAGS=NO
.endif

do-install:
.for f in ${EGL_BIN}
	${INSTALL_PROGRAM} ${WRKSRC}/release/${f} ${PREFIX}/bin
.endfor
	@${MKDIR} ${LIBDIR}/baseq2
	${INSTALL_PROGRAM} ${WRKSRC}/release/baseq2/*.so ${LIBDIR}/baseq2
	${INSTALL_DATA} ${DISTDIR}/egl.pkz ${LIBDIR}/baseq2

.include "${.CURDIR}/../quake2-data/Makefile.include"
.include <bsd.port.mk>
