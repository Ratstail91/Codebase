/* File Name: example.h
 * Author: Kayne Ruse
 * Date (dd/mm/yyyy): 24/04/2013
 * Copyright: ...
 * Description: ...
*/
#ifndef EXAMPLE_H_
#define EXAMPLE_H_

#include "base_scene.h"

class Example : public BaseScene {
public:
	/* Public access members */
	Example();
	virtual ~Example();

protected:
	/* Frame loop */
	virtual void FrameStart();
	virtual void FrameEnd();
	virtual void Update();
	virtual void Render(SDL_Surface* const);

	/* Event handlers */
	virtual void MouseMotion		(SDL_MouseMotionEvent const&);
	virtual void MouseButtonDown	(SDL_MouseButtonEvent const&);
	virtual void MouseButtonUp		(SDL_MouseButtonEvent const&);
	virtual void KeyDown			(SDL_KeyboardEvent const&);
	virtual void KeyUp				(SDL_KeyboardEvent const&);
};

#endif
