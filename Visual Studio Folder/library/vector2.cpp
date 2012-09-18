#include "vector2.h"

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
	return Vector2(x / v.x, y / v.y);
}

Vector2 Vector2::operator/(double d) {
	return Vector2(x / d, y / d);
}
