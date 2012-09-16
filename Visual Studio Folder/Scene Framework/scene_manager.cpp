/* File Name: scene_manager.cpp
 * Author: Kayne Ruse
 * Date (dd/mm/yyyy): 17/9/2012
 * Copyright: (c) Kayne Ruse 2012
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 * claim that you wrote the original software. If you use this software
 * in a product, an acknowledgment in the product documentation would be
 * appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such, and must not be
 * misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source
 * distribution.
 *
 * Description:
 *     ...
*/
#include "scene_manager.h"

#include <exception>

//-------------------------
//Scene headers
//-------------------------

//Add the custom scene headers here
#include "scene_example.h"

//-------------------------
//Public access members
//-------------------------

SceneManager::SceneManager() {
	m_pActiveScene = NULL;
}

SceneManager::~SceneManager() {
	UnloadScene();
}

void SceneManager::Init() {
	if (SDL_Init(SDL_INIT_VIDEO))
		throw(std::exception("Failed to initialize SDL"));

	Scene::SetScreen(800, 600);
}

void SceneManager::Proc() {
	LoadScene(SCENE_EXAMPLE);

	//The main loop
	while(m_pActiveScene->GetNextScene() != SCENE_QUIT) {
		//switch scenes when necessary
		if (m_pActiveScene->GetNextScene() != SCENE_NULL) {
			LoadScene(m_pActiveScene->GetNextScene());
			continue;
		}

		//call each user defined function
		m_pActiveScene->RunFrame();
	}

	UnloadScene();
}

void SceneManager::Quit() {
	UnloadScene();
	SDL_Quit();
}

//-------------------------
//Private access members
//-------------------------

void SceneManager::LoadScene(SceneList iSceneIndex) {
	UnloadScene();

	switch(iSceneIndex) {
		//add scene creation here
		case SCENE_EXAMPLE:
			m_pActiveScene = new SceneExample();
			break;

		default:
			throw(std::exception("Failed to recognize scene index"));
	}
}

void SceneManager::UnloadScene() {
	delete m_pActiveScene;
	m_pActiveScene = NULL;
}

//-------------------------
//Entry point
//-------------------------

#include <iostream>

int SDL_main(int, char**) {
	SceneManager app;

	//Try to initiate the program
	try {
		app.Init();
	}
	catch(std::exception& e) {
		std::cerr << "Init Error: " << e.what() << std::endl;
		return 1;
	}

	//try to run the program
	try {
		app.Proc();
	}
	catch(std::exception& e) {
		std::cerr << "Proc Error: " << e.what() << std::endl;

		//try to cleanup after the error
		try {
			app.Quit();
		}
		catch(std::exception& e2) {
			std::cerr << "Quit Error: " << e2.what() << std::endl;
			return 4;
		}

		return 2;
	}

	//try to quit the program
	try {
		app.Quit();
	}
	catch(std::exception& e) {
		std::cerr << "Quit Error: " << e.what() << std::endl;
		return 3;
	}

	//clean exit
	return 0;
}
