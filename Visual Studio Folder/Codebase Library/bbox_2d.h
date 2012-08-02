/* File Name: bbox_2d.h
 * Author: Kayne Ruse
 * Date: 2/8/2012
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
 *     Detect and handle box collisions on a 2D plane. This can only interface
 *      with another BBox2D, so the internals should not be messed with.
*/
#ifndef KR_BBOX2D_H_
#define KR_BBOX2D_H_ 2012080201

#include "SDL.h"

class BBox2D {
public:
	/* Public access members */
	BBox2D(Sint16 x=0, Sint16 y=0, Uint16 w=0, Uint16 h=0);
	BBox2D(SDL_Rect box);

	virtual SDL_Rect GetWorldBBox	();
	virtual bool CheckWorldBBox		(SDL_Rect otherBox);
	virtual SDL_Rect GetWorldBBox	(Sint16 x=0, Sint16 y=0);
	virtual bool CheckWorldBBox		(SDL_Rect otherBox, Sint16 x=0, Sint16 y=0);

	/* Accessors and mutators */
	virtual void SetBBox(Sint16 x, Sint16 y, Uint16 w, Uint16 h);
	virtual void SetBBox(SDL_Rect box);

	virtual SDL_Rect GetBBox();

	virtual Sint16 SetBBoxX(Sint16 x);
	virtual Sint16 SetBBoxY(Sint16 y);
	virtual Uint16 SetBBoxW(Uint16 w);
	virtual Uint16 SetBBoxH(Uint16 h);

	virtual Sint16 GetBBoxX();
	virtual Sint16 GetBBoxY();
	virtual Uint16 GetBBoxW();
	virtual Uint16 GetBBoxH();

private:
	/* Private access members */
	SDL_Rect m_rect;
};

#endif
