#include "MovingEntity.hpp"
#include "GameWorld.h"
#include "SteeringBehaviours.h"
//#include <SDL.h>

MovingEntity::MovingEntity(GameWorld* gameworld) {
	this->gameWorld = gameworld;
}
MovingEntity::~MovingEntity() {

}

void MovingEntity::Update(float deltaTime)
{


	TagNeighbors(120);
	m_dTimeElapsed = deltaTime;

	Vector2D steeringforce = getSteering()->Calculate(); //Hiet moet nog een goed getal komen : D

	Vector2D acceleration = steeringforce / getMass();

	velocity += acceleration * deltaTime;

	velocity.Trunctate(maxSpeed);

	postion += velocity * deltaTime;

	if (velocity.LenghtSq() > 0.00000001)
	{
		heading = NormalizeVector(velocity);

		side = heading.Perp();
	}

	if (getSteering()->EntityIsInSpace())
	{
		this->gameWorld->UpdateEntity(this);
	}

	EnforceNonPenetrationConstraint();


	//WrapAround(this->postion, SDL_GetWindowSurface(this->mApplication->GetWindow())->w, SDL_GetWindowSurface(this->mApplication->GetWindow())->h);
}

void MovingEntity::Draw()
{
	mApplication->DrawTexture(this->GetTexture(), this->getPostion().getX(), this->getPostion().getY(), 50, 50);
}

MovingEntity* MovingEntity::getClosestTarget() {

	std::vector<CowEntity*>::iterator it;
	std::vector<CowEntity*> collection = gameWorld->getCowList();


	for (std::vector<CowEntity*>::iterator it = collection.begin(); it != collection.end(); ++it) {
		/* std::cout << *it; ... */
		if (this->target == nullptr) {
			this->target = (*it);
		}
		else if (getPostion().DistanceSq((*it)->getPostion()) < getPostion().DistanceSq(target->getPostion())) {
			this->target = (*it);
		}
	}
	return this->target;
}


void MovingEntity::TagNeighbors(double radius)
{

	std::vector<CowEntity*>::iterator it;
	std::vector<CowEntity*> collection = gameWorld->getCowList();

	for (std::vector<CowEntity*>::iterator it = collection.begin(); it != collection.end(); ++it) {
		//first clear any current tag
		(*it)->UnTag();
		Vector2D to = (*it)->getPostion() - this->getPostion();
		//the bounding radius of the other is taken into account by adding it
		//to the range
		double range = radius + (*it)->getBRadius();
		//if entity within range, tag for further consideration. (working in
		//distance-squared space to avoid sqrts)
		if (((*it) != this) && (to.LengthSq() < range*range))
		{
			(*it)->Tag();
		}
	}//next entity

}

void MovingEntity::EnforceNonPenetrationConstraint()
{
	if (!dynamic_cast<CowEntity*>(this)) { return; }
	//iterate through all entities checking for any overlap of bounding radii
	std::vector<CowEntity*>::iterator it;
	std::vector<CowEntity*> collection = gameWorld->getCowList();

	for (std::vector<CowEntity*>::iterator it = collection.begin(); it != collection.end(); ++it) {
		//make sure we don't check against the individual
		if (*it == this) continue;
		//calculate the distance between the positions of the entities
		Vector2D ToEntity = this->getPostion() - (*it)->getPostion();
		double DistFromEachOther = ToEntity.Length();
		//if this distance is smaller than the sum of their radii then this
		//entity must be moved away in the direction parallel to the
		//ToEntity vector
		double AmountOfOverLap = (*it)->getBRadius() + this->getBRadius() -
			DistFromEachOther;
		if (AmountOfOverLap >= 0)
		{
			//move the entity a distance away equivalent to the amount of overlap.
			this->setPosition(this->getPostion() + (ToEntity / DistFromEachOther) *
				AmountOfOverLap);
		}
	}//next entity
}