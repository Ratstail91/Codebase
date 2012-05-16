/* File Name: base_scene.h
 * Author: Kayne Ruse
 * Date: 16/5/2012
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
 *     The abstract base class for implementing scenes in the scene framework.
*/
#ifndef KR_BASESCENE_H_
#define KR_BASESCENE_H_ 2012051601

#include "SDL.h"

class BaseScene {
public:
	/* Scene list */
	enum {
		SCENE_QUIT = -1, //close the program
		SCENE_NULL = 0, //do nothing
		SCENE_FIRST = 1 //first scene to open
	};

	/* Static members */
	static SDL_Surface* SetScreen(int w, int h, int bpp, int iFlags);
	static SDL_Surface* GetScreen();

	/* Public access members */
	BaseScene();
	virtual ~BaseScene();

	/* Program control members */
	virtual void RunFrame();
	virtual int GetNextScene();

protected:
	/* Frame loop members */
	virtual void Head	() {}
	virtual void Tail	() {}
	virtual void Input	();
	virtual void Update	() {}
	virtual void Render	(SDL_Surface* const) =0;

	/* Input loop members */
	virtual void QuitEvent			() { SetNextScene(SCENE_QUIT); }
	virtual void MouseMotion		(SDL_MouseMotionEvent const&) {}
	virtual void MouseButtonDown	(SDL_MouseButtonEvent const&) {}
	virtual void MouseButtonUp		(SDL_MouseButtonEvent const&) {}
	virtual void KeyDown			(SDL_KeyboardEvent const&) {}
	virtual void KeyUp				(SDL_KeyboardEvent const&) {}
//	virtual void UnknownEvent		(SDL_Event const&) {}

	/* Program control members */
	virtual int SetNextScene(int);

private:
	static SDL_Surface* ms_pScreen;
	int m_iNextScene;
};

#endif
