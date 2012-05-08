/* File Name: base_scene.h
 * Author: Kayne Ruse
 * Date: 11/2/2012
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
 *     The abstract base class for implementing scenes in a game.
*/
#ifndef KR_BASESCENE_H_
#define KR_BASESCENE_H_ 2012021101

#include "SDL.h"

#define SCENE_EXIT -1 //close the program
#define SCENE_NULL	0 //do nothing
#define SCENE_FIRST 1 //default

class BaseScene {
public:
	/* Static members */
	static SDL_Surface* SetScreen(int w, int h, int bpp, int iFlags);
	static SDL_Surface* GetScreen();

	/* Public access members */
	BaseScene();
	virtual ~BaseScene();

	/* Program control members */
	virtual void RunFrame();
	virtual int Return();

protected:
	/* Frame loop members */
	virtual void BeginLoop	() {}
	virtual void EndLoop	() {}
	virtual void Input		();
	virtual void Update		() {}
	virtual void Draw		(SDL_Surface* const) =0;

	/* Input loop members */
	virtual void Event				(SDL_Event const&) {}
	virtual void MouseMotion		(SDL_MouseMotionEvent const&) {}
	virtual void MouseButtonDown	(SDL_MouseButtonEvent const&) {}
	virtual void MouseButtonUp		(SDL_MouseButtonEvent const&) {}
	virtual void KeyDown			(SDL_KeyboardEvent const&) {}
	virtual void KeyUp				(SDL_KeyboardEvent const&) {}
	virtual void UserEvent			(SDL_UserEvent const&) {}
	virtual void UnknownEvent		(SDL_Event const&) {}

	/* Program control members */
	virtual int Return(int);
	virtual void Quit();

private:
	static SDL_Surface* ms_pScreen;
	int m_iReturn;
};

#endif
