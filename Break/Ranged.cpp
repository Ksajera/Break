#include "Ranged.h"



Ranged::Ranged()
{
}


Ranged::~Ranged()
{
}

void Ranged::draw()
{
	Weapon::draw();
	magazine.draw();
}

void Ranged::reload()
{
	sc.reload();
}

void Ranged::update(float frameTime)
{
	Weapon::update(frameTime);
	sc.update(frameTime);

}

void Ranged::attack(D3DXVECTOR2 position, D3DXVECTOR2 direction)
{
	sc.fire(position, direction);

}



float Ranged::getAttackSpeed()
{
	return fireRate;
}

float Ranged::getReloadDuration()
{
	return reloadDuration;
}

bool Ranged::initialize(Graphics * g, int width, int height, int ncols, TextureManager * textureM, Projectile* bullet, int magazineSize, float reloadTime, float firerate)
{
	reloadDuration = reloadTime;
	fireRate = firerate;
	magazine.initialize(bullet, magazineSize + (magazineSize/reloadDuration * fireRate));
	sc = ShootingComponent(&magazine, magazineSize);
	return Weapon::initialize(g, width, height, ncols, textureM);

}

bool Ranged::collide(Entity & entity, D3DXVECTOR2 & collisionVector)
{
	return magazine.collide(entity, collisionVector);
}


