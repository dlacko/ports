# New ports collection makefile for:	kcdlabel
# Date created:			Mon Dec 29 03:01:39 CET 2003
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=		kcdlabel
PORTVERSION=		2.12
PORTREVISION=	10
CATEGORIES=		print kde
MASTER_SITES=		SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}-KDE3
DISTNAME=		${PORTNAME}-${PORTVERSION}-KDE3

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Create covers, labels, and booklets for your CD cases

DEPRECATED=		Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_KDELIBS_VER=	3
USE_GMAKE=		yes
USE_AUTOTOOLS=		libtool

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g; s|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
