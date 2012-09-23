/* File Name: animator.cpp
 * Author: Kayne Ruse
 * Date (dd/mm/yyyy): 23/9/2012
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
#include "animator.h"

//-------------------------
//Public access members
//-------------------------

Animator::Animator() {
	m_frame = 0;
	m_framecount = 0;
	m_interval = 0;
	m_tick = 0;
}

void Animator::Update() {
	if (m_interval && clock() - m_tick >= m_interval) {
		m_frame++;
		if (m_frame >= m_framecount) { //GEQ for 0 indexing
			m_frame = 0;
		}
		m_tick = clock();
	}
}

unsigned int Animator::SetFrame(unsigned int i) {
	return m_frame = i;
}

unsigned int Animator::SetFrameCount(unsigned int i) {
	return m_framecount = i;
}

unsigned int Animator::GetFrame() {
	return m_frame;
}

unsigned int Animator::GetFrameCount() {
	return m_framecount;
}

time_t Animator::SetInterval(time_t i) {
	return m_interval = i;
}

time_t Animator::GetInterval() {
	return m_interval;
}

time_t Animator::GetTick() {
	return m_tick;
}
