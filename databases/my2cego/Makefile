# Created by: Kurt Jaeger <fbsd-ports@opsec.eu>
# $FreeBSD$

PORTNAME=	my2cego
PORTVERSION=	1.1.3
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.lemke-it.com/

MAINTAINER=	fbsd-ports@opsec.eu
COMMENT=	Imports mysqldump files into cego

LIB_DEPENDS=	lfcbase:${PORTSDIR}/devel/lfcbase \
		lfcxml:${PORTSDIR}/devel/lfcxml \
		cego:${PORTSDIR}/databases/cego

LICENSE=	GPLv3
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoconf:env
PLIST_FILES=	bin/my2cego

.include <bsd.port.mk>
