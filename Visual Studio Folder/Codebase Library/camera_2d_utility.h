/* File Name: camera_2d_utility.h
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
#ifndef KR_CAMERA2DUTILITY_H_
#define KR_CAMERA2DUTILITY_H_ 2012051601

#include "origin_2d.h"

class Camera2DUtility : public Origin2D {
public:
	/* Mode enum */
	enum Mode {
		_BEGIN = 0, //bounding

		NORMAL,
		CENTER,
//		TARGET,
		DISABLE,

		_END //bounding
	};

	/* Public access members */
	Camera2DUtility();

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
