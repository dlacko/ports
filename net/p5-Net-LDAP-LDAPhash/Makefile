# New ports collection makefile for:	p5-Net-LDAP-LDAPhash
# Date created:		2008-02-13
# Whom:			Zane C, Bowers <vvelox@vvelox.net>
#
# $FreeBSD$
#

PORTNAME=	Net-LDAP-LDAPhash
PORTVERSION=	1.0.3
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Make a hash out of the return from a search using Net::LDAP::Search

BUILD_DEPENDS=	p5-perl-ldap>=0.39:${PORTSDIR}/net/p5-perl-ldap
RUN_DEPENDS=	p5-perl-ldap>=0.39:${PORTSDIR}/net/p5-perl-ldap

PERL_CONFIGURE=	yes

MAN3=		Net::LDAP::LDAPhash.3

.include <bsd.port.mk>
