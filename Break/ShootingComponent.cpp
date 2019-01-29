#include "ShootingComponent.h"



ShootingComponent::ShootingComponent()
{
}

ShootingComponent::ShootingComponent(ProjectilePool * pool)
{
	projectilesPool = pool;
}


ShootingComponent::~ShootingComponent()
{
}

void ShootingComponent::fire(D3DXVECTOR2 position, D3DXVECTOR2 direction)
{
	projectilesPool->create(position + direction * TILE_SIZE, direction * PROJECTILE_SPEED);
}
