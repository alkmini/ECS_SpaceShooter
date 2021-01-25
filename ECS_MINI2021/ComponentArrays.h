#pragma once
#include <concepts>
#include "Components.h"
#include <memory>

class ComponentArrays
{
public:
	template<typename ComponentType, typename = std::enable_if_t<std::is_base_of_v<Component, ComponentType>>>
	ComponentType& GetComponent(int EntityID)
	{
		return GetComponentArray<ComponentType>()[EntityID];
	}

	template<typename ComponentType, typename = std::enable_if_t<std::is_base_of_v<Component, ComponentType>>>
	ComponentType* GetComponentArray()
	{
		static std::unique_ptr<ComponentType[]> componentArray(new ComponentType[MAX_ENTITIES]);
		return componentArray.get();
	}

};

