/* File Name: animator.h
 * Author: Kayne Ruse
 * Date (dd/mm/yyyy): 1/11/2012
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
#ifndef KR_ANIMATOR_H_
#define KR_ANIMATOR_H_ 2012110101

#include <time.h>

class Animator {
public:
	/* Public access members */
	Animator();

	void Update();

	unsigned int SetFrame		(unsigned int);
	unsigned int SetFrameCount	(unsigned int);
	unsigned int GetFrame		();
	unsigned int GetFrameCount	();

	time_t SetInterval(time_t);
	time_t GetInterval();

	bool SetActive(bool);
	bool GetActive();

private:
	/* Private access members */
	unsigned int m_frame;
	unsigned int m_framecount;
	time_t m_interval;
	time_t m_tick;
	bool m_active;
};

#endif