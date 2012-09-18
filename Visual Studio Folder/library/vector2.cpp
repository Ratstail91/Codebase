/* File Name: vector2.cpp
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
#include "vector2.h"

#include <stdexcept>
#include <math.h>

//-------------------------
//Public access members
//-------------------------

Vector2::Vector2():
x(0), y(0)
{
}

Vector2::Vector2(double d):
x(d), y(d)
{
}

Vector2::Vector2(double _x, double _y):
x(_x), y(_y)
{
}

double Vector2::Length() {
	return sqrt(x*x+y*y);
}

double Vector2::SquaredLength() {
	return x*x+y*y;
}

double Vector2::operator[](int i) {
	if (i < 0 || i >= 2)
		throw(std::out_of_range("Out of range"));

	return *(&x+i);
}

//-------------------------
//Arithmetic operators
//-------------------------

Vector2 Vector2::operator+(Vector2 v) {
	return Vector2(x + v.x, y + v.y);
}

Vector2 Vector2::operator-(Vector2 v) {
	return Vector2(x - v.x, y - v.y);
}

Vector2 Vector2::operator*(Vector2 v) {
	return Vector2(x * v.x, y * v.y);
}

Vector2 Vector2::operator*(double d) {
	return Vector2(x * d, y * d);
}

Vector2 Vector2::operator/(Vector2 v) {
	if (!v.x || !v.y)
		throw(std::invalid_argument("Divide by zero"));

	return Vector2(x / v.x, y / v.y);
}

Vector2 Vector2::operator/(double d) {
	if (!d)
		throw(std::invalid_argument("Divide by zero"));

	return Vector2(x / d, y / d);
}
