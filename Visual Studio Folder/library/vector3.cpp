/* File Name: vector3.cpp
 * Author: Kayne Ruse
 * Date (dd/mm/yyyy): 19/9/2012
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
#include "vector3.h"

#include <stdexcept>
#include <math.h>

//-------------------------
//Public access members
//-------------------------

Vector3::Vector3():
x(0), y(0), z(0)
{
}

Vector3::Vector3(double d):
x(d), y(d), z(d)
{
}

Vector3::Vector3(double _x, double _y, double _z):
x(_x), y(_y), z(_z)
{
}

double Vector3::Length() {
	return sqrt(x*x+y*y+z*z);
}

double Vector3::SquaredLength() {
	return x*x+y*y+z*z;
}

double Vector3::operator[](int i) {
	if (i < 0 || i >= 3)
		throw(std::out_of_range("Out of range"));

	return *(&x+i);
}

//-------------------------
//Arithmetic operators
//-------------------------

Vector3 Vector3::operator+(Vector3 v) {
	return Vector3(x + v.x, y + v.y, z + v.z);
}

Vector3 Vector3::operator-(Vector3 v) {
	return Vector3(x - v.x, y - v.y, z - v.z);
}

Vector3 Vector3::operator*(Vector3 v) {
	return Vector3(x * v.x, y * v.y, z * v.z);
}

Vector3 Vector3::operator*(double d) {
	return Vector3(x * d, y * d, z * d);
}

Vector3 Vector3::operator/(Vector3 v) {
	if (!v.x || !v.y || !v.z)
		throw(std::invalid_argument("Divide by zero"));

	return Vector3(x / v.x, y / v.y, z / v.z);
}

Vector3 Vector3::operator/(double d) {
	if (!d)
		throw(std::invalid_argument("Divide by zero"));

	return Vector3(x / d, y / d, z / d);
}
