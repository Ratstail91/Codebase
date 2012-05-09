/* File Name: camera_utility.cpp
 * Author: Kayne Ruse
 * Date: 12/1/2012
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
 *     Allow for dynamic (and smooth) movement of the camera.
*/
#include <exception>
#include "camera_utility.h"

//-------------------------
//Preprocessor
//-------------------------

#if KR_ORIGIN_H_ != 2012010301
#error Origin may be incorrect version for CameraUtility
#endif

//-------------------------
//Public access members
//-------------------------

CameraUtility::CameraUtility() {
	m_eMode = NORMAL;
	m_iScreenW = 0;
	m_iScreenH = 0;
}

int CameraUtility::GetCamX() {
	switch(m_eMode) {
		case NORMAL: return -(int)GetRealX();
		case CENTER: return -((int)GetRealX() - (m_iScreenW/2));
	}

	throw(std::exception("Unknown CameraUtility::Mode found"));
}

int CameraUtility::GetCamY() {
	switch(m_eMode) {
		case NORMAL: return -(int)GetRealY();
		case CENTER: return -((int)GetRealY() - (m_iScreenH/2));
	}

	throw(std::exception("Unknown CameraUtility::Mode found"));
}

//-------------------------
//Mode
//-------------------------

CameraUtility::Mode CameraUtility::SetMode(Mode eMode) {
	//possibility for a "position correction" here, that would prevent the "jump" when the mode is changed
	return m_eMode = eMode;
}

CameraUtility::Mode CameraUtility::GetMode() {
	return m_eMode;
}

//-------------------------
//Screen size
//-------------------------

void CameraUtility::SetScreenSize(int w, int h) {
	m_iScreenW = w;
	m_iScreenH = h;
}

int CameraUtility::SetScreenWidth(int w) {
	return m_iScreenW = w;
}

int CameraUtility::SetScreenHeight(int h) {
	return m_iScreenH = h;
}

int CameraUtility::GetScreenWidth() {
	return m_iScreenW;
}

int CameraUtility::GetScreenHeight() {
	return m_iScreenH;
}
