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
 *     This version handles multiple scenes.
*/
#ifndef KR_XFRAMEWORK_H_
#define KR_XFRAMEWORK_H_ 2012050302

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
#include "SDL.h"

/* Callback types */
typedef void (*xBasicCallback)(void);
typedef void (*xEventCallback)(SDL_Event const* const);

/* xFramework accessors and mutators */
int xSetInitCallback	(xBasicCallback);
int xSetQuitCallback	(xBasicCallback);

int xSetHeadCallback	(Uint8, xBasicCallback);
int xSetTailCallback	(Uint8, xBasicCallback);
int xSetUpdateCallback	(Uint8, xBasicCallback);
int xSetRenderCallback	(Uint8, xBasicCallback);

int xSetEventCallback	(Uint8, xEventCallback, Uint8);

/* Body of the xFramework */
int xAlloc	(Uint8);
int xSwitch	(Uint8);
int xQuit	(int);
int xProc	();

#ifdef __cplusplus
} //extern "C"
#endif

#endif
