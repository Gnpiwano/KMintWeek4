#pragma once
#include "Vector.h"
class FWApplication;
class BaseGameEntity
{
public:
	BaseGameEntity();
	~BaseGameEntity();

	int ID;
	Vector* getPosition() { return Position; }
	void addVelocityToPosition(Vector* vec) { Position = *Position + *vec;}

	double Height;
	double Width;

	virtual void Update(float time_elapsed);

protected:
	Vector* Position;
	FWApplication* mApplication;
};

