#include "DrawScreen.h"
#include "Config.h"
#include "FWApplication.h"
#include "GameWorld.h"
#include "Vector.h"


DrawScreen::DrawScreen(Context * con, GameWorld* world)
{
	this->context = con;
	this->gameWorld = world;
}


DrawScreen::~DrawScreen()
{
}

void DrawScreen::Draw(FWApplication * application)
{
	application->SetColor(Color(0, 180, 0, 255));
	for (int i = 0; i < gameWorld->getUnits().size(); i++) {
		application->DrawRect(gameWorld->getUnits().at(i)->getPosition()->x, gameWorld->getUnits().at(i)->getPosition()->y, 32, 32, true);
	}
	application->SetColor(Color(180, 180, 180, 255));
}



