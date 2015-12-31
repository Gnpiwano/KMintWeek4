#pragma once
#include "Vector2D.h"
#include "Utils.h"
#include "Transformations.h"
#include <math.h>
class MovingEntity;
class SteeringBehaviors
{
private:
	MovingEntity* owner;



	//the current position on the wander circle the agent is
	//attempting to steer towards
	Vector2D     m_vWanderTarget;

	//explained above
	double        m_dWanderJitter;
	double        m_dWanderRadius;
	double        m_dWanderDistance;


public:
	SteeringBehaviors(MovingEntity* owner) {
		this->owner = owner;

		m_dWanderDistance = 1;
		m_dWanderJitter = 360;
		m_dWanderRadius = 360;


		double theta = RandFloat() * (2 * 3.14);

		//create a vector to a target position on the wander circle
		m_vWanderTarget = Vector2D(m_dWanderRadius * cos(theta),
			m_dWanderRadius * sin(theta));


	}

	Vector2D Calculate();

	Vector2D Seek(const Vector2D& vector);
	Vector2D Pursuit();
	Vector2D Flee();
	Vector2D Wander();
	//Vector2D NotCollide();
	//Vector2D KeepClose();
	//Vector2D Separation();
	//Vector2D Cohesion();
	bool EntityIsInSpace();
};

