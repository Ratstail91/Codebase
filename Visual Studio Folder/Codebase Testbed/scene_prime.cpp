/* File Name: scene_prime.cpp
 * Author: 
 * Date: 
 * Copyright: 
 * Description: 
*/
#include <exception>
#include <iostream>
#include "scene_prime.h"
using namespace std;

//-------------------------
//Preprocessor directives
//-------------------------

#if KR_BASESCENE_H_ != 2012062701 //27/6/2012, revision 1
#error BaseScene version is incompatible with this scene
#endif

//-------------------------
//Public access members
//-------------------------

ScenePrime::ScenePrime() {
	try {
		//load the assets
		m_config.Load("config.cfg");

		//well, this kinda sucks
		m_image.LoadImage( (m_config["path"]+m_config["picture"]).c_str() );
	}
	catch(exception& e) {
		cerr << e.what() << endl;
	}
}

ScenePrime::~ScenePrime() {
	//
}

//-------------------------
//Frame loop members
//-------------------------

void ScenePrime::Head() {
	//
}

void ScenePrime::Tail() {
	//
}

void ScenePrime::Update() {
	//
}

void ScenePrime::Render(SDL_Surface* const pScreen) {
	m_image.DrawTo(pScreen);
}

//-------------------------
//Input loop members
//-------------------------

void ScenePrime::MouseMotion(SDL_MouseMotionEvent const& rMotion) {
	//
}

void ScenePrime::MouseButtonDown(SDL_MouseButtonEvent const& rButton) {
	//
}

void ScenePrime::MouseButtonUp(SDL_MouseButtonEvent const& rButton) {
	//
}

void ScenePrime::KeyDown(SDL_KeyboardEvent const& rKey) {
	switch(rKey.keysym.sym) {
		case SDLK_ESCAPE:
			QuitEvent();
			break;

		//...
	};
}

void ScenePrime::KeyUp(SDL_KeyboardEvent const& rKey) {
	//
}

//-------------------------
//Members
//-------------------------

//...

