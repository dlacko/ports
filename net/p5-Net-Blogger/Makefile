# Created by: ijliao
# $FreeBSD$

PORTNAME=	Net-Blogger
PORTVERSION=	1.02
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	OOP-ish interface for accessing a weblog via the XML-RPC API

BUILD_DEPENDS=	p5-Error>=0:${PORTSDIR}/lang/p5-Error \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-SOAP-Lite>0.55:${PORTSDIR}/net/p5-SOAP-Lite
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey

PERL_MODBUILD=	yes

MAN3=	Net::Blogger.3 \
	Net::Blogger::API::Core.3 \
	Net::Blogger::API::Extended.3 \
	Net::Blogger::Engine::Base.3 \
	Net::Blogger::Engine::Blogger.3 \
	Net::Blogger::Engine::Manila.3 \
	Net::Blogger::Engine::Movabletype.3 \
	Net::Blogger::Engine::Movabletype::mt.3 \
	Net::Blogger::Engine::Radio.3 \
	Net::Blogger::Engine::Slash.3 \
	Net::Blogger::Engine::Slash::slashcode.3 \
	Net::Blogger::Engine::Userland.3 \
	Net::Blogger::Engine::Userland::metaWeblog.3

.include <bsd.port.mk>
