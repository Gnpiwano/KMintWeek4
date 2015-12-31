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
		(RelativeHeading < -0.95))  //acos(0.95)=18 degs
	{
		return Seek(owner->getTarget()->getPostion());
	}
	//Not considered ahead so we predict where the evader will be.
	//the look-ahead time is proportional to the distance between the evader
	//and the pursuer; and is inversely proportional to the sum of the
	//agents' velocities
	double LookAheadTime = ToEvader.Length() /
		(owner->getMaxSpeed() + owner->getTarget()->getSpeed());
	//now seek to the predicted future position of the evader
	return Seek(owner->getTarget()->getPostion() + owner->getTarget()->getVelocity() * LookAheadTime);
}

Vector2D SteeringBehaviors::Flee()
{
	owner->setMaxSpeed(125);
	Vector2D TargetPos = owner->getClosestTarget()->getPostion();
	//only flee if the target is within 'panic distance'. Work in distance //squared space.

	if (owner->getPostion().DistanceSq(TargetPos) > owner->safeDistanceSq)
	{
		// safe
		owner->setMaxSpeed(75);
		owner->setStateid(2);
		return Vector2D(0, 0);
	}
	//in danger
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
		//in danger
		owner->setStateid(3);
	}
	m_vWanderTarget += Vector2D(RandomClamped() * m_dWanderJitter,
		RandomClamped() * m_dWanderJitter);


	//reproject this new vector back on to a unit circle
	m_vWanderTarget = NormalizeVector(m_vWanderTarget);

	//increase the length of the vector to the same as the radius
	//of the wander circle
	m_vWanderTarget *= m_dWanderRadius;

	//move the target into a position WanderDist in front of the agent
	//Vector2D target = m_vWanderTarget + Vector2D(m_dWanderDistance, 0);

	//project the target into world space
	Vector2D Target = PointToWorldSpace(m_vWanderTarget,
		owner->getHeading(),
		owner->getSide(),
		owner->getPostion());


	//and steer towards it
	return m_vWanderTarget - owner->getPostion();
}