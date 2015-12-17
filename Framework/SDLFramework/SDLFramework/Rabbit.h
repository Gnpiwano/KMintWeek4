#pragma once
#include "Unit.h"
class Vector;
class Rabbit : public Unit
{
public:
	Rabbit(Vector* Heading, Vector* Position, double Height, double Width, GameWorld* world);
	~Rabbit();

	void update(float time_elapsed);
};

