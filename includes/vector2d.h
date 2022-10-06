#ifndef SE_VECTOR_H
#define SE_VECTOR_H

#include "precision.h"

class Vector2 {
	seflow x;
	seflow y;
public:
	Vector2() : x(0.0f), y(0.0f) { }
	Vector2(seflow xx, seflow yy) : x(xx),y(yy) { }

	void Invert();
	seflow magnitude() const;
	seflow sqrtmagnitude() const;
	void normalize();

	void operator+=(const Vector2& v);
	Vector2 operator+(const Vector2& v) const;
	void operator-=(const Vector2& v);
	Vector2 operator-(const Vector2& v) const;
	void operator*=(const seflow scalar);
	Vector2 operator*(const seflow scalar) const;

	void clear();
	void addScaledVector(const Vector2& vec, const seflow scalar);
	Vector2 componentproduct(const Vector2& vec) const;
	void componentproductUpdate(const Vector2& vec);

	seflow scalarProduct(const Vector2& vec) const;
	seflow operator*(const Vector2& vec) const;

};

#endif 