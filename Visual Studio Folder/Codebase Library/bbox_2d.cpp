/* File Name: bbox_2d.cpp
 * Author: Kayne Ruse
 * Date: 16/5/2012
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
 *     Detect and handle box collisions on a 2D plane.
*/
#include "bbox_2d.h"

//-------------------------
//Public access members
//-------------------------

BBox2D::BBox2D(float x, float y, float w, float h) {
	m_rect.x = x;
	m_rect.y = y;
	m_rect.w = w;
	m_rect.h = h;
}

BBox2D::BBox2D(Rect box) {
	m_rect = box;
}

BBox2D::Rect BBox2D::GetWorldBBox() {
	return GetWorldBBox(0, 0);
}

int BBox2D::CheckWorldBBox(Rect box) {
	return CheckWorldBBox(0, 0, box);
}

BBox2D::Rect BBox2D::GetWorldBBox(float x, float y) {
	Rect box = m_rect;

	box.x += x;
	box.y += y;
	box.w += x;
	box.h += y;

	return box;
}

int BBox2D::CheckWorldBBox(float x, float y, Rect box) {
	Rect myBox = GetWorldBBox(x, y);

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

BBox2D::Rect BBox2D::SetBBox(float x, float y, float w, float h) {
	m_rect.x = x;
	m_rect.y = y;
	m_rect.w = w;
	m_rect.h = h;

	return m_rect;
}

BBox2D::Rect BBox2D::SetBBox(Rect box) {
	return m_rect = box;
}

BBox2D::Rect BBox2D::GetBBox() {
	return m_rect;
}

float BBox2D::SetBBoxX(float x) {
	return m_rect.x = x;
}

float BBox2D::SetBBoxY(float y) {
	return m_rect.y = y;
}

float BBox2D::SetBBoxW(float w) {
	return m_rect.w = w;
}

float BBox2D::SetBBoxH(float h) {
	return m_rect.h = h;
}

float BBox2D::GetBBoxX() {
	return m_rect.x;
}

float BBox2D::GetBBoxY() {
	return m_rect.y;
}

float BBox2D::GetBBoxW() {
	return m_rect.w;
}

float BBox2D::GetBBoxH() {
	return m_rect.h;
}
