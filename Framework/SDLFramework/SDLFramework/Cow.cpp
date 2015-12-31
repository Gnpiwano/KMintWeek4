#include "Cow.h"
#include "Vector.h"
#include <iostream>
#include "SteeringBehaviour.h"
#include "GameWorld.h"
Cow::Cow(Vector* Heading, Vector* Position, double Height, double Width, GameWorld* world)
{
	//this->Heading = Heading;
	//this->Position = Position;
	//this->Height = Height;
	//this->Width = Width;
	//this->steeringbehaviour = { new SteeringBehaviour(world, this) };
	//this->gameWorld = world;
	//this->gameWorld->addUnit(this);
	//
	//Vector* vec{ new Vector(180 * 0.017, 140 * 0.017) };
	//this->Velocity = vec;
}


Cow::~Cow()
{
}

void Cow::update(float time_elapsed)
{
	//this->addVelocityToPosition(this->steeringbehaviour->calculate());
}
