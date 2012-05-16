/* File Name: bbox_2d.h
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
 *     Detect and handle box collisions on a 2D plane.
*/
#ifndef KR_BBOX2D_H_
#define KR_BBOX2D_H_ 2012051601

class BBox2D {
public:
	/* Box struct */
	typedef struct Rect {
		float x;
		float y;
		float w;
		float h;
	}Rect;

	enum {FALSE=0, EDGE=1, INSIDE=2, OUTSIDE=3};

	/* Public access members */
	BBox2D(float x=0, float y=0, float w=0, float h=0);
	BBox2D(Rect box);

	virtual Rect GetWorldBBox	();
	virtual int CheckWorldBBox	(Rect box);
	virtual Rect GetWorldBBox	(float x, float y);
	virtual int CheckWorldBBox	(float x, float y, Rect box);

	/* Accessors and mutators */
	Rect SetBBox(float x, float y, float w, float h);
	Rect SetBBox(Rect box);

	Rect GetBBox();

	float SetBBoxX(float);
	float SetBBoxY(float);
	float SetBBoxW(float);
	float SetBBoxH(float);

	float GetBBoxX();
	float GetBBoxY();
	float GetBBoxW();
	float GetBBoxH();

private:
	/* Private access members */
	Rect m_rect;
};

#endif
