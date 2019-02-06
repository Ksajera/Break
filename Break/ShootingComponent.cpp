#include "ShootingComponent.h"



ShootingComponent::ShootingComponent()
{
}

ShootingComponent::ShootingComponent(ProjectilePool * pool, int size)
{
	projectilesPool = pool;
	maxProjectiles = size;
	projectilesLeft = size;
}


ShootingComponent::~ShootingComponent()
{
}

void ShootingComponent::update(float frameTime)
{
	projectilesPool->update(frameTime);
	if (isReloading) {
		timeReload -= frameTime;
		if (timeReload <= 0) {
			projectilesPool->reload(maxProjectiles);
			projectilesLeft = maxProjectiles;
			isReloading = false;
		}

	}

}

bool ShootingComponent::fire(D3DXVECTOR2 position, D3DXVECTOR2 direction)
{
	if (projectilesLeft > 0) {
		projectilesPool->create(position + direction * TILE_SIZE, direction * PROJECTILE_SPEED);
		projectilesLeft--;
	}
	else
		return false;

	return true;

}

void ShootingComponent::reload(float reloadDuration) {
	if (isReloading != true) {
		isReloading = true;
		timeReload = reloadDuration;
	}

}

