#pragma once
#include "PhysicsComponent.h"
class PlayerPhysicsComponent : PhysicsComponent
{
public:
	PlayerPhysicsComponent();
	~PlayerPhysicsComponent();
	void update(Entity *entity, float frameTime);
};

