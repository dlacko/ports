# New ports collection makefile for:	scimark2c
# Date created:		Sat Apr 05 2003
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	scimark2c
DISTVERSION=	2_1
CATEGORIES=	benchmarks
MASTER_SITES=	http://math.nist.gov/scimark2/
DISTNAME=	${PORTNAME:S/2/${DISTVERSION}/}

MAINTAINER=	thierry@pompo.net
COMMENT=	An ANSI C version of the SciMark2 benchmark

PLIST_FILES=	bin/scimark2
WRKSRC=		${WRKDIR}
USE_ZIP=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scimark2 ${PREFIX}/bin

post-install:
	@${ECHO} "*****************************************************************************"
	@${ECHO} ""
	@${ECHO} " Just run scimark2 or scimark2 -large"
	@${ECHO} ""
	@${ECHO} " The first SciMark number reported is the composite score, followed by the an"
	@${ECHO} " approximate Mflop rate for each kernel."
	@${ECHO} ""
	@${ECHO} " You may try to hack CC or CFLAGS in /etc/make.conf..."
	@${ECHO} ""
	@${ECHO} "*****************************************************************************"

.include <bsd.port.mk>
