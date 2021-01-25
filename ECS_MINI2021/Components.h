#pragma once
#include <SDL.h>

class World;

class Component
{
public:
	Component();
};

class Texture : Component
{
public:
	~Texture();

	SDL_Texture* texture = nullptr;
	SDL_Rect textureRect;
	void SetTexture(World* worldContext, const char* filePath);
};

class Position : Component
{
public:
	Position();

	void Set(float x, float y);

	float x;
	float y;
};
