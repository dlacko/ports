# $FreeBSD$

PORTNAME=	Coro
PORTVERSION=	6.31
PORTEPOCH=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Coroutine process abstraction for perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-AnyEvent>=7:${PORTSDIR}/devel/p5-AnyEvent \
		p5-AnyEvent-AIO>=1.0:${PORTSDIR}/devel/p5-AnyEvent-AIO \
		p5-EV>=4:${PORTSDIR}/devel/p5-EV \
		p5-Event>=1.08:${PORTSDIR}/devel/p5-Event \
		p5-Guard>=0.5:${PORTSDIR}/devel/p5-Guard \
		p5-IO-AIO>=3.1:${PORTSDIR}/devel/p5-IO-AIO \
		p5-common-sense>=0:${PORTSDIR}/devel/p5-common-sense
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Coro.3 \
		Coro::AIO.3 \
		Coro::AnyEvent.3 \
		Coro::BDB.3 \
		Coro::Channel.3 \
		Coro::Debug.3 \
		Coro::EV.3 \
		Coro::Event.3 \
		Coro::Handle.3 \
		Coro::Intro.3 \
		Coro::LWP.3 \
		Coro::MakeMaker.3 \
		Coro::RWLock.3 \
		Coro::Select.3 \
		Coro::Semaphore.3 \
		Coro::SemaphoreSet.3 \
		Coro::Signal.3 \
		Coro::Socket.3 \
		Coro::Specific.3 \
		Coro::State.3 \
		Coro::Storable.3 \
		Coro::Timer.3 \
		Coro::Util.3

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/cede-vs-schedule ${DOCSDIR}/
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/eg/* ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
