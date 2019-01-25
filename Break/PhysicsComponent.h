#pragma once
#include "entity.h"
class PhysicsComponent
{
public:
	PhysicsComponent();
	~PhysicsComponent();
	void update(Entity *entity, float frameTime);
};

