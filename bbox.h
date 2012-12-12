/* File Name: bbox.h
 * Author: Kayne Ruse
 * Date (dd/mm/yyyy): 19/9/2012
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
#ifndef KR_BBOX_H_
#define KR_BBOX_H_ 2012091901

#include "stdint.h"

class BBox {
public:
	int16_t x, y;
	uint16_t w, h;

	enum Result {
		NONE = 0,
		ABOVE, BELOW,
		LEFT, RIGHT,
		COLLISION
	};

	/* Member functions */
	BBox();
	BBox(int16_t x, int16_t y, uint16_t w, uint16_t h);

	BBox Tweak(int16_t x, int16_t y, int16_t w, int16_t h);
};

/* Check for a collision */
BBox::Result CheckCollision			(BBox a, BBox b);
BBox::Result CheckCollisionSide		(BBox a, BBox b);
BBox::Result CheckCollisionAbove	(BBox a, BBox b);
BBox::Result CheckCollisionBelow	(BBox a, BBox b);
BBox::Result CheckCollisionLeft		(BBox a, BBox b);
BBox::Result CheckCollisionRight	(BBox a, BBox b);

#endif
