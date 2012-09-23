/* File Name: main_menu.cpp
 * Author: Kayne Ruse
 * Date (dd/mm/yyyy): 23/09/2012
 * Copyright: ...
 * Description: ...
*/
#include "main_menu.h"

#include <iostream>
using namespace std;

//-------------------------
//Public access members
//-------------------------

MainMenu::MainMenu(ConfigUtility* cu):
pConfig(cu)
{
	start.LoadImage(pConfig->CString("start_picture"));
	quit.LoadImage(pConfig->CString("quit_picture"));

	start.GetPosition()->x = 100;
	start.GetPosition()->y = 100;
	quit.GetPosition()->x = 100;
	quit.GetPosition()->y = 400;
}

MainMenu::~MainMenu() {
	//
}

//-------------------------
//Frame loop
//-------------------------

void MainMenu::Render(SDL_Surface* const pScreen) {
	SDL_FillRect(pScreen, NULL, 0);
	start.DrawTo(pScreen);
	quit.DrawTo(pScreen);
}

//-------------------------
//Event handlers
//-------------------------

void MainMenu::MouseButtonDown(SDL_MouseButtonEvent const& rButton) {
	//cool hack: mouse becomes a BBox
	BBox m(rButton.x, rButton.y, 0, 0);

	if (CheckCollision(start.GetRealBox(), m)) {
		SetNextScene(HELLO_WORLD);
	}
	else if (CheckCollision(quit.GetRealBox(), m)) {
		QuitEvent();
	}
}

void MainMenu::KeyDown(SDL_KeyboardEvent const& rKey) {
	switch(rKey.keysym.sym) {
		case SDLK_ESCAPE:
			QuitEvent();
			break;
	}
}
