#include "SteeringBehaviour.h"
#include "GameWorld.h"
#include "Unit.h"


SteeringBehaviour::SteeringBehaviour(GameWorld* world, Unit* unit)
{
	this->gameWorld = world;
	this->unit = unit;
}


SteeringBehaviour::~SteeringBehaviour()
{
}

Vector * SteeringBehaviour::calculate()
{
	return new Vector(1, 1);
}

Vector * SteeringBehaviour::Seek(Vector * vec)
{
	return nullptr;
}

Vector * SteeringBehaviour::Flee(Vector * vec)
{
	return nullptr;
}

Vector * SteeringBehaviour::Arrive(Vector * vec)
{
	return nullptr;
}

