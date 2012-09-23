/* File Name: hello_world.cpp
 * Author: Kayne Ruse
 * Date (dd/mm/yyyy): 23/09/2012
 * Copyright: ...
 * Description: ...
*/
#include "hello_world.h"

#include "delta.h"
#include "frame_rate.h"
#include <iostream>
using namespace std;

//-------------------------
//Preprocessor directives
//-------------------------

#define SPEED 0.14f
#define CASE break; case

//-------------------------
//Public access members
//-------------------------

HelloWorld::HelloWorld(ConfigUtility* cu):
pConfig(cu)
{
	player.LoadImage(pConfig->CString("player_picture"));
	flower.LoadImage(pConfig->CString("flower_picture"), 4, 100);
}

HelloWorld::~HelloWorld() {
	//
}

//-------------------------
//Frame loop
//-------------------------

void HelloWorld::FrameStart() {
	FrameRate::CalcFrameRate();

	cout << "fps: " << FrameRate::GetFrameRate() << endl;
}

void HelloWorld::Update() {
	Delta::CalcDelta();

	//update all onscreen entities
	player.Update( Delta::GetDelta() );

	flower.Update( Delta::GetDelta() );
}

int fib(int i) {
	//fibonacci
	if (i < 3) return 1;
	return fib(i-1) + fib(i-2);
}

void HelloWorld::Render(SDL_Surface* const pScreen) {
	SDL_FillRect(pScreen, NULL, 0);

	for (int i = 0; i < 12; i++) {
		//a pretty pattern for the flower
		flower.GetPosition()->x = fib(i);
		flower.GetPosition()->y = fib(i+2);
		flower.DrawTo(pScreen);
	}

	player.DrawTo(pScreen);
}

//-------------------------
//Event handlers
//-------------------------

void HelloWorld::KeyDown(SDL_KeyboardEvent const& rKey) {
	switch(rKey.keysym.sym) {
		CASE SDLK_ESCAPE: SetNextScene(MAIN_MENU);

		//player movement
		CASE SDLK_UP:		player.GetMotion()->y -= SPEED;
		CASE SDLK_DOWN:		player.GetMotion()->y += SPEED;
		CASE SDLK_LEFT:		player.GetMotion()->x -= SPEED;
		CASE SDLK_RIGHT:	player.GetMotion()->x += SPEED;
	}
}

void HelloWorld::KeyUp(SDL_KeyboardEvent const& rKey) {
	switch(rKey.keysym.sym) {
		//player movement
		CASE SDLK_UP:		player.GetMotion()->y += SPEED;
		CASE SDLK_DOWN:		player.GetMotion()->y -= SPEED;
		CASE SDLK_LEFT:		player.GetMotion()->x += SPEED;
		CASE SDLK_RIGHT:	player.GetMotion()->x -= SPEED;
	}
}
