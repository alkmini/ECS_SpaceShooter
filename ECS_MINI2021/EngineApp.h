#pragma once
#include <SDL.h>
#include "Time.h"
#include "World.h"

class EngineApp
{

public:

	EngineApp();
	~EngineApp();

	void Run();
	
private:

	SDL_Window* window;
	SDL_Renderer* renderer;

	bool isRunning;

	const Uint8* keyboard;

	Time applicationTime;
	World* world;

	bool InitSDL(const char* title, int width, int height, bool fullscreen);
	void HandleEvents();
	void Update();
	void InitWorld();
	void Clean();
};

