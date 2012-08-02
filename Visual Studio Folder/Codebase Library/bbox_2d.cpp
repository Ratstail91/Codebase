/* File Name: bbox_2d.cpp
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
#include "bbox_2d.h"

//-------------------------
//Public access members
//-------------------------

BBox2D::BBox2D(Sint16 x, Sint16 y, Uint16 w, Uint16 h) {
	m_rect.x = x;
	m_rect.y = y;
	m_rect.w = w;
	m_rect.h = h;
}

BBox2D::BBox2D(SDL_Rect box) : m_rect(box) {
	//
}

SDL_Rect BBox2D::GetWorldBBox() {
	return GetWorldBBox(0, 0);
}

bool BBox2D::CheckWorldBBox(SDL_Rect otherBox) {
	return CheckWorldBBox(otherBox, 0, 0);
}

SDL_Rect BBox2D::GetWorldBBox(Sint16 x, Sint16 y) {
	SDL_Rect box = m_rect;

	box.x += x;
	box.y += y;

	return box;
}

bool BBox2D::CheckWorldBBox(SDL_Rect otherBox, Sint16 x, Sint16 y) {
	SDL_Rect myBox = GetWorldBBox(x, y);

	/* lets say there are two boxes with a width of 3
	 * these boxes are given origins of 0 and 3
	 * if the boxes are zero indexed, then they look like this:
	 * 
	 *     0, 1, 2
	 *     3, 4, 5
	 * 
	 * no collision. However, if they have the origins 4 and 6:
	 * 
	 *     4, 5, 6
	 *     6, 7, 8
	 * 
	 * there should be a graphical overlap, which is considered a collision.
	 * because of this, the correct operator in the following (inverted)
	 * if statement is "greater than or equal to", instead of "greater than"
	 * 
	 * Pay close attention when you are building more advanced collision code
	 * on top of this.
	*/

	if (
			otherBox.x >= myBox.x + myBox.w ||
			otherBox.y >= myBox.y + myBox.h ||
			myBox.x >= otherBox.x + otherBox.w ||
			myBox.y >= otherBox.y + otherBox.h
		)
		return false;

	return true;
}

//-------------------------
//Accessors and mutators
//-------------------------

void BBox2D::SetBBox(Sint16 x, Sint16 y, Uint16 w, Uint16 h) {
	m_rect.x = x;
	m_rect.y = y;
	m_rect.w = w;
	m_rect.h = h;
}

void BBox2D::SetBBox(SDL_Rect box) {
	m_rect = box;
}

SDL_Rect BBox2D::GetBBox() {
	return m_rect;
}

Sint16 BBox2D::SetBBoxX(Sint16 x) {
	return m_rect.x = x;
}

Sint16 BBox2D::SetBBoxY(Sint16 y) {
	return m_rect.y = y;
}

Uint16 BBox2D::SetBBoxW(Uint16 w) {
	return m_rect.w = w;
}

Uint16 BBox2D::SetBBoxH(Uint16 h) {
	return m_rect.h = h;
}

Sint16 BBox2D::GetBBoxX() {
	return m_rect.x;
}

Sint16 BBox2D::GetBBoxY() {
	return m_rect.y;
}

Uint16 BBox2D::GetBBoxW() {
	return m_rect.w;
}

Uint16 BBox2D::GetBBoxH() {
	return m_rect.h;
}
