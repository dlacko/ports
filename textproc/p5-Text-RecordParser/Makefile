# $FreeBSD$

PORTNAME=	Text-RecordParser
PORTVERSION=	1.6.1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Read record-oriented files

BUILD_DEPENDS=	p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy \
		p5-Text-TabularDisplay>=0:${PORTSDIR}/textproc/p5-Text-TabularDisplay \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Readonly>=0:${PORTSDIR}/devel/p5-Readonly \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-version>=0:${PORTSDIR}/devel/p5-version
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

PERL_MODBUILD=	yes

MAN1=		tablify.1 tabmerge.1 tab2graph.1
MAN3=		Text::RecordParser.3 \
		Text::RecordParser::Tab.3 \
		Text::RecordParser::Object.3

.include <bsd.port.mk>
