#pragma once
class DrawScreen;
class GameWorld;
class FWApplication;
class RabbitEntity;
class Context
{
public:
	Context();
	~Context();

	GameWorld* gameWorld;
	//DrawScreen* drawScreen;

	int startApplication();

private:
	FWApplication* application;
	RabbitEntity* rabbit;
};

class context
{
public:
	context();
	~context();
};

