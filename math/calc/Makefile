# Created by: jmz
# $FreeBSD$

PORTNAME=	calc
PORTVERSION=	2.12.4.8
CATEGORIES=	math
MASTER_SITES=	SF

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Arbitrary precision calculator

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

MAKE_JOBS_UNSAFE=	yes

MAN1=		calc.1

CALCPAGER?=	more
MAKE_ENV+=	CALCPAGER="${CALCPAGER}" CAT="${CAT}" CHMOD="${CHMOD}" CP="${CP}" \
		GMAKE="${GMAKE}" LN="${LN}" MKDIR="${MKDIR}" MV="${MV}" RM="${RM}" \
		SED="${SED}" TOUCH="${TOUCH}" TRUE="${TRUE}"

PLIST_SUB+=	VERSION=${PORTVERSION}	VER1=${PORTVERSION:R} \
		VER2=${PORTVERSION:R:R}	VER3=${PORTVERSION:R:R:R}

regression-test: build
	( cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} check )

.include <bsd.port.mk>
