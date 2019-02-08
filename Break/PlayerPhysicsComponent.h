#pragma once
#include "PhysicsComponent.h"
#include "InputComponent.h"
class PlayerPhysicsComponent : PhysicsComponent
{
public:
	PlayerPhysicsComponent();
	~PlayerPhysicsComponent();
	void update(Entity *entity, InputComponent *inputC, float frameTime);
	void Move(Entity *entity, D3DXVECTOR2 direction, float frameTime);
	void Sneak(Entity *entity, D3DXVECTOR2 direction, float frameTime);
	bool Stop(Entity *entity, float frameTime);


};

