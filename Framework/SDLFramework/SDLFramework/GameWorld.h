#pragma once
#include <stdio.h>
#include "MovingEntity.hpp"
#include "CowEntity.h"
#include <vector>

class GameWorld {

private:
	std::vector<CowEntity*> cowList;
	MovingEntity* rabbit;
public:
	GameWorld();
	~GameWorld();
	std::vector<CowEntity*> getCowList() { return this->cowList; };
	void UpdateEntity(MovingEntity* entity);
	void setCowList(std::vector<CowEntity*> cowList) { this->cowList = cowList; };
	void addCowToCowList(CowEntity* cow) { this->cowList.push_back(cow); };
	void setRabbit(MovingEntity* rabbit) { this->rabbit = rabbit; }
	MovingEntity* getRabbit() { return rabbit; }
};
