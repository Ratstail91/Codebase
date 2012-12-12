/* File Name: frame_rate.cpp
 * Author: Kayne Ruse
 * Date (dd/mm/yyyy): 13/12/2012
 * Copyright: (c) Kayne Ruse 2012
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 * claim that you wrote the original software. If you use this software
 * in a product, an acknowledgment in the product documentation would be
 * appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such, and must not be
 * misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source
 * distribution.
 *
 * Description:
 *     ...
*/
#include "frame_rate.h"

#include <time.h>

//-------------------------
//Static members
//-------------------------

int FrameRate::ms_iFrameCount = 0;
int FrameRate::ms_iFrameRate = 0;
int FrameRate::ms_iTick = 0;

//-------------------------
//Public access members
//-------------------------

int FrameRate::CalcFrameRate() {
	ms_iFrameCount++;
	if (clock() - ms_iTick >= CLOCKS_PER_SEC) {
		ms_iFrameRate = ms_iFrameCount;
		ms_iFrameCount = 0;
		ms_iTick = clock();
	}
	return ms_iFrameRate;
}

int FrameRate::GetFrameRate() {
	return ms_iFrameRate;
}
