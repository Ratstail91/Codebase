/* File Name: scene_prime.cpp
 * Author: 
 * Date: 
 * Copyright: 
 * Description: 
*/
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
	m_one.LoadImage("jumpman.bmp");
	m_two.LoadImage("two.bmp", 0, 300);
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
	FPSUtility::CalcDeltaTime();

	//collision
	SDL_Rect tmp = m_one.GetWorldBBox(); //this workournd should stop the dancing
	tmp.h += 1;

	if (m_two.CheckWorldBBox( tmp )) {
		cout << "collision" << endl;
		m_one.StopMotion();
		m_one.SetOriginY( float(m_two.GetWorldBBox().y - m_one.GetBBoxH()) );
	}
	else {
		cout << "falling" << endl;
		m_one.SetMotionY(.1f);
	}

	m_one.Update( FPSUtility::GetDeltaTime() );
}

void ScenePrime::Render(SDL_Surface* const pScreen) {
	SDL_FillRect(pScreen, NULL, SDL_MapRGB(pScreen->format, 0, 0, 0));
	m_one.DrawTo(pScreen);
	m_two.DrawTo(pScreen);
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

