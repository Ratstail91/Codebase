/* File Name: scene.cpp
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
#include <exception>
#include "scene.h"

//-------------------------
//Static declarations
//-------------------------

SDL_Surface* Scene::ms_pScreen = NULL;
SceneList Scene::ms_iNextScene = SCENE_NULL;

//-------------------------
//Public access members
//-------------------------

Scene::Scene() {
	//
}

Scene::~Scene() {
	//
}

//-------------------------
//Program control
//-------------------------

SDL_Surface* Scene::SetScreen(int w, int h, int bpp, Uint32 flags) {
	if (!bpp)
		bpp = SDL_GetVideoInfo()->vfmt->BitsPerPixel;

	ms_pScreen = SDL_SetVideoMode(w, h, bpp, flags);

	if (ms_pScreen == NULL)
		throw(std::exception("Failed to create the screen surface"));

	return ms_pScreen;
}

SDL_Surface* Scene::GetScreen() {
	return ms_pScreen;
}

SceneList Scene::SetNextScene(SceneList iSceneIndex) {
	return ms_iNextScene = iSceneIndex;
}

SceneList Scene::GetNextScene() {
	return ms_iNextScene;
}

//-------------------------
//Frame loop
//-------------------------

void Scene::RunFrame() {
	FrameStart();

	EventLoop();
	Update();
	Render(ms_pScreen);

	SDL_Flip(ms_pScreen);

	FrameEnd();
}

//-------------------------
//Event handlers
//-------------------------

void Scene::EventLoop() {
	SDL_Event event;

	while(SDL_PollEvent(&event)) {
		switch(event.type) {
			case SDL_QUIT:
				QuitEvent();
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

#ifdef EVENT_USE_JOYSTICK
			//TODO: joystick/gamepad support
#endif

#ifdef EVENT_USE_UNKNOWN
			default:
				UnknownEvent(event);
				break;
#endif
		}//switch
	}//while
}
