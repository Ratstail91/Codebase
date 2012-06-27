/* File Name: simple_callbacks.c
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
 *     This version handles only one scene; see "complex callbacks" for multiple scenes.
 * 
 * Notes:
 *     The "sc" prefix is to differentiate these variables from identical names in
 *     "complex callbacks".
*/
#include "simple_callbacks.h"

/* Preprocessor directives */
#define LIST_02(X) X,X
#define LIST_04(X) LIST_02(X),LIST_02(X)
#define LIST_08(X) LIST_04(X),LIST_04(X)
#define LIST_16(X) LIST_08(X),LIST_08(X)
#define LIST_32(X) LIST_16(X),LIST_16(X)

#define FALSE 0
#define TRUE 1

/* Simple callback internals */
int sc_g_bRunning = TRUE;

scBasic sc_g_fpInit = NULL;
scBasic sc_g_fpQuit = NULL;

scBasic sc_g_fpHead = NULL;
scBasic sc_g_fpTail = NULL;
scBasic sc_g_fpUpdate = NULL;
scBasic sc_g_fpRender = NULL;

scEvent sc_g_fpEvents[SDL_NUMEVENTS] = {LIST_32(NULL)};

/* Simple callback functions */
int  scSetInit(scBasic cb) {
	if (sc_g_fpInit != NULL) return 1;
	sc_g_fpInit = cb;
	return 0;
}

int scSetQuit(scBasic cb) {
	if (sc_g_fpQuit != NULL) return 1;
	sc_g_fpQuit = cb;
	return 0;
}

int scSetHead(scBasic cb) {
	if (sc_g_fpHead != NULL) return 1;
	sc_g_fpHead = cb;
	return 0;
}

int scSetTail(scBasic cb) {
	if (sc_g_fpTail != NULL) return 1;
	sc_g_fpTail = cb;
	return 0;
}

int scSetUpdate(scBasic cb) {
	if (sc_g_fpUpdate != NULL) return 1;
	sc_g_fpUpdate = cb;
	return 0;
}

int scSetRender(scBasic cb) {
	if (sc_g_fpRender != NULL) return 1;
	sc_g_fpRender = cb;
	return 0;
}

int scSetEvent(scEvent cb, Uint8 e) {
	if (e >= SDL_NUMEVENTS) return 2;
	if (sc_g_fpEvents[e] != NULL) return 1;
	sc_g_fpEvents[e] = cb;
	return 0;
}

void scQuit() {
	sc_g_bRunning = FALSE;
}

void scProc() {
	SDL_Event event;

	if (sc_g_fpInit != NULL) sc_g_fpInit();

	while(sc_g_bRunning) {
		if (sc_g_fpHead != NULL) sc_g_fpHead();

		while(SDL_PollEvent(&event)) {
			if (sc_g_fpEvents[event.type] != NULL)
				sc_g_fpEvents[event.type](&event);
		}

		if (sc_g_fpUpdate != NULL) sc_g_fpUpdate();
		if (sc_g_fpRender != NULL) sc_g_fpRender();

		if (sc_g_fpTail != NULL) sc_g_fpTail();
	}

	if (sc_g_fpQuit != NULL) sc_g_fpQuit();
}
