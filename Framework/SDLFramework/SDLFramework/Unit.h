#pragma once
#include "MovingEntity.hpp"

class GameWorld;
class SteeringBehaviour;

class Unit : public MovingEntity
{
public:
	Unit();
	~Unit();

	virtual void update(float time_elapsed) {};

protected:
	SteeringBehaviour* steeringBehaviour;
	GameWorld* gameWorld;
};

