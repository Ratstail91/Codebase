/* File Name: scene_prime.cpp
 * Copyright: (c) Kayne Ruse, all rights reserved.
 * Author: Kayne Ruse
 * Date: 
 * Description: 
*/
#include "scene_prime.h"

//-------------------------
//Preprocessor directives
//-------------------------

#define CASE break; case
#define SPEED 0.14f

//-------------------------
//Public access members
//-------------------------

ScenePrime::ScenePrime() {
	 m_image.LoadImage("player_red.bmp");
}

ScenePrime::~ScenePrime() {
	m_image.UnloadImage();
}

//-------------------------
//Frame loop members
//-------------------------

void ScenePrime::BeginLoop() {
	//
}

void ScenePrime::EndLoop() {
	//
}

void ScenePrime::Update() {
	m_origin.Update(0);
}

void ScenePrime::Draw(SDL_Surface* const pScreen) {
	m_image.SetImagePosition( m_origin.GetOriginX(), m_origin.GetOriginY() );
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
		CASE SDLK_ESCAPE: Quit();

		//controls
		CASE SDLK_UP:		m_origin.ShiftMotionY(-SPEED);
		CASE SDLK_DOWN:		m_origin.ShiftMotionY( SPEED);
		CASE SDLK_LEFT:		m_origin.ShiftMotionX(-SPEED);
		CASE SDLK_RIGHT:	m_origin.ShiftMotionX( SPEED);
	};
}

void ScenePrime::KeyUp(SDL_KeyboardEvent const& rKey) {
	switch(rKey.keysym.sym) {
		//controls
		CASE SDLK_UP:		m_origin.ShiftMotionY( SPEED);
		CASE SDLK_DOWN:		m_origin.ShiftMotionY(-SPEED);
		CASE SDLK_LEFT:		m_origin.ShiftMotionX( SPEED);
		CASE SDLK_RIGHT:	m_origin.ShiftMotionX(-SPEED);
	};
}

//-------------------------
//Members
//-------------------------

//...

