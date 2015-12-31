#pragma once
#include "MovingEntity.hpp"

class GameWorld;
class CowEntity : public MovingEntity
{
public:
	CowEntity(GameWorld* world);
	~CowEntity();
	virtual void Update(float deltatime);

};

