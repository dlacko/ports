# Created by: George Hartzell <hartzell@alerce.com>
# $FreeBSD$

PORTNAME=	CGI-Application-Plugin-ViewCode
PORTVERSION=	1.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	View the source of the running application

RUN_DEPENDS=	p5-CGI-Application>=0:${PORTSDIR}/www/p5-CGI-Application \
		p5-CGI-Application-Plugin-Forward>=0:${PORTSDIR}/www/p5-CGI-Application-Plugin-Forward \
		p5-Syntax-Highlight-Perl-Improved>=0:${PORTSDIR}/textproc/p5-Syntax-Highlight-Perl-Improved \
		p5-Pod-Xhtml>=0:${PORTSDIR}/textproc/p5-Pod-Xhtml \
		p5-Test-LongString>=0:${PORTSDIR}/devel/p5-Test-LongString
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	CGI::Application::Plugin::ViewCode.3

.include <bsd.port.mk>
