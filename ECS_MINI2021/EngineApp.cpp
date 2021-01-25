#include <iostream>
#include "EngineApp.h"
#include <SDL_image.h>

EngineApp::EngineApp()
{

}

EngineApp::~EngineApp()
{
	delete world;
}

void EngineApp::Update()
{
	applicationTime.Update();
	world->Update();
}

bool EngineApp::InitSDL(const char* title, int width, int height, bool fullscreen)
{
	Uint32 flags = SDL_WINDOW_SHOWN;
	if (fullscreen)
	{
		flags |= SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		if (!(window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags)))
		{
			std::cout << "Error. Window could not be created." << std::endl;
			return false;
		}

		if (!(renderer = SDL_CreateRenderer(window, -1, 0)))
		{
			std::cout << "Error. Renderer could not be created." << std::endl;
			return false;
		}

		SDL_SetRenderDrawColor(renderer, 120, 0, 120, 1);

		isRunning = true;
		return true;
	}
	else
	{
		isRunning = false;
		std::cout << "Error. Could not initialize SDL. "<< std::endl;
		return false;
	}
}

void EngineApp::HandleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT)
	{
		isRunning = false;
		return;
	}

	SDL_PumpEvents();
	keyboard = SDL_GetKeyboardState(NULL);
}

void EngineApp::Run()
{
	if (!InitSDL("Space Shooter!", 800, 600, false))
	{
		return;
	}
	SDL_Delay(300);

	HandleEvents();

	InitWorld();

	while (isRunning)
	{
		HandleEvents();
		Update();
	}

	Clean();
}

void EngineApp::InitWorld()
{
	world = new World(renderer, window, keyboard);
}

void EngineApp::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
