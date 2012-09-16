/* File Name: scene_example.cpp
 * Author: Kayne Ruse
 * Date (dd/mm/yyyy): 17/09/2012
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
 *     ...
*/
#include "scene_example.h"

//-------------------------
//Public access members
//-------------------------

SceneExample::SceneExample() {
	//
}

SceneExample::~SceneExample() {
	//
}

//-------------------------
//Frame loop
//-------------------------

void SceneExample::FrameStart() {
	//
}

void SceneExample::FrameEnd() {
	//
}

void SceneExample::Update() {
	//
}

void SceneExample::Render(SDL_Surface* const) {
	//
}

//-------------------------
//Event handlers
//-------------------------

void SceneExample::MouseMotion(SDL_MouseMotionEvent const& rMotion) {
	//
}

void SceneExample::MouseButtonDown(SDL_MouseButtonEvent const& rButton) {
	//
}

void SceneExample::MouseButtonUp(SDL_MouseButtonEvent const& rButton) {
	//
}

void SceneExample::KeyDown(SDL_KeyboardEvent const& rKey) {
	switch(rKey.keysym.sym) {
		case SDLK_ESCAPE:
			QuitEvent();
			break;
	}
}

void SceneExample::KeyUp(SDL_KeyboardEvent const& rKey) {
	//
}
