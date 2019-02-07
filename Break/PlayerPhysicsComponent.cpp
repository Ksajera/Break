#include "PlayerPhysicsComponent.h"

PlayerPhysicsComponent::PlayerPhysicsComponent()
{
}


PlayerPhysicsComponent::~PlayerPhysicsComponent()
{
}

void PlayerPhysicsComponent::update(Entity * entity, InputComponent* inputC, float frameTime)
{
	PhysicsComponent::update(entity, frameTime);

}

void PlayerPhysicsComponent::Move(Entity *entity, D3DXVECTOR2 direction, float frameTime)
{
	D3DXVECTOR2 velocity = entity->getVelocity();

	entity->setVelocity(velocity + direction  * MOVE_SPEED * frameTime);

	if (D3DXVec2Length(&velocity) > MAX_MOVE_SPEED) {
		D3DXVECTOR2 uv;
		D3DXVec2Normalize(&uv, &velocity);
		entity->setVelocity(uv * MAX_MOVE_SPEED);

	}

}

bool PlayerPhysicsComponent::Stop(Entity * entity, float frameTime)
{
	D3DXVECTOR2 velocity = entity->getVelocity();
	if (velocity != D3DXVECTOR2(0, 0)) {
		D3DXVECTOR2 uv;
		D3DXVec2Normalize(&uv, &velocity);
		entity->setVelocity(velocity - uv * 300 * frameTime);
	}
	else
		return true; //stopped moving

	return false; //still moving

}



