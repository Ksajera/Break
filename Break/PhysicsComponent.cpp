#include "PhysicsComponent.h"



PhysicsComponent::PhysicsComponent()
{
}


PhysicsComponent::~PhysicsComponent()
{
}

void PhysicsComponent::update(Entity * entity, float frameTime)
{
	D3DXVECTOR2 velocity = entity->getVelocity();
	if (D3DXVec2Length(&velocity) > MAX_MOVE_SPEED) {
		D3DXVec2Normalize(&velocity, &velocity);
		entity->setVelocity(velocity * MAX_MOVE_SPEED);
		velocity = entity->getVelocity();

	}

	entity->setX(entity->getX() + velocity.x * frameTime);
	entity->setY(entity->getY() + velocity.y * frameTime);

}
