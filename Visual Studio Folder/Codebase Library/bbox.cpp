/* File Name: bbox.cpp
 * Author: Kayne Ruse
 * Date: 20/3/2012
 * Copyright: (c) Kayne Ruse 2012
 * 
 * This file is part of Codebase Library.
 * 
 * Codebase Library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Codebase Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with Codebase Library.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Description: 
 *     Detect and handle box collisions.
*/
#include "bbox.h"

//-------------------------
//Public access members
//-------------------------

BBox::BBox(float x, float y, float w, float h) {
	m_rect.x = x;
	m_rect.y = y;
	m_rect.w = w;
	m_rect.h = h;
}

BBox::BBox(Rect box) {
	m_rect = box;
}

BBox::Rect BBox::GetWorldBBox() {
	return GetWorldBBox(0, 0);
}

int BBox::CheckWorldBBox(Rect box) {
	return CheckWorldBBox(0, 0, box);
}

BBox::Rect BBox::GetWorldBBox(float fRealX, float fRealY) {
	Rect box = m_rect;

	box.x += fRealX;
	box.y += fRealY;
	box.w += fRealX;
	box.h += fRealY;

	return box;
}

int BBox::CheckWorldBBox(float fRealX, float fRealY, Rect box) {
	Rect myBox = GetWorldBBox(fRealX, fRealY);

	/* Returns:
	 * 0: false
	 * 1: edge
	 * 2: this is inside
	 * 3: this is outside
	*/

	if (
			myBox.x < box.x &&
			myBox.y < box.y &&
			myBox.w > box.w &&
			myBox.h > box.h
		)
		return OUTSIDE;

	if (
			myBox.x > box.x &&
			myBox.y > box.y &&
			myBox.w < box.w &&
			myBox.h < box.h
		)
		return INSIDE;

	if (
			myBox.x < box.w &&
			myBox.y < box.h &&
			myBox.w > box.x &&
			myBox.h > box.y
		)
		return EDGE;

	return FALSE;
}

//-------------------------
//Accessors and mutators
//-------------------------

BBox::Rect BBox::SetBBox(float x, float y, float w, float h) {
	m_rect.x = x;
	m_rect.y = y;
	m_rect.w = w;
	m_rect.h = h;

	return m_rect;
}

BBox::Rect BBox::SetBBox(Rect box) {
	return m_rect = box;
}

BBox::Rect BBox::GetBBox() {
	return m_rect;
}

float BBox::SetBBoxX(float x) {
	return m_rect.x = x;
}

float BBox::SetBBoxY(float y) {
	return m_rect.y = y;
}

float BBox::SetBBoxW(float w) {
	return m_rect.w = w;
}

float BBox::SetBBoxH(float h) {
	return m_rect.h = h;
}

float BBox::GetBBoxX() {
	return m_rect.x;
}

float BBox::GetBBoxY() {
	return m_rect.y;
}

float BBox::GetBBoxW() {
	return m_rect.w;
}

float BBox::GetBBoxH() {
	return m_rect.h;
}
