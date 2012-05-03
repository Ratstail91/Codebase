/* File Name: xFramework.h
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
 *     This version handles only one scene.
*/
#ifndef KR_XFRAMEWORK_H_
#define KR_XFRAMEWORK_H_ 2012050301

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
#include "SDL.h"

/* Callback types */
typedef void (*xBasicCallback)(void);
typedef void (*xEventCallback)(SDL_Event const* const);

/* xFramework functions */
int xSetInitCallback	(xBasicCallback);
int xSetQuitCallback	(xBasicCallback);

int xSetHeadCallback	(xBasicCallback);
int xSetTailCallback	(xBasicCallback);
int xSetUpdateCallback	(xBasicCallback);
int xSetRenderCallback	(xBasicCallback);

int xSetEventCallback	(xEventCallback, Uint8);

void xProc();
void xQuit();

#ifdef __cplusplus
} //extern "C"
#endif

#endif
