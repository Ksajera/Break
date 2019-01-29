#include "ProjectilePool.h"



ProjectilePool::ProjectilePool()
{
}


ProjectilePool::~ProjectilePool()
{
}

void ProjectilePool::create(D3DXVECTOR2 position, D3DXVECTOR2 velocity)
{
	for (auto it = projectiles.begin(); it < projectiles.end(); it++) {
		if (!(it->getActive())) {
			it->setActive(true);
			it->setVisible(true);
			it->setVelocity(velocity);
			it->setX(position.x);
			it->setY(position.y);
			return;
		}
	}

}

void ProjectilePool::initialize(Projectile *projectile, int size)
{
	projectile->setActive(false);
	projectile->setVisible(false);
	for (int i = 0; i < size; i++) {
		projectiles.push_back(*projectile);

	}
}

void ProjectilePool::update(float frameTime)
{
	for (auto it = projectiles.begin(); it < projectiles.end(); it++) {
		it->update(frameTime);
	}

}

void ProjectilePool::draw()
{
	for (auto it = projectiles.begin(); it < projectiles.end(); it++) {
		if (it->getActive())
			it->draw();
	}
}
