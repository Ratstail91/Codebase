/* File Name: origin.h
 * Author: Kayne Ruse
 * Date: 3/1/2012
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
#include "origin.h"

//-------------------------
//Public access members
//-------------------------

Origin::Origin(float fRealX, float fRealY) {
	m_fRealX = fRealX;
	m_fRealY = fRealY;
	m_fMotionX = 0;
	m_fMotionY = 0;
}

void Origin::Update(int iDelta) {
	m_fRealX += iDelta * m_fMotionX + m_fMotionX;
	m_fRealY += iDelta * m_fMotionY + m_fMotionY;
}

//-------------------------
//Real Position
//-------------------------

void Origin::SetRealPosition(float fRealX, float fRealY) {
	m_fRealX = fRealX;
	m_fRealY = fRealY;
}

float Origin::SetRealX(float fRealX) {
	return m_fRealX = fRealX;
}

float Origin::SetRealY(float fRealY) {
	return m_fRealY = fRealY;
}

void Origin::ShiftRealPosition(float fRealX, float fRealY) {
	m_fRealX += fRealX;
	m_fRealY += fRealY;
}

float Origin::ShiftRealX(float fRealX) {
	return m_fRealX += fRealX;
}

float Origin::ShiftRealY(float fRealY) {
	return m_fRealY += fRealY;
}

float Origin::GetRealX() {
	return m_fRealX;
}

float Origin::GetRealY() {
	return m_fRealY;
}

//-------------------------
//Real Motion
//-------------------------

void Origin::SetMotion(float fMotionX, float fMotionY) {
	m_fMotionX = fMotionX;
	m_fMotionY = fMotionY;
}

float Origin::SetMotionX(float fMotionX) {
	return m_fMotionX = fMotionX;
}

float Origin::SetMotionY(float fMotionY) {
	return m_fMotionY = fMotionY;
}

void Origin::ShiftMotion(float fMotionX, float fMotionY) {
	m_fMotionX += fMotionX;
	m_fMotionY += fMotionY;
}

float Origin::ShiftMotionX(float fMotionX) {
	return m_fMotionX += fMotionX;
}

float Origin::ShiftMotionY(float fMotionY) {
	return m_fMotionY += fMotionY;
}

float Origin::GetMotionX() {
	return m_fMotionX;
}

float Origin::GetMotionY() {
	return m_fMotionY;
}

void Origin::StopMotion() {
	m_fMotionX = 0;
	m_fMotionY = 0;
}
