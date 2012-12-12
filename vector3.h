/* File Name: vector3.h
 * Author: Kayne Ruse
 * Date (dd/mm/yyyy): 31/10/2012
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
#ifndef KR_VECTOR3_H_
#define KR_VECTOR3_H_ 2012103101

#include <stdexcept>
#include <math.h>

class Vector3 {
public:
	/* Public access members */
	double x, y, z;

	inline Vector2():
	x(0), y(0), z(0)
	{
	}

	inline Vector2(double d):
	x(d), y(d), z(0)
	{
	}

	inline Vector2(double _x, double _y, double _z):
	x(_x), y(_y), z(_z)
	{
	}

	inline double Length() {
		return sqrt(x*x+y*y+z*z);
	}

	inline double SquaredLength()  {
		return x*x+y*y+z*z;
	}

	inline double operator[](size_t i) {
		if (i >= 3)
			throw(std::out_of_range("Out of range"));

		return *(&x+i);
	}

	/* Arithmetic operators */
	inline Vector3 operator+(Vector3 v) { return Vector3(x + v.x, y + v.y, z + v.z); }
	inline Vector3 operator-(Vector3 v) { return Vector3(x - v.x, y - v.y, z - v.z); }
	inline Vector3 operator*(Vector3 v) { return Vector3(x * v.x, y * v.y, z * v.z); }
	inline Vector3 operator*(double d) { return Vector3(x * d, y * d, z * d); }

	inline Vector3 operator/(Vector3 v) {
		if (!v.x || !v.y || !v.z)
			throw(std::invalid_argument("Divide by zero"));

		return Vector3(x / v.x, y / v.y, z / v.z);
	}

	inline Vector3 operator/(double d) {
		if (!d)
			throw(std::invalid_argument("Divide by zero"));

		return Vector3(x / d, y / d, z / d);
	}

	template<typename T> inline Vector3 operator+=(T t) { return *this = *this + t; }
	template<typename T> inline Vector3 operator-=(T t) { return *this = *this - t; }
	template<typename T> inline Vector3 operator*=(T t) { return *this = *this * t; }
	template<typename T> inline Vector3 operator/=(T t) { return *this = *this / t; }

	inline bool operator==(Vector3 v) { return (x == v.x && y == v.y && z == v.z); }
	inline bool operator!=(Vector3 v) { return (x != v.x || y != v.y || z != v.z); }
	template<typename T> inline bool operator==(T t) { return (x == t && y == t && z == t); }
	template<typename T> inline bool operator!=(T t) { return (x != t || y != t || z != t); }
};

#endif
