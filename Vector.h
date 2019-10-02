#ifndef _VECTOR_H
	#define _VECTOR_H

#include <vector>
#include <math.h>

class Vector
{

	public:

		Vector(float x = 0.0f, float y = 0.0f);

		float X;

		float Y;

		void Normalize();

		float Length();

public:

		Vector operator +(const Vector& v);
		Vector operator -(const Vector& v);
		Vector operator *(const float& mag);
		Vector operator /(const float& mag);

		void operator =(const Vector& v);
		void operator +=(const Vector& v);
		void operator -=(const Vector& v);

};

Vector operator *(const float& mag, const Vector& v);

#endif