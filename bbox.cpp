/* File Name: bbox.cpp
 * Author: Kayne Ruse
 * Date (dd/mm/yyyy): 21/9/2012
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
#include "bbox.h"

#include <stdexcept>
#include <algorithm>

//-------------------------
//Preprocessor directives
//-------------------------

#define DISTANCE_ABOVE(a,b)	((b).y + (b).h - (a).y)
#define DISTANCE_BELOW(a,b)	((a).y + (a).h - (b).y)
#define DISTANCE_LEFT(a,b)	((b).x + (b).w - (a).x)
#define DISTANCE_RIGHT(a,b)	((a).x + (a).w - (b).x)

//-------------------------
//Member functions
//-------------------------

BBox::BBox():
x(0), y(0), w(0), h(0)
{
}

BBox::BBox(int16_t _x, int16_t _y, uint16_t _w, uint16_t _h):
x(_x), y(_y), w(_w), h(_h)
{
}

BBox BBox::Tweak(int16_t _x, int16_t _y, int16_t _w, int16_t _h) {
	return BBox(
		x + _x,
		y + _y,
		((w > -_w) ? w + _w : 0),
		((h > -_h) ? h + _h : 0));
}

//-------------------------
//Check for a collision
//-------------------------

BBox::Result CheckCollision(BBox a, BBox b) {
	/* lets say there are two boxes with a width of 3
	 * these boxes are given origins of 0 and 3
	 * if the boxes are zero indexed, then they look like this:
	 * 
	 * 0, 1, 2
	 * 3, 4, 5
	 * 
	 * no collision. However, if they have the origins 4 and 6:
	 * 
	 * 4, 5, 6
	 * 6, 7, 8
	 * 
	 * there should be a graphical overlap, which is considered a collision.
	 * because of this, the correct operator in the following (inverted)
	 * if statement is "greater than or equal to", instead of "greater than"
	 * 
	 * Pay close attention when you are building more advanced collision code
	 * on top of this.
	 */
	if (b.x >= a.x + a.w ||
		b.y >= a.y + a.h ||
		a.x >= b.x + b.w ||
		a.y >= b.y + b.h
		)
		return BBox::NONE;

	return BBox::COLLISION;
}

BBox::Result CheckCollisionSide(BBox a, BBox b) {
	if (!CheckCollision(a, b))
		return BBox::NONE;

	//check each side, and return only if true
	if (CheckCollisionAbove(a, b))
		return BBox::ABOVE;

	if (CheckCollisionBelow(a, b))
		return BBox::BELOW;

	if (CheckCollisionLeft(a, b))
		return BBox::LEFT;

	if (CheckCollisionRight(a, b))
		return BBox::RIGHT;

	//error
	throw(std::logic_error("Collision side unknown"));
}

BBox::Result CheckCollisionAbove(BBox a, BBox b) {
	if (!CheckCollision(a, b))
		return BBox::NONE;

	if (DISTANCE_ABOVE(a, b) <= DISTANCE_BELOW(a, b) && DISTANCE_ABOVE(a, b) <= std::min(DISTANCE_LEFT(a, b), DISTANCE_RIGHT(a, b)))
		return BBox::ABOVE;

	return BBox::NONE;
}

BBox::Result CheckCollisionBelow(BBox a, BBox b) {
	if (!CheckCollision(a, b))
		return BBox::NONE;

	if (DISTANCE_BELOW(a, b) <= DISTANCE_ABOVE(a, b) && DISTANCE_BELOW(a, b) <= std::min(DISTANCE_LEFT(a, b), DISTANCE_RIGHT(a, b)))
		return BBox::BELOW;

	return BBox::NONE;
}

BBox::Result CheckCollisionLeft(BBox a, BBox b) {
	if (!CheckCollision(a, b))
		return BBox::NONE;

	if (DISTANCE_LEFT(a, b) <= DISTANCE_RIGHT(a, b) && DISTANCE_LEFT(a, b) <= std::min(DISTANCE_ABOVE(a, b), DISTANCE_BELOW(a, b)))
		return BBox::LEFT;

	return BBox::NONE;
}

BBox::Result CheckCollisionRight(BBox a, BBox b) {
	if (!CheckCollision(a, b))
		return BBox::NONE;

	if (DISTANCE_RIGHT(a, b) <= DISTANCE_LEFT(a, b) && DISTANCE_RIGHT(a, b) <= std::min(DISTANCE_ABOVE(a, b), DISTANCE_BELOW(a, b)))
		return BBox::RIGHT;

	return BBox::NONE;
}
