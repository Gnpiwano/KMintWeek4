#pragma once
class DrawScreen;
class GameWorld;
class FWApplication;
class Context
{
public:
	Context();
	~Context();

	GameWorld* gameWorld;
	DrawScreen* drawScreen;

	int startApplication();

private:
	FWApplication* application;

};

