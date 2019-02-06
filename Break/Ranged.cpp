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

void Ranged::update(float frameTime)
{
	Weapon::update(frameTime);
	magazine.update(frameTime);

}

void Ranged::attack(D3DXVECTOR2 position, D3DXVECTOR2 direction)
{
	if (!sc.fire(position, direction))
		reload();

}

bool Ranged::initialize(Graphics * g, int width, int height, int ncols, TextureManager * textureM, Projectile* bullet, int magazineSize)
{
	magazine.initialize(bullet, magazineSize + (magazineSize/reloadDuration * fireRate));
	sc = ShootingComponent(&magazine, magazineSize);
	return Weapon::initialize(g, width, height, ncols, textureM);

}

bool Ranged::collide(Entity & entity, D3DXVECTOR2 & collisionVector)
{
	return magazine.collide(entity, collisionVector);
}

void Ranged::reload()
{
	magazine.reload(magazineSize);
}

