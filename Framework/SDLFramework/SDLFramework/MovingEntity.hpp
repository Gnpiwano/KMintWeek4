#pragma once
#include "IGameObject.h"
#include <stdio.h>
#include "Vector2D.h"

class SteeringBehaviors;
class GameWorld;

class MovingEntity : public IGameObject {
protected:
	int id;
	bool isTagged = false;
	SteeringBehaviors* steering;
	GameWorld* gameWorld;

	Vector2D postion;
	Vector2D velocity;
	Vector2D heading;
	Vector2D side;

	float mass;
	float maxSpeed;
	float maxForce;

	MovingEntity* target;
	double m_dTimeElapsed;
	int stateId = 0;

public:

	MovingEntity(GameWorld* gameworld);
	~MovingEntity();

	const double PanicDistanceSq = 100.0 * 100.0;
	const double safeDistanceSq = 250.0 * 200.0;

	virtual void Update(float deltatime);
	void Draw();

	void setId(int id) { this->id = id; }
	void setSteering(SteeringBehaviors* steering) { this->steering = steering; }
	void setPosition(const Vector2D& postion) { this->postion = postion; }
	void setVelocity(Vector2D& velocity) { this->velocity = velocity; }
	void setHeading(Vector2D& heading) { this->heading = heading; }
	void setMass(float mass) { this->mass = mass; }
	void setMaxForce(float maxForce) { this->maxForce = maxForce; }
	void setMaxSpeed(float maxSpeed) { this->maxSpeed = maxSpeed; }
	void SetTarget(MovingEntity* entity) { this->target = entity; };
	void setStateid(int stateId) { this->stateId = stateId; }

	int getId() { return this->id; }
	double getSpeed()const { return velocity.Length(); }
	SteeringBehaviors* getSteering() { return steering; }
	Vector2D getPostion() { return this->postion; }
	Vector2D getHeading() { return this->heading; }
	Vector2D getVelocity() { return this->velocity; }
	Vector2D getSide() { return this->side; }
	float getMass() { return this->mass; }
	float getMaxForce() { return this->maxForce; }
	float getMaxSpeed() { return this->maxSpeed; }
	MovingEntity* getTarget() { return target; }
	int getStateId() { return this->stateId; }
	FWApplication* getApplication() { return this->mApplication; }
	MovingEntity* getClosestTarget();
	double TimeElapsed()const { return m_dTimeElapsed; }
	GameWorld* getWorld() { return this->gameWorld; }

	void TagNeighbors(double radius);
	void Tag() { this->isTagged = true; }
	void UnTag() { this->isTagged = false; }
	bool getTagged() { return this->isTagged; }

	double getBRadius() { return 25;}
	void EnforceNonPenetrationConstraint();
};
