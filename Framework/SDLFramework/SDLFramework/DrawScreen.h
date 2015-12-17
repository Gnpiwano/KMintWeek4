#pragma once
class Context;
class FWApplication;
class GameWorld;
class DrawScreen
{
public:
	DrawScreen(Context * con, GameWorld* world);
	~DrawScreen();
	
	void Draw(FWApplication* application);

private:
	Context * context;
	GameWorld* gameWorld;
};

