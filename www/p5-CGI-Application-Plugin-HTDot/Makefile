# New ports collection makefile for:	CGI::Application::Plugin::HTDot
# Date created:				05 March 2006
# Whom:					Espen Tagestad <espen@tagestad.no>
#
# $FreeBSD$
#

PORTNAME=	CGI-Application-Plugin-HTDot
PORTVERSION=	0.07
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lippe@FreeBSD.org
COMMENT=	Enable "magic dot" notation in CGI::Application-derived applications

BUILD_DEPENDS=	p5-CGI-Application>=4.0:${PORTSDIR}/www/p5-CGI-Application \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-HTML-Template-Pluggable>=0:${PORTSDIR}/www/p5-HTML-Template-Pluggable \
		p5-CGI-Application>=0:${PORTSDIR}/www/p5-CGI-Application \
		p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		CGI::Application::Plugin::HTDot.3

.include <bsd.port.mk>
