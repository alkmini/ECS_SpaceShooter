#pragma once
#include <type_traits>
#include <concepts>
#include "Components.h"

class ComponentHelper
{
private:

	inline static int counter = 0;

public:

	template<class ComponentType, typename = std::enable_if_t<std::is_base_of_v<Component, ComponentType>>>
	static int GetComponentID()
	{
		static int id = counter++;
		return id;
	}
};