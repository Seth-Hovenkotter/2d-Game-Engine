#include "vector.h"


Vector::Vector(float x, float y)
{
	X = x;
	Y = y;
}

// Converts the vector to a unit vector
void Vector::Normalize()
{
	float length = Length();

	if(length <= 0)
	    return;

	X /= length;
	Y /= length;
}

// Finds the Length or Magnitude
float Vector::Length()
{
	return sqrt(X * X + Y * Y);
}

Vector Vector::operator +(const Vector& v)
{
	Vector vector;
	vector.X = X + v.X;
	vector.Y = Y + v.Y;

	return vector;
}

Vector Vector::operator -(const Vector& v)
{
	Vector vector;
	vector.X = X - v.X;
	vector.Y = Y - v.Y;

	return vector;
}

Vector Vector::operator *(const float& mag)
{
	Vector vector;
	vector.X = X * mag;
	vector.Y = Y * mag;

	return vector;
}

Vector Vector::operator /(const float& mag)
{
	Vector vector;
	vector.X = X / mag;
	vector.Y = Y / mag;

	return vector;
}

void Vector::operator =(const Vector& v)
{
	X = v.X;
	Y = v.Y;
}

void Vector::operator +=(const Vector& v)
{
	X += v.X;
	Y += v.Y;
}

void Vector::operator -=(const Vector& v)
{
	X -= v.X;
	Y -= v.Y;
}

Vector operator *(const float& mag, const Vector& v)
{
	Vector vector;
	vector.X = v.X * mag;
	vector.Y = v.Y * mag;

	return vector;
}