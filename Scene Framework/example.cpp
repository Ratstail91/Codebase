/* File Name: example.cpp
 * Author: Kayne Ruse
 * Date (dd/mm/yyyy): 24/04/2013
 * Copyright: ...
 * Description: ...
*/
#include "example.h"

//-------------------------
//Public access members
//-------------------------

Example::Example() {
	//
}

Example::~Example() {
	//
}

//-------------------------
//Frame loop
//-------------------------

void Example::FrameStart() {
	//
}

void Example::FrameEnd() {
	//
}

void Example::Update() {
	//
}

void Example::Render(SDL_Surface* const screen) {
	//
}

//-------------------------
//Event handlers
//-------------------------

void Example::MouseMotion(SDL_MouseMotionEvent const& motion) {
	//
}

void Example::MouseButtonDown(SDL_MouseButtonEvent const& button) {
	//
}

void Example::MouseButtonUp(SDL_MouseButtonEvent const& button) {
	//
}

void Example::KeyDown(SDL_KeyboardEvent const& key) {
	switch(key.keysym.sym) {
		case SDLK_ESCAPE:
			QuitEvent();
			break;
	}
}

void Example::KeyUp(SDL_KeyboardEvent const& key) {
	//
}
