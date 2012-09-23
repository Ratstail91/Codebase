/* File Name: hello_world.h
 * Author: Kayne Ruse
 * Date (dd/mm/yyyy): 23/09/2012
 * Copyright: ...
 * Description: ...
*/
#ifndef KR_HELLOWORLD_H_
#define KR_HELLOWORLD_H_

#include "config_utility.h"

#include "scene.h"

#include "actor.h"

class HelloWorld : public Scene {
public:
	/* Public access members */
	HelloWorld(ConfigUtility*);
	virtual ~HelloWorld();

protected:
	/* Frame loop */
	virtual void FrameStart();
	virtual void Update();
	virtual void Render(SDL_Surface* const);

	/* Event handlers */
	virtual void KeyDown			(SDL_KeyboardEvent const&);
	virtual void KeyUp				(SDL_KeyboardEvent const&);

	/* Members */
	ConfigUtility* const pConfig;
	Actor player;
	Actor flower;
};

#endif
