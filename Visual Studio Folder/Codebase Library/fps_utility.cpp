/* File Name: fps_utility.cpp
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
#include <time.h>
#include "fps_utility.h"

//-------------------------
//Static members
//-------------------------

int FPSUtility::ms_iFrameRate = 0;
int FPSUtility::ms_iLastFrameRate = 0;
int FPSUtility::ms_iFrameTick = 0;
int FPSUtility::ms_iDeltaTime = 0;
int FPSUtility::ms_iDeltaTick = 0;

//-------------------------
//Public access members
//-------------------------

int FPSUtility::CalcFrameRate() {
	if (clock() - ms_iFrameTick >= CLOCKS_PER_SEC) {
		ms_iLastFrameRate = ms_iFrameRate;
		ms_iFrameRate = 0;
		ms_iFrameTick = clock();
	}
	ms_iFrameRate++;
	return ms_iLastFrameRate;
}

int FPSUtility::CalcDeltaTime() {
	ms_iDeltaTime = clock() - ms_iDeltaTick;
	ms_iDeltaTick = clock();
	return ms_iDeltaTime;
}

int FPSUtility::GetFrameRate() {
	return ms_iLastFrameRate;
}

int FPSUtility::GetDeltaTime() {
	return ms_iDeltaTime;
}
