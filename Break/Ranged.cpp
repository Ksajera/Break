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
	sc.fire(position, direction);
}

bool Ranged::initialize(Graphics * g, int width, int height, int ncols, TextureManager * textureM, Projectile* bullet, int magazineSize)
{
	magazine.initialize(bullet, magazineSize);
	sc = ShootingComponent(&magazine);
	return Weapon::initialize(g, width, height, ncols, textureM);
}
