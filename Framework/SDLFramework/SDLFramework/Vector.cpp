#include "Vector.h"



Vector::Vector(float x, float y)
{
	this->x = x;
	this->y = y;
}


Vector::~Vector()
{
}

Vector* Vector::operator+(Vector& vec)
{
	Vector* vector = new Vector(this->x + vec.x, this->y + vec.y);
	return vector;
}

void Vector::operator=(Vector * vec)
{
	(*this).x = vec->x;
	(*this).y = vec->y;
	return;
}
