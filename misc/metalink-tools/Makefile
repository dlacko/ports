# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	metalink
PORTVERSION=	0.3.6
PORTREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	SF/metalinks/Metalink%20commandline/${PORTVERSION}
PKGNAMESUFFIX?=	-tools

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Metalink generation tool

LIB_DEPENDS=	gcrypt:${PORTSDIR}/security/libgcrypt \
		glibmm-2.4.1:${PORTSDIR}/devel/glibmm \
		gpg-error.0:${PORTSDIR}/security/libgpg-error \
		sigc-2.0.0:${PORTSDIR}/devel/libsigc++20

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GNOME=	glib20
GNU_CONFIGURE=	yes
USES=		pkgconfig
CONFIGURE_ENV+=	AWK="${AWK}"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_JOBS_SAFE=	yes

# Documents to install
DOC_FILES=	\
		README

.ifndef(NOPORTDOCS)
PORTDOCS=	*
.endif

PLIST_FILES=	bin/${PORTNAME}

do-install:
# docs
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
