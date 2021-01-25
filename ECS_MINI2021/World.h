#pragma once
#include <SDL.h>
#include <iostream>
#include "ComponentHelper.h"
#include "Entity.h"
#include <vector>
#include <array>
#include "ComponentArrays.h"
#include "Systems.h"

class World
{
public:
	World(SDL_Renderer* renderer, SDL_Window* window, const Uint8* keyboard);
	~World();

	void Update();
	std::array<Entity, MAX_ENTITIES>& GetEntities();

	template<class ComponentType>
	ComponentType* GetComponentArray();

	template<class ComponentType>
	ComponentType* GetComponent(int EntityID);

	 template<class ...Components>
	 int CreateEntity();

	 void DestroyEntity(int entityID);

public:
	SDL_Renderer* renderer;
	SDL_Window* window;
	const Uint8* keyboard;

private:
	std::array<Entity, MAX_ENTITIES> entities;
	ComponentArrays componentArrays;
	std::vector<System*> systems;
	std::vector<int> availableEntityIDs;

};

template<class ComponentType>
inline ComponentType* World::GetComponentArray()
{
	return componentArrays.GetComponentArray<ComponentType>();
}

template<class ComponentType>
inline ComponentType* World::GetComponent(int EntityID)
{
	return &GetComponentArray<ComponentType>()[EntityID];
}

template<class ...Components>
inline int World::CreateEntity()
{
	int entityID = availableEntityIDs.back();
	availableEntityIDs.pop_back();

	entities[entityID].AddComponents<Components...>();
	return entityID;
}

