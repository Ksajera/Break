#include "PlayerPhysicsComponent.h"

PlayerPhysicsComponent::PlayerPhysicsComponent()
{
}


PlayerPhysicsComponent::~PlayerPhysicsComponent()
{
}

void PlayerPhysicsComponent::update(Entity * entity, InputComponent* inputC, float frameTime)
{
	D3DXVECTOR2 velocity = entity->getVelocity();

	Move(&velocity, inputC, frameTime);
	entity->setVelocity(velocity);

	PhysicsComponent::update(entity, frameTime);

}

void PlayerPhysicsComponent::Move(D3DXVECTOR2* velocity, InputComponent* inputC, float frameTime)
{
	D3DXVECTOR2 direction;
	D3DXVECTOR2 uv;
	if (inputC->getMovement(&direction)) {
		*velocity += direction * MOVE_SPEED * frameTime;

		if (D3DXVec2Length(velocity) > MAX_MOVE_SPEED) {
			D3DXVec2Normalize(&uv, velocity);
			*velocity = uv * MAX_MOVE_SPEED;

		}
	}
	else {
		if (*velocity != D3DXVECTOR2(0, 0)) {
			D3DXVec2Normalize(&uv, velocity);
			*velocity -= uv * 180 * frameTime; //decelerate, pseudo lerp
		}
	}

}
