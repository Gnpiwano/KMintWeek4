#pragma once
#include "BaseGameEntity.h"
class Vector;
class SteeringBehaviour;
class MovingEntity : public BaseGameEntity
{
public:
	MovingEntity();
	~MovingEntity();

	virtual void Update(float time_elapsed);
	Vector* Velocity;
	Vector* Heading;
	
	float Mass = 100;
	float MaxSpeed = 180;
	float MaxForce = 40;
	float MaxTurnRate;

	SteeringBehaviour* steeringbehaviour;

};

