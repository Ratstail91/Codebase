/* File Name: camera_utility.h
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
#ifndef KR_CAMERAUTILITY_H_
#define KR_CAMERAUTILITY_H_ 2012011201

#include "origin.h"

class CameraUtility : public Origin {
public:
	/* Mode enum */
	enum Mode {
		NORMAL,
		CENTER
	};

	/* Public access members */
	CameraUtility();

	int GetCamX();
	int GetCamY();

	/* Mode */
	Mode SetMode(Mode eMode);
	Mode GetMode();

	/* Screen size */
	void SetScreenSize	(int w, int h);
	int SetScreenWidth	(int w);
	int SetScreenHeight	(int h);

	int GetScreenWidth	();
	int GetScreenHeight	();

private:
	/* Private access members */
	Mode m_eMode;

	int m_iScreenW;
	int m_iScreenH;
};

#endif
