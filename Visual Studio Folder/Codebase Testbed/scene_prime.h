/* File Name: scene_prime.h
 * Author: 
 * Date: 
 * Copyright: 
 * Description: 
*/
#ifndef KR_SCENEPRIME_H_
#define KR_SCENEPRIME_H_

#include "SDL.h"

#include "base_scene.h"
#include "fps_utility.h"
#include "camera_2d_utility.h"

#include "entity.h"

class ScenePrime : public BaseScene {
public:
	/* Public access members */
	ScenePrime();
	virtual ~ScenePrime();

protected:
	/* Frame loop members */
	virtual void Head	();
	virtual void Tail	();
	virtual void Update	();
	virtual void Render	(SDL_Surface* const);

	/* Input loop members */
	virtual void MouseMotion		(SDL_MouseMotionEvent const&);
	virtual void MouseButtonDown	(SDL_MouseButtonEvent const&);
	virtual void MouseButtonUp		(SDL_MouseButtonEvent const&);
	virtual void KeyDown			(SDL_KeyboardEvent const&);
	virtual void KeyUp				(SDL_KeyboardEvent const&);

	/* Members */
	Entity m_red;
	Entity m_blu;

	Camera2DUtility m_camUtil;
};

#endif
