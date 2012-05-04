/* File Name: origin.h
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
 *     Handle position and motion on a 2D plane.
*/
#ifndef KR_ORIGIN_H_
#define KR_ORIGIN_H_ 2012010301

class Origin {
public:
	/* Public access members */
	Origin(float fRealX = 0, float fRealY = 0);

	virtual void Update(int iDelta);

	/* Real positon */
	void SetRealPosition	(float fRealX, float fRealY);
	float SetRealX			(float fRealX);
	float SetRealY			(float fRealY);

	void ShiftRealPosition	(float fRealX, float fRealY);
	float ShiftRealX		(float fRealX);
	float ShiftRealY		(float fRealY);

	float GetRealX			();
	float GetRealY			();

	/* Real motion */
	void SetMotion			(float fMotionX, float fMotionY);
	float SetMotionX		(float fMotionX);
	float SetMotionY		(float fMotionY);

	void ShiftMotion		(float fMotionX, float fMotionY);
	float ShiftMotionX		(float fMotionX);
	float ShiftMotionY		(float fMotionY);

	float GetMotionX		();
	float GetMotionY		();

	void StopMotion			();

private:
	/* Private access members */
	float m_fRealX;
	float m_fRealY;
	float m_fMotionX;
	float m_fMotionY;
};

#endif
