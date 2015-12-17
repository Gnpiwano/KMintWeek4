#pragma once
#include "Vector.h"
#include <vector>
class ArriveBehaviour;
class FleeBehaviour;
class SeekBehaviour;
class GameWorld;
class Unit;
class SteeringBehaviour
{
public:
	SteeringBehaviour(GameWorld* world, Unit* unit);
	~SteeringBehaviour();

	Vector* Target;
	Unit* unit;
	bool SeekOff;
	bool FleeOff;
	bool ArriveOff;

	Vector* calculate();

private:
	ArriveBehaviour* arriveBehaviour;
	FleeBehaviour* fleeBehaviour;
	SeekBehaviour* seekBehaviour;

	Vector* Seek(Vector* vec);
	Vector* Flee(Vector* vec);
	Vector* Arrive(Vector* vec);

	GameWorld* gameWorld;
};

