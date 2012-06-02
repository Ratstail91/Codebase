/* File Name: complex_callbacks.h
 * Author: Kayne Ruse
 * Date: 2/6/2012
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
 *     The "cc" prefix is to differentiate these variables from identical names in
 *     "simple callbacks".
*/
#ifndef KR_COMPLEXCALLBACKS_H_
#define KR_COMPLEXCALLBACKS_H_ 2012060201

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
#include "SDL.h"

/* Callback types */
typedef void (*ccBasic)(void);
typedef void (*ccEvent)(SDL_Event const* const);

/* Complex callbacks accessors and mutators */
int ccSetInit	(ccBasic);
int ccSetQuit	(ccBasic);

int ccSetHead	(Uint8, ccBasic);
int ccSetTail	(Uint8, ccBasic);
int ccSetUpdate	(Uint8, ccBasic);
int ccSetRender	(Uint8, ccBasic);

int ccSetEvent	(Uint8, ccEvent, Uint8);

/* Body of the complex callbacks */
int ccAlloc		(Uint8);
int ccSwitch	(Uint8);
int ccQuit		(int);
int ccProc		();

#ifdef __cplusplus
} //extern "C"
#endif

#endif
