# Created by: Kurt Jaeger <fbsd-ports@opsec.eu>
# $FreeBSD$

PORTNAME=	DBD-cego
PORTVERSION=	1.2.0
CATEGORIES=	databases perl5
MASTER_SITES=	http://www.lemke-it.com/
PKGNAMEPREFIX=	p5-

MAINTAINER=	fbsd-ports@opsec.eu
COMMENT=	Cego DBI driver for Perl 5

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-DBI>=1.61:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	p5-DBI>=1.61:${PORTSDIR}/databases/p5-DBI
LIB_DEPENDS=	cego.1:${PORTSDIR}/databases/cego
MAKE_JOBS_UNSAFE=	yes

PERL_CONFIGURE=	yes
CC:=		${CXX}

MAN3=		DBD::Cego.3

post-configure:
	@${REINPLACE_CMD} -e 's|fno-strict-aliasing|fno-strict-aliasing -fpermissive|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
