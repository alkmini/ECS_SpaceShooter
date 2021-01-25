#include "Components.h"
#include <SDL_image.h>
#include <cassert>
#include "World.h"

Component::Component()
{
	
}

Texture::~Texture()
{
	if (texture != nullptr)
	{
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
}

void Texture::SetTexture(World* worldContext, const char* filePath)
{
	if (texture != nullptr)
	{
		SDL_DestroyTexture(texture);
	}

	texture = IMG_LoadTexture(worldContext->renderer, filePath);
	assert(texture, "Image from path could not be loaded onto texture. ");

	int w;
	int h;
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);

	textureRect.w = w;
	textureRect.h = h;
	textureRect.x = 0;
	textureRect.y = 0;

}

Position::Position()
{
	x = 0;
	y = 0;
}

void Position::Set(float x, float y)
{
	this->x = x;
	this->y = y;
}
