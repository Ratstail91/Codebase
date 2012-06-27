/* File Name: complex_callbacks.c
 * Author: Kayne Ruse
 * Date: 27/6/2012
 * Copyright: (c) Kayne Ruse 2012
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 * claim that you wrote the original software. If you use this software
 * in a product, an acknowledgment in the product documentation would be
 * appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such, and must not be
 * misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source
 * distribution.
 *
 * Description:
 *     This is a simple framework written in C, based on Simple DirectMedia Layer (SDL).
 *     This framework contains no initialisation or rendering code.
 *     This version handles multiple scenes; see "simple callbacks" for a single scene.
 * 
 * Notes:
 *     The "cc" prefix is to differentiate these variables from identical names in
 *     "simple callbacks".
*/
#include "complex_callbacks.h"

/* Preprocessor directives */

#define FALSE 0
#define TRUE 1

/* Complex callbacks internals */
int cc_g_bRunning = TRUE;
Uint8 cc_g_uiSceneCount = 0;
Uint8 cc_g_uiSceneThis = 0;
Uint8 cc_g_uiSceneNext = 0;
int cc_g_iReturn = 0;

ccBasic cc_g_fpInit = NULL;
ccBasic cc_g_fpQuit = NULL;

typedef struct ccScene {
	ccBasic m_fpHead;
	ccBasic m_fpTail;
	ccBasic m_fpUpdate;
	ccBasic m_fpRender;

	ccEvent m_fpEvents[SDL_NUMEVENTS];
}ccScene;

ccScene* cc_g_pSceneArray = NULL;

/* Complex callbacks accessors and mutators */
int ccSetInit(ccBasic cb) {
	if (cc_g_fpInit != NULL) return 1;

	cc_g_fpInit = cb;

	return 0;
}

int ccSetQuit(ccBasic cb) {
	if (cc_g_fpQuit != NULL) return 1;

	cc_g_fpQuit = cb;

	return 0;
}

int ccSetHead(Uint8 s, ccBasic cb) {
	if (cc_g_pSceneArray == NULL || s >= cc_g_uiSceneCount) return 2;
	if (cc_g_pSceneArray[s].m_fpHead != NULL) return 1;

	cc_g_pSceneArray[s].m_fpHead = cb;

	return 0;
}

int ccSetTail(Uint8 s, ccBasic cb) {
	if (cc_g_pSceneArray == NULL || s >= cc_g_uiSceneCount) return 2;
	if (cc_g_pSceneArray[s].m_fpTail != NULL) return 1;

	cc_g_pSceneArray[s].m_fpTail = cb;

	return 0;
}

int ccSetUpdate(Uint8 s, ccBasic cb) {
	if (cc_g_pSceneArray == NULL || s >= cc_g_uiSceneCount) return 2;
	if (cc_g_pSceneArray[s].m_fpUpdate != NULL) return 1;

	cc_g_pSceneArray[s].m_fpUpdate = cb;

	return 0;
}

int ccSetRender(Uint8 s, ccBasic cb) {
	if (cc_g_pSceneArray == NULL || s >= cc_g_uiSceneCount) return 2;
	if (cc_g_pSceneArray[s].m_fpRender != NULL) return 1;

	cc_g_pSceneArray[s].m_fpRender = cb;

	return 0;
}

int ccSetEvent(Uint8 s, ccEvent cb, Uint8 e) {
	if (e >= SDL_NUMEVENTS) return 3;
	if (cc_g_pSceneArray == NULL || s >= cc_g_uiSceneCount) return 2;
	if (cc_g_pSceneArray[s].m_fpEvents[e] != NULL) return 1;

	cc_g_pSceneArray[s].m_fpEvents[e] = cb;

	return 0;
}

/* Body of the complex callbacks */
int ccAlloc(Uint8 num) {
	Uint8 i, j;

	if (cc_g_pSceneArray != NULL) return 2;

	cc_g_uiSceneCount = num;

	cc_g_pSceneArray = malloc( cc_g_uiSceneCount * sizeof(ccScene) );

	if (cc_g_pSceneArray == NULL) return 1;

	/* Zero the array */
	for (i = 0; i < cc_g_uiSceneCount; i++) {
		cc_g_pSceneArray[i].m_fpHead = NULL;
		cc_g_pSceneArray[i].m_fpTail = NULL;

		cc_g_pSceneArray[i].m_fpUpdate = NULL;
		cc_g_pSceneArray[i].m_fpRender = NULL;

		/* Zero the event arrays */
		for (j = 0; j < SDL_NUMEVENTS; j++) {
			cc_g_pSceneArray[i].m_fpEvents[j] = NULL;
		}
	}

	return 0;
}

int ccSwitch(Uint8 i) {
	if (cc_g_pSceneArray == NULL) return 2;
	if (i >= cc_g_uiSceneCount) return 1;

	cc_g_uiSceneNext = i;

	return 0;
}

int ccQuit(int i) {
	if (cc_g_iReturn != 0 || cc_g_bRunning == FALSE) return -1;

	cc_g_bRunning = FALSE;

	return 0;
}

int ccProc() {
	SDL_Event event;

	if (cc_g_pSceneArray == NULL) return 2;

	if (cc_g_fpInit != NULL) cc_g_fpInit();

	while(cc_g_bRunning) {
		cc_g_uiSceneThis = cc_g_uiSceneNext;

		if (cc_g_pSceneArray[cc_g_uiSceneThis].m_fpHead != NULL) cc_g_pSceneArray[cc_g_uiSceneThis].m_fpHead();

		while(SDL_PollEvent(&event)) {
			if (cc_g_pSceneArray[cc_g_uiSceneThis].m_fpEvents[event.type] != NULL)
				cc_g_pSceneArray[cc_g_uiSceneThis].m_fpEvents[event.type](&event);
		}

		if (cc_g_pSceneArray[cc_g_uiSceneThis].m_fpUpdate != NULL) cc_g_pSceneArray[cc_g_uiSceneThis].m_fpUpdate();
		if (cc_g_pSceneArray[cc_g_uiSceneThis].m_fpRender != NULL) cc_g_pSceneArray[cc_g_uiSceneThis].m_fpRender();

		if (cc_g_pSceneArray[cc_g_uiSceneThis].m_fpTail != NULL) cc_g_pSceneArray[cc_g_uiSceneThis].m_fpTail();
	}

	if (cc_g_fpQuit != NULL) cc_g_fpQuit();

	free(cc_g_pSceneArray);

	return cc_g_iReturn;
}
