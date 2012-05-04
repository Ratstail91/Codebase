/* File Name: simple_callbacks.h
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
 *     This version handles only one scene; see "complex callbacks" for multiple scenes.
 * 
 * Notes:
 *     The "sc_" prefix for the globals is to differentiate these variables from identical
 *     variables in "complex callbacks".
*/
#ifndef KR_SIMPLECALLBACKS_H_
#define KR_SIMPLECALLBACKS_H_ 2012050401

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
#include "SDL.h"

/* Callback types */
typedef void (*scBasicCallback)(void);
typedef void (*scEventCallback)(SDL_Event const* const);

/* Simple callback functions */
int scSetInitCallback	(scBasicCallback);
int scSetQuitCallback	(scBasicCallback);

int scSetHeadCallback	(scBasicCallback);
int scSetTailCallback	(scBasicCallback);
int scSetUpdateCallback	(scBasicCallback);
int scSetRenderCallback	(scBasicCallback);

int scSetEventCallback	(scEventCallback, Uint8);

void scProc();
void scQuit();

#ifdef __cplusplus
} //extern "C"
#endif

#endif
