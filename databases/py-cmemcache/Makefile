# New ports collection makefile for:    py-cmemcache
# Date created:                         17 Jan 2009
# Whom:                                 Qing Feng <qingfeng@douban.com>
#
# $FreeBSD$
#

PORTNAME=	cmemcache
PORTVERSION=	0.95
CATEGORIES=	databases python
MASTER_SITES=	http://gijsbert.org/downloads/cmemcache/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	qingfeng@douban.com
COMMENT=	Python API for memcached, a distributed memory cache daemon

LIB_DEPENDS=	memcache:${PORTSDIR}/databases/libmemcache

USE_BZIP2=	yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
