# $FreeBSD$

PORTNAME=	nanumfonts
PORTVERSION=	3.1
CATEGORIES=	korean
MASTER_SITES=	http://cdn.naver.com/naver/NanumFont/fontfiles/ \
		LOCAL
MASTER_SITE_SUBDIR=	jkim
PKGNAMESUFFIX=	-${FONTTYPE}
DISTFILES=	NanumFont_${FONTTYPE:U}_ALL${EXTRACT_SUFX} \
		NanumFontSetup_${FONTTYPE:U}_GOTHICECO${EXTRACT_SUFX} \
		NanumFontSetup_${FONTTYPE:U}_GOTHICLIGHT${EXTRACT_SUFX} \
		NanumFontSetup_${FONTTYPE:U}_MYUNGJOECO${EXTRACT_SUFX}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Nanum family Hangul fonts (${FONTFORMAT})

LICENSE=	OFL
LICENSE_NAME=	Open Font License version 1.1
LICENSE_FILE=	${FILESDIR}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS+=	${LOCALBASE}/bin/mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		${LOCALBASE}/bin/mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

DISTINFO_FILE=	${PKGDIR}/distinfo.${FONTTYPE}

NO_WRKSUBDIR=	yes
USE_ZIP=	yes

FONTTYPE?=	otf
FONTFORMAT?=	OpenType

FONTSDIR=	lib/X11/fonts/nanum-${FONTTYPE}
FONTLIST=	NanumBrush \
		NanumGothic \
		NanumGothicBold \
		NanumGothicEco \
		NanumGothicEcoBold \
		NanumGothicEcoExtraBold \
		NanumGothicExtraBold \
		NanumGothicLight \
		NanumMyeongjo \
		NanumMyeongjoBold \
		NanumMyeongjoEco \
		NanumMyeongjoEcoBold \
		NanumMyeongjoEcoExtraBold \
		NanumMyeongjoExtraBold \
		NanumPen

PLIST_DIRS=	${FONTSDIR}
.for f in ${FONTLIST}
PLIST_FILES+=	${FONTSDIR}/${f}.${FONTTYPE}
.endfor
PLIST_FILES+=	${FONTSDIR}/fonts.dir \
		${FONTSDIR}/fonts.scale

do-build:
	${LOCALBASE}/bin/mkfontscale ${WRKSRC}
	${LOCALBASE}/bin/mkfontdir ${WRKSRC}

do-install:
	${MKDIR} ${PREFIX}/${FONTSDIR}
.for f in ${FONTLIST}
	${INSTALL_DATA} ${WRKSRC}/${f}.${FONTTYPE} ${PREFIX}/${FONTSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/fonts.dir ${PREFIX}/${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts.scale ${PREFIX}/${FONTSDIR}

post-install:
	@${ECHO_CMD} "@exec fc-cache -s %D/${FONTSDIR} 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec fc-cache -s %D/${FONTSDIR} 2>/dev/null || true" >> ${TMPPLIST}
	@-${LOCALBASE}/bin/fc-cache -s ${PREFIX}/${FONTSDIR} 2>/dev/null

.include <bsd.port.mk>
