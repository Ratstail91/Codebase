/* File Name: base_scene_mgr.cpp
 * Author: Kayne Ruse
 * Date: 3/1/2012
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
 *     The base class for managing a series of classes derived from BaseScene.
*/
#include <exception>
#include <iostream>
#include "base_scene_mgr.h"
using namespace std;

//-------------------------
//Public access members
//-------------------------

void BaseSceneMgr::Init() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		throw(exception("Failed to initialise SDL"));

	BaseScene::SetScreen(800, 600, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
}

void BaseSceneMgr::Loop() {
	try {
		LoadScene();
		m_iNext = m_pScene->Return();

		while(m_iNext != SCENE_EXIT) {
			if (m_iNext != SCENE_NULL) {
				UnloadScene();
				LoadScene();
			}

			m_pScene->RunFrame();
			m_iNext = m_pScene->Return();
		}
	}
	catch(exception& e) {
		cerr << "Error: " << e.what() << endl;
	}
	catch(int& i) {
		cerr << "Error code: " << i << endl;
	}
	catch(...) {
		cerr << "Unhandled exception thrown" << endl;
	}

	UnloadScene();
}

void BaseSceneMgr::Quit() {
	SDL_Quit();
}

//-------------------------
//Protected access members
//-------------------------

BaseSceneMgr::BaseSceneMgr() {
	m_pScene = NULL;
	m_iNext = SCENE_FIRST;
}

BaseSceneMgr::~BaseSceneMgr() {
	//
}

//-------------------------
//Accessors and mutators
//-------------------------

BaseScene* BaseSceneMgr::SetScene(BaseScene* pScene) {
	return m_pScene = pScene;
}

BaseScene* BaseSceneMgr::GetScene() {
	return m_pScene;
}

int BaseSceneMgr::SetNext(int iNext) {
	return m_iNext = iNext;
}

int BaseSceneMgr::GetNext() {
	return m_iNext;
}
//-------------------------
//Scene management members
//-------------------------

void BaseSceneMgr::UnloadScene() {
	delete m_pScene;
	m_pScene = NULL;
}
