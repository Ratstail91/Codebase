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
