#ifndef KR_VECTOR2_H_
#define KR_VECTOR2_H_

class Vector2 {
public:
	/* Public access members */
	double x, y;

	Vector2();
	Vector2(double);
	Vector2(double, double);

	double Length();
	double SquaredLength();

	/* Arithmetic operators */
	inline Vector2 operator+(Vector2);
	inline Vector2 operator-(Vector2);
	inline Vector2 operator*(Vector2);
	inline Vector2 operator*(double);
	inline Vector2 operator/(Vector2);
	inline Vector2 operator/(double);

	template<typename T> Vector2& operator+=(T t) { return *this = *this + t; }
	template<typename T> Vector2& operator-=(T t) { return *this = *this - t; }
	template<typename T> Vector2& operator*=(T t) { return *this = *this * t; }
	template<typename T> Vector2& operator/=(T t) { return *this = *this / t; }
};

#endif
