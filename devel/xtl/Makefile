# ex:ts=8
# New ports collection makefile for:	xtl
# Date created:			Sep 1, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xtl
PORTVERSION=	1.4.2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library for R/W structured data to/from an external representation

NO_BUILD=	yes

do-install:
	${CP} -R ${WRKSRC}/include/* ${PREFIX}/include

.include <bsd.port.mk>
