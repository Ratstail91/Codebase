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

#if KR_BASESCENE_H_ != 2012051601 // 16/5/2012, revision 1
#error BaseScene version is incompatible with this scene
#endif

//-------------------------
//Public access members
//-------------------------

ScenePrime::ScenePrime() {
	//setup the camera

	m_camUtil.SetScreenSize( GetScreen()->w, GetScreen()->h );
	m_camUtil.SetMode( Camera2DUtility::CENTER );

	//load the assets
	try {
		m_red.LoadImage("player_red.bmp");

		//testing Image::IsLoadedImage()
		cout << m_red.IsLoadedImage() << endl;
		cout << m_blu.IsLoadedImage() << endl;

		m_blu.LoadImage("player_blue.bmp");
	}
	catch(exception& e) {
		cerr << "Asset error: " << e.what() << endl;
		QuitEvent();
	}
}

ScenePrime::~ScenePrime() {
	//free the assets
	m_red.UnloadImage();
	m_blu.UnloadImage();
}

//-------------------------
//Frame loop members
//-------------------------

void ScenePrime::Head() {
	//calcualte the framerate
	FPSUtility::CalcFrameRate();
}

void ScenePrime::Tail() {
	//
}

void ScenePrime::Update() {
	//smooth movement
	FPSUtility::CalcDeltaTime();

	m_red.Update( FPSUtility::GetDeltaTime() );
	m_blu.Update( FPSUtility::GetDeltaTime() );
}

void ScenePrime::Render(SDL_Surface* const pScreen) {
	//camera adjustment
	m_camUtil.SetOriginPosition( m_red.GetOriginX(), m_red.GetOriginY() );

	//grey background
	SDL_FillRect(pScreen, NULL, SDL_MapRGB(pScreen->format, 192, 192, 192) );

	//white square
	SDL_Rect square;

	square.x = -60 + m_camUtil.GetCamX();
	square.y = -60 + m_camUtil.GetCamY();
	square.w = 120;
	square.h = 120;

	SDL_FillRect(pScreen, &square, SDL_MapRGB(pScreen->format, 255, 255, 255) );

	//draw the entities, using  the camera coords
	m_red.DrawTo(pScreen, m_camUtil.GetCamX(), m_camUtil.GetCamY());
	m_blu.DrawTo(pScreen, m_camUtil.GetCamX(), m_camUtil.GetCamY());
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

		//red player controls
		case SDLK_UP:		m_red.ShiftMotionY(-0.14f); break;
		case SDLK_DOWN:		m_red.ShiftMotionY( 0.14f); break;
		case SDLK_LEFT:		m_red.ShiftMotionX(-0.14f); break;
		case SDLK_RIGHT:	m_red.ShiftMotionX( 0.14f); break;

		//output the framerate
		case SDLK_f:
			cout << FPSUtility::GetFrameRate() << endl;
			break;
	};
}

void ScenePrime::KeyUp(SDL_KeyboardEvent const& rKey) {
	switch(rKey.keysym.sym) {
		//red player controls
		case SDLK_UP:		m_red.ShiftMotionY( 0.14f); break;
		case SDLK_DOWN:		m_red.ShiftMotionY(-0.14f); break;
		case SDLK_LEFT:		m_red.ShiftMotionX( 0.14f); break;
		case SDLK_RIGHT:	m_red.ShiftMotionX(-0.14f); break;
	};
}

//-------------------------
//Members
//-------------------------

//...

