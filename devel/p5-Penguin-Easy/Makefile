# New ports collection makefile for:	p5-Penguin-Easy
# Date created:				May 28th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Penguin-Easy
PORTVERSION=	1.1
CATEGORIES=	devel security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A quick and easy implementation of the p5-Penguin module

BUILD_DEPENDS=	p5-Penguin>=0:${PORTSDIR}/devel/p5-Penguin

PERL_CONFIGURE=	YES

MAN3=		Penguin::Easy.3

post-install:
		${MKDIR} ${PREFIX}/lib/perl5/site_perl/Penguin/Easy/bin ${PREFIX}/lib/perl5/site_perl/Penguin/Easy/doc
		${INSTALL} -c -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} ${WRKSRC}/bin/ep ${PREFIX}/lib/perl5/site_perl/Penguin/Easy/bin
		${INSTALL_DATA} ${WRKSRC}/Penguin-howto ${PREFIX}/lib/perl5/site_perl/Penguin/Easy/doc

.include <bsd.port.mk>
