#pragma once
#include <iostream>
#include <math.h>
#include <iosfwd>
#include <limits>
class Vector2D
{

private:

public:
	Vector2D() {};
	~Vector2D() {};

	float x;
	float y;

	Vector2D(float x, float y) { this->x = x; this->y = y; };

	float getX() { return x; }
	float getY() { return y; }

	bool operator < (const Vector2D* vector) const
	{
		return (x < vector->x && y < vector->y);
	}

	bool operator >(const Vector2D* vector) const
	{
		return (x > vector->x && y > vector->y);
	}

	bool operator ==(const Vector2D& vector) const
	{
		if (this->x == vector.x && this->y == vector.y) {
			return true;
		}
		return false;
	}

	Vector2D operator /(float f) const
	{
		Vector2D vect;
		vect.x = this->x / f;
		vect.y = this->y / f;

		return vect;
	}

	Vector2D operator /(int f) const
	{
		Vector2D vect;
		vect.x = this->x / f;
		vect.y = this->y / f;

		return vect;
	}

	Vector2D operator /(double f) const
	{
		Vector2D vect;
		vect.x = this->x / f;
		vect.y = this->y / f;

		return vect;
	}

	Vector2D operator *(double f) const
	{
		Vector2D vect;
		vect.x = this->x / f;
		vect.y = this->y / f;

		return vect;
	}

	Vector2D& operator+=(const Vector2D& vector)
	{
		this->x += vector.x;
		this->y += vector.y;
		return *this;
	}

	Vector2D& operator-=(const Vector2D& vector)
	{
		this->x -= vector.x;
		this->y -= vector.y;
		return *this;
	}

	Vector2D operator *(const Vector2D& vector) const {
		Vector2D vec;
		vec.x = x * vector.x + x * vector.y;
		vec.y = y * vector.x + y * vector.y;
		return vec;
	}

	Vector2D operator*(double rhs)
	{
		Vector2D result = *this;
		result *= rhs;
		return result;
	}

	const Vector2D& operator*=(const double& rhs)
	{
		x *= rhs;
		y *= rhs;

		return *this;
	}

	Vector2D& operator*=(const Vector2D& vector)
	{

		this->x = x * vector.x + x * vector.y;
		this->y = y * vector.x + y * vector.y;
		return *this;
	}

	Vector2D operator +(const Vector2D& vector) const
	{
		Vector2D vec;
		vec.x = x + vector.x;
		vec.y = y + vector.y;
		return vec;
	}

	Vector2D operator - (const Vector2D& vector) const
	{
		Vector2D vec;
		vec.x = x - vector.x;
		vec.y = y - vector.y;
		return vec;
	}

	inline double Length() const
	{
		return sqrt(x*x + y*y);
	}

	inline double LengthSq() const
	{
		return (x*x + y*y);
	}

	inline double Distance(Vector2D& vector)const
	{
		double ySeperation = vector.y - y;
		double xSeperation = vector.x - x;
		return sqrt(ySeperation * ySeperation + xSeperation * xSeperation);
	}

	inline double DistanceSq(const Vector2D& vector)const
	{
		double ySeperation = vector.y - y;
		double xSeperation = vector.x - x;
		return ySeperation * ySeperation + xSeperation * xSeperation;
	}

	inline void Normalize()
	{
		double vector_lenght = this->Length();

		if (vector_lenght > std::numeric_limits<double>::epsilon())
		{
			this->x /= vector_lenght;
			this->y /= vector_lenght;
		}
	}

	inline Vector2D Perp()const
	{
		return Vector2D(-y, x);
	}

	const Vector2D& operator/=(const double& rhs)
	{
		x /= rhs;
		y /= rhs;

		return *this;
	}

	inline void Trunctate(double max)
	{
		if (this->Length() > max)
		{
			this->Normalize();

			*this = *this * max;
		}
	}

	inline double Dot(const Vector2D &v2)const
	{
		return x*v2.x + y*v2.y;
	}

	void print()
	{
		std::cout << "vector x: " << x << " vector y: " << y << std::endl;
	}
};

inline Vector2D NormalizeVector(const Vector2D &vec)
{
	Vector2D vector = vec;
	double vector_lenght = vector.Length();

	if (vector_lenght > std::numeric_limits<double>::epsilon())
	{
		vector.x /= vector_lenght;
		vector.y /= vector_lenght;
	}

	return vector;
}