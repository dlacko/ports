# Created by: Pedro F. Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	admesh
PORTVERSION=	0.95
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://launchpadlibrarian.net/67068999/ \
		http://www.sourcefiles.org/Scientific/Numerical_Analysis/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program for processing STL triangulated solid meshes

LICENSE=	GPLv2 # (or later)

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

PORTDOCS=	admesh.doc
PLIST_FILES=	bin/admesh

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/admesh ${PREFIX}/bin/
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ADMESH.DOC ${DOCSDIR}/admesh.doc
.endif

.include <bsd.port.mk>
