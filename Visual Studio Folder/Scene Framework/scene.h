#ifndef KR_SCENE_H_
#define KR_SCENE_H_

#include "SDL.h"
#include "scene_list.h"

class Scene {
public:
	/* Public access members */
	Scene();
	virtual ~Scene();

	/* Program control */
	static SDL_Surface* SetScreen(int w, int h, int bpp = 0, Uint32 flags = SDL_SWSURFACE);
	static SDL_Surface* GetScreen();

	static SceneList SetNextScene(SceneList iSceneIndex);
	static SceneList GetNextScene();

	/* Frame loop */
	virtual void RunFrame();

protected:
	virtual void FrameStart() {}
	virtual void FrameEnd() {}
	virtual void Update() {}
	virtual void Render(SDL_Surface* const pScreen) =0;

	/* Event handlers */
	virtual void EventLoop();

	virtual void QuitEvent			() { SetNextScene(SCENE_QUIT); }
	virtual void MouseMotion		(SDL_MouseMotionEvent const&) {}
	virtual void MouseButtonDown	(SDL_MouseButtonEvent const&) {}
	virtual void MouseButtonUp		(SDL_MouseButtonEvent const&) {}
	virtual void KeyDown			(SDL_KeyboardEvent const&) {}
	virtual void KeyUp				(SDL_KeyboardEvent const&) {}

#ifdef EVENT_USE_JOYSTICK
	//TODO: joystick/gamepad support
#endif

#ifdef EVENT_USE_UNKNOWN
	virtual void UnknownEvent		(SDL_Event const&) {}
#endif

private:
	static SDL_Surface* ms_pScreen;
	static SceneList ms_iNextScene;
};

#endif
