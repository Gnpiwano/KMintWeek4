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

Context::Context()
{
	gameWorld = { new GameWorld() };
	drawScreen = { new DrawScreen(this, gameWorld) };
	application = { new FWApplication() };

	// Context loaded start Application for this situation. 
	startApplication();
}


Context::~Context()
{
}

int Context::startApplication()
{
	//auto window = Window::CreateSDLWindow();
	if (!application->GetWindow())
	{
		LOG("Couldn't create window...");
		return EXIT_FAILURE;
	}

	application->SetTargetFPS(60);
	application->SetColor(Color(180, 180, 180, 255));

	//while (true){}
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
					
					Unit* cow{ new Cow(new Vector(event.motion.x, event.motion.y), new Vector(event.motion.x, event.motion.y), 20, 20, gameWorld) };
				}
				else if (event.button.button == SDL_BUTTON_RIGHT) {
					
					Unit* rabbit{ new Rabbit(new Vector(event.motion.x, event.motion.y), new Vector(event.motion.x, event.motion.y), 20, 20, gameWorld) };
				}
				break;
			}
		}

		//Method for drawing everything. 
		drawScreen->Draw(application);
		gameWorld->update(0.017f);
		application->EndTick();
	}

	return EXIT_SUCCESS;
}
