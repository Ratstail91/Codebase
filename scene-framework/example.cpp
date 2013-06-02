#include "example.hpp"

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

void Example::Update(Clock::duration delta) {
	//
}

void Example::FrameEnd() {
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
