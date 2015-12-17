#pragma once
#include <vector>
#include "Unit.h"
class GameWorld
{
public:
	GameWorld();
	~GameWorld();

	void update(double time_elapsed);
	void addUnit(Unit* entity) { entitys.push_back(entity); };
	std::vector<Unit*> getUnits() { return entitys; };

private:
	std::vector<Unit*> entitys;
};

