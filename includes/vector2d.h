#ifndef _VECTOR2D__H
#define _VECTOR2D__H

typedef float strad;

class Vector2 {
	strad x;
	strad y;
public:
	Vector2() : x(0.0f), y(0.0f) { }
	Vector2(strad xx, strad yy) : x(xx),y(yy) { }

	void Invert();
	strad magnitude() const;
	strad sqrtmagnitude() const;
	void normalize();

	void operator+=(const Vector2& v);
	Vector2 operator+(const Vector2& v) const;
	void operator-=(const Vector2& v);
	Vector2 operator-(const Vector2& v) const;
	void operator*=(const strad scalar);
	Vector2 operator*(const strad scalar) const;

	void clear();
	void addScaledVector(const Vector2& vec, const strad scalar);
	Vector2 componentproduct(const Vector2& vec) const;
	void componentproductUpdate(const Vector2& vec);

	strad scalarProduct(const Vector2& vec) const;
	strad operator*(const Vector2& vec) const;

};

#endif 