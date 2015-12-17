#pragma once
#include "Unit.h"
class Vector;
class GameWorld;
class Cow : public Unit
{
public:
	Cow(Vector* Heading, Vector* Position, double Height, double Width, GameWorld* world);
	~Cow();

	void update(float time_elapsed);

};

