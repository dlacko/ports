# Created by: gahr
# $FreeBSD$

PORTNAME=	zorba
PORTVERSION=	2.7.0
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	https://launchpadlibrarian.net/119058962/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A general purpose C++ XQuery processor

LICENSE=	AL2

LIB_DEPENDS=	execinfo:${PORTSDIR}/devel/libexecinfo \
   		xerces-c.3:${PORTSDIR}/textproc/xerces-c3 \
		icudata:${PORTSDIR}/devel/icu \
		curl:${PORTSDIR}/ftp/curl \
		tidy:${PORTSDIR}/www/tidy-lib \
		uuid:${PORTSDIR}/misc/e2fsprogs-libuuid
RUN_DEPENDS=	fop:${PORTSDIR}/textproc/fop

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	PHP PYTHON RUBY JAVA DOCS

# Both install include/xqc.h
CONFLICTS=	xqilla-[0-9]*

USE_GNOME=	libxml2 libxslt
USE_LDCONFIG=	yes
USES=		cmake:outsource iconv
CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CMAKE_ARGS=	-DCMAKE_REQUIRED_FLAGS:STRING="-I${LOCALBASE}/include -L${LOCALBASE}/lib"

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}

PLIST_SUB+=	FULLVERSION=${PORTVERSION} \
		MIDVERSION=${PORTVERSION:R} \
		MINVERSION=${PORTVERSION:R:R}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPHP}
USE_PHP=	tokenizer
USE_PHP_BUILD=	yes
WITH_SWIG=	yes
CMAKE_ARGS+=	-DWITH_PHP5:BOOL=true \
   		-DPHP5_INSTALL_PATH:FILEPATH="lib/php/${PHP_EXT_DIR}"
PLIST_SUB+=	WITH_PHP="" \
		PHP_EXTLIBDIR="lib/php/${PHP_EXT_DIR}"
.else
CMAKE_ARGS+=	-DWITH_PHP5:BOOL=false
PLIST_SUB+=	WITH_PHP="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
WITH_SWIG=	yes
CMAKE_ARGS+=	-DWITH_PYTHON:BOOL=true \
		-DPYTHON_SWIG_INSTALL_DIR:FILEPATH=${PYTHONPREFIX_SITELIBDIR:S/${PREFIX}\///}
PLIST_SUB+=	WITH_PYTHON="" \
		PYTHON_SITELIBDIR=${PYTHONPREFIX_SITELIBDIR:S/${PREFIX}\///}

.else
CMAKE_ARGS+=	-DWITH_PYTHON:BOOL=false
PLIST_SUB+=	WITH_PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MRUBY}
USE_RUBY=	yes
WITH_SWIG=	yes
CMAKE_ARGS+=	-DWITH_RUBY:BOOL=true
PLIST_SUB+=	WITH_RUBY=""
.else
CMAKE_ARGS+=	-DWITH_RUBY:BOOL=false
PLIST_SUB+=	WITH_RUBY="@comment "
.endif

.if ${PORT_OPTIONS:MJAVA}
USE_JAVA=	yes
CONFIGURE_ENV+=	JAVA_HOME=${JAVA_HOME}
CATEGORIES+=	java
WITH_SWIG=	yes
CMAKE_ARGS+=	-DWITH_JAVA:BOOL=true \
   		-DJAVA_LIBDIR:PATH=${JAVALIBDIR}
PLIST_SUB+=	WITH_JAVA=""
.else
CMAKE_ARGS+=	-DWITH_JAVA:BOOL=false
PLIST_SUB+=	WITH_JAVA="@comment "
.endif

.if defined(WITH_SWIG)
BUILD_DEPENDS+=	swig2.0:${PORTSDIR}/devel/swig20
.endif

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
.endif

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	   ${WRKSRC}/CMakeLists.txt ${WRKSRC}/cmake_modules/FindPHP5.cmake
.if !${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e '531s|^|#|' ${WRKSRC}/CMakeLists.txt
.endif

#pre-build:
#	${FIND} ${WRKSRC} -name "*.orig" -delete

post-install:
	${LN} -sf libzorba_simplestore.so.${PORTVERSION} ${PREFIX}/lib/libzorba_simplestore.so.${PORTVERSION:R:R}

test:	build
	cd ${BUILD_WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
