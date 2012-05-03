/* File Name: xFramework.c
 * Author: Kayne Ruse
 * Date: 3/5/2012
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
 *     This version handles multiple scenes.
*/
#include "xFramework.h"

/* Preprocessor directives */

#define FALSE 0
#define TRUE 1

/* xFramework internals */
int g_bRunning = TRUE;
Uint8 g_uiSceneCount = 0;
Uint8 g_uiSceneThis = 0;
Uint8 g_uiSceneNext = 0;
int g_iReturn = 0;

xBasicCallback g_fpInit = NULL;
xBasicCallback g_fpQuit = NULL;

typedef struct xScene {
	xBasicCallback m_fpHead;
	xBasicCallback m_fpTail;
	xBasicCallback m_fpUpdate;
	xBasicCallback m_fpRender;

	xEventCallback m_fpEvents[SDL_NUMEVENTS];
}xScene;

xScene* g_pSceneArray = NULL;

/* xFramework accessors and mutators */
int xSetInitCallback(xBasicCallback cb) {
	if (g_fpInit != NULL) return 1;

	g_fpInit = cb;

	return 0;
}

int xSetQuitCallback(xBasicCallback cb) {
	if (g_fpQuit != NULL) return 1;

	g_fpQuit = cb;

	return 0;
}

int xSetHeadCallback(Uint8 s, xBasicCallback cb) {
	if (g_pSceneArray == NULL || s >= g_uiSceneCount) return 2;
	if (g_pSceneArray[s].m_fpHead != NULL) return 1;

	g_pSceneArray[s].m_fpHead = cb;

	return 0;
}

int xSetTailCallback(Uint8 s, xBasicCallback cb) {
	if (g_pSceneArray == NULL || s >= g_uiSceneCount) return 2;
	if (g_pSceneArray[s].m_fpTail != NULL) return 1;

	g_pSceneArray[s].m_fpTail = cb;

	return 0;
}

int xSetUpdateCallback(Uint8 s, xBasicCallback cb) {
	if (g_pSceneArray == NULL || s >= g_uiSceneCount) return 2;
	if (g_pSceneArray[s].m_fpUpdate != NULL) return 1;

	g_pSceneArray[s].m_fpUpdate = cb;

	return 0;
}

int xSetRenderCallback(Uint8 s, xBasicCallback cb) {
	if (g_pSceneArray == NULL || s >= g_uiSceneCount) return 2;
	if (g_pSceneArray[s].m_fpRender != NULL) return 1;

	g_pSceneArray[s].m_fpRender = cb;

	return 0;
}

int xSetEventCallback(Uint8 s, xEventCallback cb, Uint8 e) {
	if (e >= SDL_NUMEVENTS) return 3;
	if (g_pSceneArray == NULL || s >= g_uiSceneCount) return 2;
	if (g_pSceneArray[s].m_fpEvents[e] != NULL) return 1;

	g_pSceneArray[s].m_fpEvents[e] = cb;

	return 0;
}

/* Body of the xFramework */
int xAlloc(Uint8 num) {
	Uint8 i, j;

	if (g_pSceneArray != NULL) return 2;

	g_uiSceneCount = num;

	g_pSceneArray = malloc( g_uiSceneCount * sizeof(xScene) );

	if (g_pSceneArray == NULL) return 1;

	/* Zero the array */
	for (i = 0; i < g_uiSceneCount; i++) {
		g_pSceneArray[i].m_fpHead = NULL;
		g_pSceneArray[i].m_fpTail = NULL;

		g_pSceneArray[i].m_fpUpdate = NULL;
		g_pSceneArray[i].m_fpRender = NULL;

		/* Zero the event arrays */
		for (j = 0; j < SDL_NUMEVENTS; j++) {
			g_pSceneArray[i].m_fpEvents[j] = NULL;
		}
	}

	return 0;
}

int xSwitch(Uint8 i) {
	if (g_pSceneArray == NULL) return 2;
	if (i >= g_uiSceneCount) return 1;

	g_uiSceneNext = i;

	return 0;
}

int xQuit(int i) {
	if (g_iReturn != 0 || g_bRunning == FALSE) return -1;

	g_bRunning = FALSE;

	return 0;
}

int xProc() {
	SDL_Event event;

	if (g_pSceneArray == NULL) return 2;

	if (g_fpInit != NULL) g_fpInit();

	while(g_bRunning) {
		g_uiSceneThis = g_uiSceneNext;

		if (g_pSceneArray[g_uiSceneThis].m_fpHead != NULL) g_pSceneArray[g_uiSceneThis].m_fpHead();

		while(SDL_PollEvent(&event)) {
			if (g_pSceneArray[g_uiSceneThis].m_fpEvents[event.type] != NULL)
				g_pSceneArray[g_uiSceneThis].m_fpEvents[event.type](&event);
		}

		if (g_pSceneArray[g_uiSceneThis].m_fpUpdate != NULL) g_pSceneArray[g_uiSceneThis].m_fpUpdate();
		if (g_pSceneArray[g_uiSceneThis].m_fpRender != NULL) g_pSceneArray[g_uiSceneThis].m_fpRender();

		if (g_pSceneArray[g_uiSceneThis].m_fpTail != NULL) g_pSceneArray[g_uiSceneThis].m_fpTail();
	}

	if (g_fpQuit != NULL) g_fpQuit();

	free(g_pSceneArray);

	return g_iReturn;
}
