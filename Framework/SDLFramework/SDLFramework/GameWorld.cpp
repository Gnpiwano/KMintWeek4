#include "GameWorld.h"



GameWorld::GameWorld()
{
}


GameWorld::~GameWorld()
{
}

void GameWorld::update(double time_elapsed)
{
	for (int i = 0; i < entitys.size(); i++) {
		entitys.at(i)->update(time_elapsed);
	}
}
