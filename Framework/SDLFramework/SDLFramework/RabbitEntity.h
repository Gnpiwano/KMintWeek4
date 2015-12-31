#pragma once
#include "MovingEntity.hpp"

class GameWorld;

class RabbitEntity : public MovingEntity
{
public:
	RabbitEntity(GameWorld* world);
	~RabbitEntity();
	virtual void Update(double deltatime);
};

