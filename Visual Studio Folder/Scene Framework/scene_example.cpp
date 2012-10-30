/* File Name: scene_example.cpp
 * Author: Kayne Ruse
 * Date (dd/mm/yyyy): 31/10/2012
 * Copyright: ...
 * Description: ...
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

void SceneExample::Render(SDL_Surface* const screen) {
	//
}

//-------------------------
//Event handlers
//-------------------------

void SceneExample::MouseMotion(SDL_MouseMotionEvent const& motion) {
	//
}

void SceneExample::MouseButtonDown(SDL_MouseButtonEvent const& button) {
	//
}

void SceneExample::MouseButtonUp(SDL_MouseButtonEvent const& button) {
	//
}

void SceneExample::KeyDown(SDL_KeyboardEvent const& key) {
	switch(key.keysym.sym) {
		case SDLK_ESCAPE:
			QuitEvent();
			break;
	}
}

void SceneExample::KeyUp(SDL_KeyboardEvent const& key) {
	//
}
