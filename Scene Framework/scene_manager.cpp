/* File Name: scene_manager.cpp
 * Author: Kayne Ruse
 * Date (dd/mm/yyyy): 24/04/2013
 * Copyright: (c) Kayne Ruse 2013
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
 *     Initialize the program, and manage the flow of the scene system.
*/
#include "scene_manager.h"

#include <stdexcept>

//-------------------------
//Scene headers
//-------------------------

//Add the custom scene headers here
#include "example.h"

//-------------------------
//Public access members
//-------------------------

SceneManager::SceneManager() {
	activeScene = nullptr;
}

SceneManager::~SceneManager() {
	UnloadScene();
}

void SceneManager::Init() {
	if (SDL_Init(SDL_INIT_VIDEO))
		throw(std::runtime_error("Failed to initialize SDL"));

	BaseScene::SetScreen(800, 600);
}

void SceneManager::Proc() {
	LoadScene(SceneList::FIRST);

	//The main loop
	while(activeScene->GetNextScene() != SceneList::QUIT) {
		//switch scenes when necessary
		if (activeScene->GetNextScene() != SceneList::CONTINUE) {
			LoadScene(activeScene->GetNextScene());
			continue;
		}

		//call each user defined function
		activeScene->RunFrame();
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

void SceneManager::LoadScene(SceneList sceneIndex) {
	UnloadScene();

	switch(sceneIndex) {
		//add scene creation calls here
		case SceneList::FIRST:
		case SceneList::EXAMPLE:
			activeScene = new Example();
		break;

		default:
			throw(std::logic_error("Failed to recognize the scene index"));
	}
}

void SceneManager::UnloadScene() {
	delete activeScene;
	activeScene = nullptr;
}
