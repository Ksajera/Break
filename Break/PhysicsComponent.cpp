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

	entity->setX(entity->getX() + velocity.x * frameTime);
	entity->setY(entity->getY() + velocity.y * frameTime);

}
