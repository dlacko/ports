# New ports collection makefile for:	POE-Component-SMTP
# Date created:	   02 June 2003
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-SMTP
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	mail devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	SMTP Protocol Implementation

BUILD_DEPENDS=	p5-POE>=0:${PORTSDIR}/devel/p5-POE \
		p5-POE-Session-MultiDispatch>=0:${PORTSDIR}/devel/p5-POE-Session-MultiDispatch \
		p5-Mail-Tools>=0:${PORTSDIR}/mail/p5-Mail-Tools
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Component::Server::SMTP.3 POE::Filter::SMTP.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS+=	p5-Test-Simple>=0.98:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
