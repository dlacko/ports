# New ports collection makefile for:	p5-IPC-Mmap-Share
# Date created:		2006-07-17
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	IPC-Mmap-Share
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Safely share structures among processes using anonymous mmap

RUN_DEPENDS=	p5-IPC-Mmap>=0:${PORTSDIR}/devel/p5-IPC-Mmap
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		IPC::Mmap::Share.3

.include <bsd.port.mk>
