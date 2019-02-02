#pragma once
#include "PhysicsComponent.h"
#include "InputComponent.h"
class PlayerPhysicsComponent : PhysicsComponent
{
public:
	PlayerPhysicsComponent();
	~PlayerPhysicsComponent();
	void update(Entity *entity, InputComponent *inputC, float frameTime);
	void Move(D3DXVECTOR2* velocity, InputComponent* inputC, float frameTime);
};

