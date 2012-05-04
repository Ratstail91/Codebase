/* File Name: complex_callbacks.c
 * Author: Kayne Ruse
 * Date: 4/5/2012
 * Copyright: (c) Kayne Ruse 2012
 * 
 * This file is part of Codebase Library.
 * 
 * Codebase Library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Codebase Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with Codebase Library.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Description: 
 *     This is a simple framework written in C, based on Simple DirectMedia Layer (SDL).
 *     This framework contains no initialisation or rendering code.
 *     This version handles multiple scenes; see "simple callbacks" for a single scene.
 * 
 * Notes:
 *     The "cc_" prefix for the globals is to differentiate these variables from identical
 *     variables in "simple callbacks".
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

ccBasicCallback cc_g_fpInit = NULL;
ccBasicCallback cc_g_fpQuit = NULL;

typedef struct ccScene {
	ccBasicCallback m_fpHead;
	ccBasicCallback m_fpTail;
	ccBasicCallback m_fpUpdate;
	ccBasicCallback m_fpRender;

	ccEventCallback m_fpEvents[SDL_NUMEVENTS];
}ccScene;

ccScene* cc_g_pSceneArray = NULL;

/* Complex callbacks accessors and mutators */
int ccSetInitCallback(ccBasicCallback cb) {
	if (cc_g_fpInit != NULL) return 1;

	cc_g_fpInit = cb;

	return 0;
}

int ccSetQuitCallback(ccBasicCallback cb) {
	if (cc_g_fpQuit != NULL) return 1;

	cc_g_fpQuit = cb;

	return 0;
}

int ccSetHeadCallback(Uint8 s, ccBasicCallback cb) {
	if (cc_g_pSceneArray == NULL || s >= cc_g_uiSceneCount) return 2;
	if (cc_g_pSceneArray[s].m_fpHead != NULL) return 1;

	cc_g_pSceneArray[s].m_fpHead = cb;

	return 0;
}

int ccSetTailCallback(Uint8 s, ccBasicCallback cb) {
	if (cc_g_pSceneArray == NULL || s >= cc_g_uiSceneCount) return 2;
	if (cc_g_pSceneArray[s].m_fpTail != NULL) return 1;

	cc_g_pSceneArray[s].m_fpTail = cb;

	return 0;
}

int ccSetUpdateCallback(Uint8 s, ccBasicCallback cb) {
	if (cc_g_pSceneArray == NULL || s >= cc_g_uiSceneCount) return 2;
	if (cc_g_pSceneArray[s].m_fpUpdate != NULL) return 1;

	cc_g_pSceneArray[s].m_fpUpdate = cb;

	return 0;
}

int ccSetRenderCallback(Uint8 s, ccBasicCallback cb) {
	if (cc_g_pSceneArray == NULL || s >= cc_g_uiSceneCount) return 2;
	if (cc_g_pSceneArray[s].m_fpRender != NULL) return 1;

	cc_g_pSceneArray[s].m_fpRender = cb;

	return 0;
}

int ccSetEventCallback(Uint8 s, ccEventCallback cb, Uint8 e) {
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
