# New ports collection makefile for:	sol
# Date created:				12 April 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	sol
PORTVERSION=	1.0.7
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://shh.thathost.com/pub-unix/files/

MAINTAINER=	edwin@mavetju.org
COMMENT=	Solitaire card game for X Window System

LIB_DEPENDS=	shhopt.1:${PORTSDIR}/devel/libshhopt \
		shhmsg.1:${PORTSDIR}/devel/libshhmsg \
		xalloc.1:${PORTSDIR}/devel/libxalloc \
		shhcards.1:${PORTSDIR}/games/libshhcards

CONFLICTS=	gnome-games-*

USE_GMAKE=	yes
USE_XORG=	xpm x11 xaw

MAN6=		sol.6

.include <bsd.port.pre.mk>

pre-build:
	cd ${WRKSRC} && ${GMAKE} readme.var

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sol ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sol.6 ${PREFIX}/man/man6
	@${MKDIR} ${PREFIX}/share/sol
	${INSTALL_DATA} ${WRKSRC}/sol.score ${PREFIX}/share/sol
	@${CHOWN} root:games ${PREFIX}/bin/sol
	@${CHOWN} root:games ${PREFIX}/share/sol/sol.score
	@${CHMOD} 2755 ${PREFIX}/bin/sol
	@${CHMOD} 770 ${PREFIX}/share/sol
	@${CHMOD} 660 ${PREFIX}/share/sol/sol.score
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/sol
	${INSTALL_DATA} ${WRKSRC}/CREDITS ${PREFIX}/share/doc/sol
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/sol
.endif

.include <bsd.port.post.mk>
