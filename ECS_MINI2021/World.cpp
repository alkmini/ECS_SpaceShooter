#include "World.h"
#include "Components.h"

World::World(SDL_Renderer* renderer, SDL_Window* window, const Uint8* keyboard)
{
	this->renderer = renderer;
	this->window = window;
	this->keyboard = keyboard;
	for (int i = 0; i < MAX_ENTITIES; i++)
	{
		availableEntityIDs.push_back(i);
	}

	systems.push_back(new Render());
	int id = CreateEntity<Texture, Position>();
	GetComponent<Texture>(id)->SetTexture(this, "Assets/SpacePlayer.png");
}

World::~World()
{
	for (System* s : systems)
	{
		delete s;
	}
}

void World::Update()
{
	for (System* s : systems)
	{
		s->ApplyLogic(this);
	}
}

std::array<Entity, MAX_ENTITIES>& World::GetEntities()
{
	return entities;
}

void World::DestroyEntity(int entityID)
{
	GetEntities()[entityID].RemoveAllComponents();
	availableEntityIDs.push_back(entityID);
}

