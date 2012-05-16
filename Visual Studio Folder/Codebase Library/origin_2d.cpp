/* File Name: origin_2d.h
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
 *     Handle position and motion on a 2D plane.
*/
#include "origin_2d.h"

//-------------------------
//Public access members
//-------------------------

Origin2D::Origin2D(float x, float y) {
	m_fOriginX = x;
	m_fOriginY = y;
	m_fMotionX = 0;
	m_fMotionY = 0;
}

void Origin2D::Update(int iDelta) {
	m_fOriginX += iDelta * m_fMotionX + m_fMotionX;
	m_fOriginY += iDelta * m_fMotionY + m_fMotionY;
}

//-------------------------
//Positon in 2D
//-------------------------

void Origin2D::SetOriginPosition(float x, float y) {
	m_fOriginX = x;
	m_fOriginY = y;
}

float Origin2D::SetOriginX(float x) {
	return m_fOriginX = x;
}

float Origin2D::SetOriginY(float y) {
	return m_fOriginY = y;
}

void Origin2D::ShiftOriginPosition(float x, float y) {
	m_fOriginX += x;
	m_fOriginY += y;
}

float Origin2D::ShiftOriginX(float x) {
	return m_fOriginX += x;
}

float Origin2D::ShiftOriginY(float y) {
	return m_fOriginY += y;
}

float Origin2D::GetOriginX() {
	return m_fOriginX;
}

float Origin2D::GetOriginY() {
	return m_fOriginY;
}

//-------------------------
//Motion in 2D
//-------------------------

void Origin2D::SetMotion(float x, float y) {
	m_fMotionX = x;
	m_fMotionY = y;
}

float Origin2D::SetMotionX(float x) {
	return m_fMotionX = x;
}

float Origin2D::SetMotionY(float y) {
	return m_fMotionY = y;
}

void Origin2D::ShiftMotion(float x, float y) {
	m_fMotionX += x;
	m_fMotionY += y;
}

float Origin2D::ShiftMotionX(float x) {
	return m_fMotionX += x;
}

float Origin2D::ShiftMotionY(float y) {
	return m_fMotionY += y;
}

float Origin2D::GetMotionX() {
	return m_fMotionX;
}

float Origin2D::GetMotionY() {
	return m_fMotionY;
}

void Origin2D::StopMotion() {
	m_fMotionX = 0;
	m_fMotionY = 0;
}
