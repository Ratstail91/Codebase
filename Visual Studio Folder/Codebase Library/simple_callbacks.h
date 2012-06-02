/* File Name: simple_callbacks.h
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
 *     This version handles only one scene; see "complex callbacks" for multiple scenes.
 * 
 * Notes:
 *     The "sc" prefix is to differentiate these variables from identical names in
 *     "complex callbacks".
*/
#ifndef KR_SIMPLECALLBACKS_H_
#define KR_SIMPLECALLBACKS_H_ 2012060201

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

void scProc();
void scQuit();

#ifdef __cplusplus
} //extern "C"
#endif

#endif
