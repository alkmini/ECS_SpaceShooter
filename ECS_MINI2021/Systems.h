#pragma once
#include <bitset>
#include "ECS_Utilities.h"
#include "ComponentHelper.h"

class World;

class System
{
public:
	virtual void ApplyLogic(World* worldContext) {};

protected:
	template<class ...RequiredComponents>
	void SetMask();
	std::bitset<MAX_COMPONENTS> componentMask;

};

template<class ...RequiredComponents>
inline void System::SetMask()
{
	(componentMask.set(ComponentHelper::GetComponentID<RequiredComponents>()), ...);
}

class Render : public System
{
public:
	Render();

	void ApplyLogic(World* worldContext) override;
};

