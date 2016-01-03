#include "SteeringBehaviours.h"
#include "MovingEntity.hpp"
#include "CowEntity.h"
#include "SDL.h"
#include "GameWorld.h"


Vector2D SteeringBehaviors::Calculate()
{
	switch (owner->getStateId())
	{
	case 1: {
		Vector2D vec{ 0, 0 };
		vec += this->Pursuit() * 3;
		vec.Trunctate(20);
		return vec;
	}
			break;
	case 2:
		return this->Wander();

		break;
	case 3:
		return this->Flee();
		break;
	default:
		break;
	}

	Vector2D vector{ 1, 1 };
	return vector;
}

Vector2D SteeringBehaviors::Seek(const Vector2D& TargetPos)
{
	Vector2D DesiredVelocity = NormalizeVector(TargetPos - owner->getPostion()) * owner->getMaxSpeed();
	return (DesiredVelocity - owner->getVelocity());
}

Vector2D SteeringBehaviors::Pursuit()
{
	Vector2D ToEvader = owner->getTarget()->getPostion() - owner->getPostion();
	double RelativeHeading = owner->getHeading().Dot(owner->getTarget()->getHeading());
	if ((ToEvader.Dot(owner->getHeading()) > 0) &&
		(RelativeHeading < -0.95))
	{
		return Seek(owner->getTarget()->getPostion());
	}

	double LookAheadTime = ToEvader.Length() /
		(owner->getMaxSpeed() + owner->getTarget()->getSpeed());

	return Seek(owner->getTarget()->getPostion() + owner->getTarget()->getVelocity() * LookAheadTime);
}

Vector2D SteeringBehaviors::Flee()
{
	owner->setMaxSpeed(125);
	Vector2D TargetPos = owner->getClosestTarget()->getPostion();

	if (owner->getPostion().DistanceSq(TargetPos) > owner->safeDistanceSq)
	{
		owner->setMaxSpeed(75);
		owner->setStateid(2);
		return Vector2D(0, 0);
	}

	Vector2D DesiredVelocity = NormalizeVector(owner->getPostion() - TargetPos) * (owner->getMaxSpeed());
	return (DesiredVelocity - owner->getVelocity());
}

bool SteeringBehaviors::EntityIsInSpace() {
	float xCor = owner->getPostion().getX();
	float yCor = owner->getPostion().getY();
	int screenX = 800;
	int screenY = 600;

	if (xCor > screenX + 25 || xCor < -25 || yCor > screenY + 25 || yCor < -25) {
		return true;
	}

	return false;
}

Vector2D SteeringBehaviors::Wander()
{
	Vector2D TargetPos = owner->getClosestTarget()->getPostion();
	if (owner->getPostion().DistanceSq(TargetPos) < owner->PanicDistanceSq)
	{
		owner->setStateid(3);
	}
	m_vWanderTarget += Vector2D(RandomClamped() * m_dWanderJitter,
		RandomClamped() * m_dWanderJitter);

	m_vWanderTarget = NormalizeVector(m_vWanderTarget);

	m_vWanderTarget *= m_dWanderRadius;

	Vector2D Target = PointToWorldSpace(m_vWanderTarget,
		owner->getHeading(),
		owner->getSide(),
		owner->getPostion());

	return m_vWanderTarget - owner->getPostion();
}