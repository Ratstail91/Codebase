/* File Name: fps_utility.h
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
 *     To calculate framerate and regulate game speed.
*/
#ifndef KR_FPSUTILITY_H_
#define KR_FPSUTILITY_H_ 2012010301

class FPSUtility {
public:
	/* Public access members */
	static int CalcFrameRate	();
	static int CalcDeltaTime	();
	static int GetFrameRate		();
	static int GetDeltaTime		();

	FPSUtility() {}

private:
	/* Private access members */
	static int ms_iFrameRate;
	static int ms_iLastFrameRate;
	static int ms_iFrameTick;

	static int ms_iDeltaTime;
	static int ms_iDeltaTick;
};

#endif
