#include "Rabbit.h"
#include "Vector.h"
#include "GameWorld.h"
#include "SteeringBehaviour.h"

Rabbit::Rabbit(Vector* Heading, Vector* Position, double Height, double Width, GameWorld* world)
{
	//this->Heading = Heading;
	//this->Position = Position;
	//this->Height = Height;
	//this->Width = Width;
	//this->steeringbehaviour = { new SteeringBehaviour(world, this) };
	//this->gameWorld = world;
	//this->gameWorld->addUnit(this);

	//Vector* vec{ new Vector(180 * 0.017, 140 * 0.017) };
	//this->Velocity = vec;
}


Rabbit::~Rabbit()
{
}

void Rabbit::update(float time_elapsed)
{
}
