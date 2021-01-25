#pragma once
#include "ECS_Utilities.h"
#include <bitset>
#include "ComponentHelper.h"

class Entity
{
private:
	std::bitset<MAX_COMPONENTS> components;

public:
	template<class ComponentType>
	inline bool HasComponent() const
	{
		return components.test(ComponentHelper::GetComponentID< ComponentType >());
	}

	template<class... ComponentTypes>
	inline bool HasComponents() const
	{
		std::bitset<MAX_COMPONENTS> compareMask;
		(compareMask.set(ComponentHelper::GetComponentID<ComponentTypes>()), ...);
		return (components & compareMask) == compareMask;
	}

	inline bool HasComponents(std::bitset<MAX_COMPONENTS> compareMask) const
	{
		return (components & compareMask) == compareMask;
	}

	template<class ComponentType>
	inline void AddComponent()
	{
		components.set(ComponentHelper::GetComponentID<ComponentType>(), true);
	}

	template<class ...ComponentTypes>
	inline void AddComponents()
	{
		(components.set(ComponentHelper::GetComponentID<ComponentTypes>(), true), ...);
	}

	template<class ComponentType>
	inline void RemoveComponent()
	{
		components.set(ComponentHelper::GetComponentID<ComponentType>(), false);
	}

	template<class ...ComponentTypes>
	inline void RemoveComponents()
	{
		(components.set(ComponentHelper::GetComponentID<ComponentTypes>(), false), ...);
	}

	inline void RemoveAllComponents()
	{
		components.reset();
	}
};

