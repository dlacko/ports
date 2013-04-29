# $FreeBSD$
#
# handle dependency on the pkgconf port
#
# MAINTAINER: portmgr@FreeBSD.org
#
# Feature:	pkgconfig
# Usage:	USES=pkgconfig or USES=pkgconfig:ARGS
# Valid ARGS:	build (default, implicit), run, both
#
#
.if !defined(_INCLUDE_USES_PKGCONFIG_MK)
_INCLUDE_USES_PKGCONFIG_MK=	yes

_PKGCONFIG_DEPENDS=	pkgconf:${PORTSDIR}/devel/pkgconf

.if !defined(pkgconfig_ARGS)
pkgconfig_ARGS=	build
.endif

.if ${pkgconfig_ARGS} == "build"
BUILD_DEPENDS+=	${_PKGCONFIG_DEPENDS}
CONFIGURE_ENV+=	PKG_CONFIG=pkgconf
.elif ${pkgconfig_ARGS} == "run"
RUN_DEPENDS+=	${_PKGCONFIG_DEPENDS}
.elif ${pkgconfig_ARGS} == "both"
CONFIGURE_ENV+=	PKG_CONFIG=pkgconf
BUILD_DEPENDS+=	${_PKGCONFIG_DEPENDS}
RUN_DEPENDS+=	${_PKGCONFIG_DEPENDS}
.else
IGNORE=	USES=pkgconfig - invalid args: [${pkgconfig_ARGS}] specifed
.endif

.endif