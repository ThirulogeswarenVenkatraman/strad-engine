#include "vector2d.h"
#include "math.h"

void Vector2::Invert() {
	x = -x;
	y = -y;
}

float Vector2::magnitude() const 
{
	return strad(x * x + y * y);
}

strad Vector2::sqrtmagnitude() const
{
	return strad(sqrtf(x * x + y * y));
}

void Vector2::normalize()
{
	strad mag = magnitude();

	if (mag > 0)
	{
		this->x *= ((strad)1) / mag;
		this->y *= ((strad)1) / mag;
	}
}

void Vector2::operator+=(const Vector2& v)
{
	this->x += v.x;
	this->y += v.y;
}

void Vector2::operator-=(const Vector2& v)
{
	this->x -= v.x;
	this->y -= v.y;
}

Vector2 Vector2::operator+(const Vector2& v) const 
{
	return Vector2(this->x + v.x, this->y + v.y);
}

Vector2 Vector2::operator-(const Vector2& v) const
{
	return Vector2(this->x - v.x, this->y - v.y);
}

//multiplies vector by a scalar
void Vector2::operator*=(const strad scalar) 
{
	this->x *= scalar;
	this->y *= scalar;
}

Vector2 Vector2::operator*(const strad scalar) const
{
	return Vector2(x * scalar, y * scalar);
}

void Vector2::addScaledVector(const Vector2& vec, const strad scalar)
{
	this->x += vec.x * scalar;
	this->y += vec.y * scalar;
}

Vector2 Vector2::componentproduct(const Vector2& vec) const
{
	return Vector2(this->x * vec.x, this->y * vec.y);
}

void Vector2::componentproductUpdate(const Vector2& vec)
{
	this->x *= vec.x;
	this->y *= vec.y;
}

strad Vector2::scalarProduct(const Vector2& vec) const
{
	return strad(this->x * vec.x + this->y * vec.y);
}


strad Vector2::operator*(const Vector2& vec) const
{
	return strad(this->x * vec.x + this->y * vec.y);
}

void Vector2::clear()
{
	this->x = 0.0f;
	this->y = 0.0f;
}