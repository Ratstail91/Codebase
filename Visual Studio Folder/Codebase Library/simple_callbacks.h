/* File Name: simple_callbacks.h
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
#ifndef KR_SIMPLECALLBACKS_H_
#define KR_SIMPLECALLBACKS_H_ 2012062702

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
#include "SDL.h"

/* Callback types */
typedef void (*scBasic)(void);
typedef void (*scEvent)(SDL_Event const* const);

/* Simple callback functions */
int scSetInit	(scBasic);
int scSetQuit	(scBasic);

int scSetHead	(scBasic);
int scSetTail	(scBasic);
int scSetUpdate	(scBasic);
int scSetRender	(scBasic);

int scSetEvent	(scEvent, Uint8);

void scQuit();
void scProc();

#ifdef __cplusplus
} //extern "C"
#endif

#endif
