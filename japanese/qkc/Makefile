# Created by: Masafumi NAKANE <max@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qkc
PORTVERSION=	1.0
CATEGORIES=	japanese
MASTER_SITES=	http://hp.vector.co.jp/authors/VA000501/
DISTNAME=	${PORTNAME}c100

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Quick Kanji Code Converter (C version)

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
ALL_TARGET=
PLIST_FILES=	bin/qkc

MAN1=		qkc.1
MANLANG=	ja

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qkc ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/qkc.1 ${PREFIX}/man/ja/man1

.include <bsd.port.mk>
