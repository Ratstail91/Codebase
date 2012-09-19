/* File Name: fps_utility.h
 * Author: Kayne Ruse
 * Date: 27/6/2012
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
 *     To calculate framerate and regulate game speed.
*/
#ifndef KR_FPSUTILITY_H_
#define KR_FPSUTILITY_H_

class FPSUtility {
public:
	/* Public access members */
	static int CalcFrameRate	();
	static int CalcDeltaTime	();
	static int GetFrameRate		();
	static int GetDeltaTime		();

private:
	/* Private access members */
	static int ms_iFrameRate;
	static int ms_iLastFrameRate;
	static int ms_iFrameTick;

	static int ms_iDeltaTime;
	static int ms_iDeltaTick;
};

#endif