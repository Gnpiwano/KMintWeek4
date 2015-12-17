#pragma once
#include "BaseVector.h"
class Vector : public BaseVector
{
public:
	Vector(float x, float y);
	~Vector();

	Vector* operator+(Vector& vec);
	void operator=(Vector* vec);
};

