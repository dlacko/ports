# Created by: Tzanetos Balitsaris <tzabal@it.teithe.gr>
# $FreeBSD$

PORTNAME=	jitsi
PORTVERSION=	1.1
CATEGORIES=	net-im java
MASTER_SITES=	https://download.jitsi.org/jitsi/nightly/src/ \
		http://aetos.it.teithe.gr/~tzabal/files/
DISTNAME=	jitsi-src-1.1.4456.10418

MAINTAINER=	tzabal@it.teithe.gr
COMMENT=	Open source IM and VoIP application

USE_ZIP=	yes
USE_JAVA=	yes
USE_ANT=	yes
MAKE_ARGS=	rebuild
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

DESKTOP_ENTRIES="Jitsi" \
		"VoIP and Instant Messenger" \
		${PREFIX}/share/pixmaps/jitsi.png \
		jitsi \
		"Network;InstantMessaging;VideoConference;Java;" \
		true

.include <bsd.port.pre.mk>

do-install:
	@${ECHO_CMD} ">> Creating Jitsi directories..."
	@${MKDIR} ${PREFIX}/lib/jitsi/sc-bundles
	@${MKDIR} ${PREFIX}/lib/jitsi/lib/bundle
	@${MKDIR} ${PREFIX}/lib/jitsi/lib/native

# Bundles (Jitsi modules)
	@${ECHO_CMD} ">> Installing bundles (Jitsi modules)..."
	@cd ${WRKSRC}/sc-bundles && ${COPYTREE_SHARE} \* \
		${PREFIX}/lib/jitsi/sc-bundles
	@${RM} ${PREFIX}/lib/jitsi/sc-bundles/*slick*.jar
	@${RM} -r ${PREFIX}/lib/jitsi/sc-bundles/os-specific

# Library Jars
	@${ECHO_CMD} ">> Installing library jars..."
	@cd ${WRKSRC}/lib/bundle && ${COPYTREE_SHARE} \* \
		${PREFIX}/lib/jitsi/lib/bundle "! -name junit.jar"
	@${INSTALL_DATA} ${WRKSRC}/lib/os-specific/freebsd/jdic_stub.jar \
		${PREFIX}/lib/jitsi/lib
	@cd ${WRKSRC}/lib && ${COPYTREE_SHARE} "felix.jar jdic-all.jar \
		felix.client.run.properties logging.properties" \
			${PREFIX}/lib/jitsi/lib

# Native Libraries
	@${ECHO_CMD} ">> Installing native libraries..."
.if ${ARCH} != amd64
	@cd ${WRKSRC}/lib/native/freebsd && ${COPYTREE_SHARE} \* \
		${PREFIX}/lib/jitsi/lib/native
.else
	@cd ${WRKSRC}/lib/native/freebsd-64 && ${COPYTREE_SHARE} \* \
		${PREFIX}/lib/jitsi/lib/native
.endif

# Wrapper script to run Jitsi
	@${ECHO_CMD} ">> Installing wrapper script..."
	@${INSTALL_SCRIPT} ${FILESDIR}/jitsi.sh ${PREFIX}/bin/jitsi

# Desktop related
	@${ECHO_CMD} ">> Installing Jitsi's logo..."
	@${INSTALL_DATA} ${WRKSRC}/resources/images/logo/sc_logo_128x128.png \
		${PREFIX}/share/pixmaps/jitsi.png

.include <bsd.port.post.mk>
