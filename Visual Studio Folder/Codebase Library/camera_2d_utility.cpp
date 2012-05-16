/* File Name: camera_2d_utility.cpp
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
 *     Allow for dynamic (and smooth) movement of the camera on  2D plane.
*/
#include <exception>
#include "camera_2d_utility.h"

//-------------------------
//Preprocessor directives
//-------------------------

#if KR_ORIGIN2D_H_ != KR_CAMERA2DUTILITY_H_
#error Origin2D version is incompatible with Camera2DUtility
#endif

//-------------------------
//Public access members
//-------------------------

Camera2DUtility::Camera2DUtility() {
	m_eMode = NORMAL;
	m_iScreenW = 0;
	m_iScreenH = 0;
}

int Camera2DUtility::GetCamX() {
	switch(m_eMode) {
		case NORMAL: return -(int)GetOriginX();
		case CENTER: return -((int)GetOriginX() - (m_iScreenW/2));
//		case TARGET: //unknown
		case DISABLE: return 0;
		default: throw(std::exception("Invalid Camera Mode found"));
	}
}

int Camera2DUtility::GetCamY() {
	switch(m_eMode) {
		case NORMAL: return -(int)GetOriginY();
		case CENTER: return -((int)GetOriginY() - (m_iScreenH/2));
//		case TARGET: //unknown
		case DISABLE: return 0;
		default: throw(std::exception("Invalid Camera Mode found"));
	}
}

//-------------------------
//Mode
//-------------------------

Camera2DUtility::Mode Camera2DUtility::SetMode(Camera2DUtility::Mode eMode) {
	//possibility for a "position correction" here, that would prevent the "jump" when the mode is changed
	if (eMode <= _BEGIN || eMode >= _END) throw(std::exception("Invalid Camera Mode"));
	return m_eMode = eMode;
}

Camera2DUtility::Mode Camera2DUtility::GetMode() {
	return m_eMode;
}

//-------------------------
//Screen size
//-------------------------

void Camera2DUtility::SetScreenSize(int w, int h) {
	m_iScreenW = w;
	m_iScreenH = h;
}

int Camera2DUtility::SetScreenWidth(int w) {
	return m_iScreenW = w;
}

int Camera2DUtility::SetScreenHeight(int h) {
	return m_iScreenH = h;
}

int Camera2DUtility::GetScreenWidth() {
	return m_iScreenW;
}

int Camera2DUtility::GetScreenHeight() {
	return m_iScreenH;
}
