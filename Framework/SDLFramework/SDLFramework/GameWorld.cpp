#include "GameWorld.h"
#include "SDL.h"

GameWorld::GameWorld() {

}
GameWorld::~GameWorld() {

}

void GameWorld::UpdateEntity(MovingEntity * entity)
{
	float xCor = entity->getPostion().getX();
	float yCor = entity->getPostion().getY();
	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);
	int screenX = 800;
	int screenY = 600;

	if (xCor > screenX + 25) {
		//Rechts uit beeld
		entity->setPosition(Vector2D{ -25,yCor });
	}
	if (xCor < -25) {
		//Links uit beeld
		entity->setPosition(Vector2D{ static_cast<float>(screenX + 25),yCor });
	}
	if (yCor > screenY + 25) {
		//Onder uit beeld
		entity->setPosition(Vector2D{ xCor,-25 });
	}
	if (yCor < -25) {
		//Boven uit beeld
		entity->setPosition(Vector2D{ xCor,static_cast<float>(screenY + 25) });
	}
}
