#include "RabbitEntity.h"
#include "GameWorld.h"

RabbitEntity::RabbitEntity(GameWorld* world) :MovingEntity(world)
{
#ifdef __APPLE__
	this->SetTexture(mApplication->LoadTexture("/Users/bryansijs/Documents/C++/KMINT/KMINT/Framework/SDLFramework/Resources/haas.png"));
#else
	this->SetTexture(mApplication->LoadTexture("rabbit-2.png"));
#endif
	this->setPosition(Vector2D{ 600,300 });
	this->setMaxSpeed(800);
	this->setMass(0.05f);
	world->setRabbit(this);
}


RabbitEntity::~RabbitEntity()
{
}


void RabbitEntity::Update(double deltaTime)
{

}