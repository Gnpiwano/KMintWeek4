#include "CowEntity.h"
#include "SteeringBehaviours.h"
#include "GameWorld.h"
#include <random>
CowEntity::CowEntity(GameWorld* world) :MovingEntity(world)
{
	srand(time(NULL));

	int cow = world->getCowList().size() + 1;

	std::string location = "";
	
	location = location + "cow-1.png";

	this->SetTexture(mApplication->LoadTexture(location));

	this->setSteering(new SteeringBehaviors{ this });
	this->setStateid(1);
	this->setMaxSpeed(100);
	this->setMass(.4f);
	mApplication->AddRenderable(this);
	world->addCowToCowList(this);
	this->SetTarget(world->getRabbit());
}

CowEntity::~CowEntity()
{
}

void CowEntity::Update(float deltaTime)
{
	MovingEntity::Update(deltaTime);
}