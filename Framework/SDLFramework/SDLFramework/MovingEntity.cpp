#include "MovingEntity.hpp"
#include "GameWorld.h"
#include "SteeringBehaviours.h"

MovingEntity::MovingEntity(GameWorld* gameworld) {
	this->gameWorld = gameworld;
}
MovingEntity::~MovingEntity() {

}

void MovingEntity::Update(float deltaTime)
{
	TagNeighbors(120);
	m_dTimeElapsed = deltaTime;

	Vector2D steeringforce = getSteering()->Calculate();

	Vector2D acceleration = steeringforce / getMass();

	velocity += acceleration * deltaTime;

	velocity.Trunctate(maxSpeed);

	postion += velocity * deltaTime;

	if (velocity.LengthSq() > 0.00000001)
	{
		heading = NormalizeVector(velocity);

		side = heading.Perp();
	}

	if (getSteering()->EntityIsInSpace())
	{
		this->gameWorld->UpdateEntity(this);
	}

	EnforceNonPenetrationConstraint();
}

void MovingEntity::Draw()
{
	mApplication->DrawTexture(this->GetTexture(), this->getPostion().getX(), this->getPostion().getY(), 50, 50);
}

MovingEntity* MovingEntity::getClosestTarget() {

	std::vector<CowEntity*>::iterator it;
	std::vector<CowEntity*> collection = gameWorld->getCowList();


	for (std::vector<CowEntity*>::iterator it = collection.begin(); it != collection.end(); ++it) {
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
		(*it)->UnTag();
		Vector2D to = (*it)->getPostion() - this->getPostion();
		double range = radius + (*it)->getBRadius();
		if (((*it) != this) && (to.LengthSq() < range*range))
		{
			(*it)->Tag();
		}
	}
}

void MovingEntity::EnforceNonPenetrationConstraint()
{
	if (!dynamic_cast<CowEntity*>(this)) { return; }
	std::vector<CowEntity*>::iterator it;
	std::vector<CowEntity*> collection = gameWorld->getCowList();

	for (std::vector<CowEntity*>::iterator it = collection.begin(); it != collection.end(); ++it) {
		if (*it == this) continue;
		Vector2D ToEntity = this->getPostion() - (*it)->getPostion();
		double DistFromEachOther = ToEntity.Length();
		double AmountOfOverLap = (*it)->getBRadius() + this->getBRadius() -
			DistFromEachOther;
		if (AmountOfOverLap >= 0)
		{
			this->setPosition(this->getPostion() + (ToEntity / DistFromEachOther) *
				AmountOfOverLap);
		}
	}
}