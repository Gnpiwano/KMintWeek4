#include "Context.h"
#include "GameWorld.h"
#include "DrawScreen.h"
#include "FWApplication.h"
#include "Config.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include "Cow.h"
#include "Rabbit.h"
#include "Vector.h"
#include "RabbitEntity.h"
#include "SteeringBehaviours.h"

Context::Context()
{
	application = { new FWApplication() };
	gameWorld = { new GameWorld() };

	rabbit = new RabbitEntity(gameWorld);
	startApplication();
}

Context::~Context()
{
}

int Context::startApplication()
{
	if (!application->GetWindow())
	{
		LOG("Couldn't create window...");
		return EXIT_FAILURE;
	}

	application->SetTargetFPS(60);
	application->SetColor(Color(180, 180, 180, 255));

	CowEntity* cow = new  CowEntity(gameWorld);

	rabbit->SetTarget(cow);
	rabbit->setStateid(3);
	rabbit->setSteering(new SteeringBehaviors{ rabbit });
	application->AddRenderable(rabbit);

	while (application->IsRunning())
	{
		application->StartTick();
		application->SetColor(Color(180, 180, 180, 255));
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				application->Quit();
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {

				default:
					break;
				}
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button == SDL_BUTTON_LEFT) {
					
					CowEntity* cow = new  CowEntity(gameWorld);
					cow->setPosition(Vector2D(event.motion.x, event.motion.y));
				}
				else if (event.button.button == SDL_BUTTON_RIGHT) {
					rabbit->setPosition(Vector2D(event.motion.x, event.motion.y));
				}
				break;
			}
		}

		application->UpdateGameObjects();
		application->RenderGameObjects();
		application->EndTick();
	}

	return EXIT_SUCCESS;
}

context::context()
{
}


context::~context()
{
}
