#ifndef EXAMPLE_HPP_
#define EXAMPLE_HPP_

#include "base_scene.hpp"

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
	virtual void MouseMotion(SDL_MouseMotionEvent const&);
	virtual void MouseButtonDown(SDL_MouseButtonEvent const&);
	virtual void MouseButtonUp(SDL_MouseButtonEvent const&);
	virtual void KeyDown(SDL_KeyboardEvent const&);
	virtual void KeyUp(SDL_KeyboardEvent const&);
};

#endif
