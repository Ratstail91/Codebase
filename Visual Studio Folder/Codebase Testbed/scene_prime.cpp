/* File Name: scene_prime.cpp
 * Copyright: (c) Kayne Ruse, all rights reserved.
 * Author: Kayne Ruse
 * Date: 
 * Description: 
*/
#include <iostream>
#include "scene_prime.h"
using namespace std;

//-------------------------
//Public access members
//-------------------------

ScenePrime::ScenePrime() {
	//camera is usually first
	m_camUtil.SetMode( CameraUtility::NORMAL );
	m_camUtil.SetScreenSize( GetScreen()->w, GetScreen()->h );

	//load this, usually should have it in a try/catch block
	m_cfgUtil.Load( "config.cfg" );

	//another try/catch block for this
	m_udpNet.Init(m_cfgUtil.Integer( "port" )); //port 2000
}

ScenePrime::~ScenePrime() {
	m_udpNet.Quit();
}

//-------------------------
//Frame loop members
//-------------------------

void ScenePrime::BeginLoop() {
	FPSUtility::CalcFrameRate();
}

void ScenePrime::EndLoop() {
	//
}

void ScenePrime::Update() {
	FPSUtility::CalcDeltaTime();

	while (m_udpNet.Receive()) {
		cout << (char*)(m_udpNet.GetDataIn()) << endl;
	}
}

void ScenePrime::Draw(SDL_Surface* const pScreen) {
	//
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
			Quit();
			break;

		case SDLK_SPACE:
			m_udpNet.Send( m_cfgUtil["127.0.0.1"].c_str(), m_cfgUtil.Integer( "port" ), (void*)("Hello world!"), strlen("Hello world!") );
	};
}

void ScenePrime::KeyUp(SDL_KeyboardEvent const& rKey) {
	//
}

//-------------------------
//Members
//-------------------------

//...

