/* File Name: origin_2d.h
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
 *     Handle position and motion on a 2D plane.
*/
#ifndef KR_ORIGIN2D_H_
#define KR_ORIGIN2D_H_ 2012051601

class Origin2D {
public:
	/* Public access members */
	Origin2D(float x = 0, float y = 0);

	virtual void Update(int iDelta);

	/* Positon in 2D */
	void SetOriginPosition		(float x, float y);
	float SetOriginX			(float x);
	float SetOriginY			(float y);

	void ShiftOriginPosition	(float x, float y);
	float ShiftOriginX			(float x);
	float ShiftOriginY			(float y);

	float GetOriginX			();
	float GetOriginY			();

	/* Motion in 2D */
	void SetMotion		(float x, float y);
	float SetMotionX	(float x);
	float SetMotionY	(float y);

	void ShiftMotion	(float x, float y);
	float ShiftMotionX	(float x);
	float ShiftMotionY	(float y);

	float GetMotionX	();
	float GetMotionY	();

	void StopMotion		();

private:
	/* Private access members */
	float m_fOriginX;
	float m_fOriginY;
	float m_fMotionX;
	float m_fMotionY;
};

#endif
