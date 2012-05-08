/* File Name: base_scene.cpp
 * Author: Kayne Ruse
 * Date: 11/2/2012
 * Copyright: (c) Kayne Ruse 2012
 * 
 * This file is part of Codebase Library.
 * 
 * Codebase Library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Codebase Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with Codebase Library.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Description: 
 *     The abstract base class for implementing scenes in a game.
*/
#include <exception>
#include "base_scene.h"

//-------------------------
//Static members
//-------------------------

SDL_Surface* BaseScene::ms_pScreen = NULL;

SDL_Surface* BaseScene::SetScreen(int w, int h, int bpp, int iFlags) {
	//SDL video
	ms_pScreen = SDL_SetVideoMode(w, h, bpp, iFlags);

	if (ms_pScreen == NULL)
		throw(std::exception("Failed to initialise the screen surface"));

	return ms_pScreen;
}

SDL_Surface* BaseScene::GetScreen() {
	return ms_pScreen;
}

//-------------------------
//Public access members
//-------------------------

BaseScene::BaseScene() {
	m_iReturn = SCENE_NULL;
}

BaseScene::~BaseScene() {
	//
}

//-------------------------
//Program control members
//-------------------------

void BaseScene::RunFrame() {
	BeginLoop	();

	Input		();
	Update		();
	Draw		(ms_pScreen);

	SDL_Flip	(ms_pScreen);

	EndLoop		();
}

int BaseScene::Return() {
	return m_iReturn;
}

int BaseScene::Return(int i) {
	return m_iReturn = i;
}

void BaseScene::Quit() {
	Return(SCENE_EXIT);
}

//-------------------------
//Input loop
//-------------------------

void BaseScene::Input() {
	SDL_Event event;

	while(SDL_PollEvent(&event)) {
		Event(event);

		switch(event.type) {
			case SDL_QUIT:
				Quit();
				break;

			case SDL_VIDEORESIZE:
				SetScreen(event.resize.w, event.resize.h, 0, ms_pScreen->flags);
				break;

			case SDL_MOUSEMOTION:
				MouseMotion(event.motion);
				break;

			case SDL_MOUSEBUTTONDOWN:
				MouseButtonDown(event.button);
				break;

			case SDL_MOUSEBUTTONUP:
				MouseButtonUp(event.button);
				break;

			case SDL_KEYDOWN:
				KeyDown(event.key);
				break;

			case SDL_KEYUP:
				KeyUp(event.key);
				break;

			case SDL_USEREVENT:
				UserEvent(event.user);
				break;

			default:
				UnknownEvent(event);
				break;
		}
	}
}
