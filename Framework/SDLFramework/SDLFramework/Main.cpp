#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include "SDL_events.h"
#include "SDL_timer.h"
#include <time.h>
#include "CowEntity.h"
#include "RabbitEntity.h"
#include "SteeringBehaviours.h"
#include "GameWorld.h"
#include "Context.h"

int main()
{
	Context* con{ new Context() };
	////auto window = Window::CreateSDLWindow();
	//auto application = new FWApplication();
	//if (!application->GetWindow())
	//{
	//	LOG("Couldn't create window...");
	//	return EXIT_FAILURE;
	//}

	//application->SetTargetFPS(60);
	//application->SetColor(Color(255, 10, 40, 255));

	//GameWorld* world = new GameWorld();
	//RabbitEntity* rabbit = new RabbitEntity(world);

	//CowEntity* cow = new  CowEntity(world);
	//CowEntity* cow2 = new  CowEntity(world);
	//CowEntity* cow3 = new  CowEntity(world);
	//CowEntity* cow4 = new  CowEntity(world);
	//CowEntity* cow5 = new  CowEntity(world);
	//CowEntity* cow6 = new  CowEntity(world);
	//CowEntity* cow7 = new  CowEntity(world);
	//CowEntity* cow8 = new  CowEntity(world);
	//CowEntity* cow9 = new  CowEntity(world);
	//CowEntity* cow10 = new  CowEntity(world);
	//cow->setPosition(Vector2D(50, 50));
	//cow2->setPosition(Vector2D(200, 50));
	//cow3->setPosition(Vector2D(50, 300));
	//cow4->setPosition(Vector2D(400, 300));
	//cow5->setPosition(Vector2D(600, 600));
	//cow6->setPosition(Vector2D(150, 350));
	//cow7->setPosition(Vector2D(250, 550));
	//cow8->setPosition(Vector2D(230, 90));
	//cow9->setPosition(Vector2D(487, 98));
	//cow10->setPosition(Vector2D(600, 259));

	//application->AddRenderable(rabbit);

	////rabbit->SetTarget(cow);
	//rabbit->setStateid(3);
	//rabbit->setSteering(new SteeringBehaviors{ rabbit });
	//while (application->IsRunning())
	//{
	//	application->StartTick();

	//	SDL_Event event;
	//	while (SDL_PollEvent(&event))
	//	{
	//		switch (event.type)
	//		{
	//		case SDL_QUIT:
	//			application->Quit();
	//			break;
	//		case SDL_KEYDOWN:
	//			switch (event.key.keysym.sym) {
	//			case SDLK_SPACE: {
	//				if (world->getCowList().size() < 146) {
	//					CowEntity* scow = new  CowEntity(world);
	//					scow->setPosition(Vector2D(50, 50));
	//				}}
	//							 break;
	//			default:
	//				break;
	//			}
	//		}
	//	}
	//	application->UpdateGameObjects();
	//	application->RenderGameObjects();
	//	application->EndTick();

	//	application->SetColor(Color(255, 255, 255, 255));

	//}

	//return EXIT_SUCCESS;
}