#include "Weapon.h"



Weapon::Weapon()
{
}


Weapon::~Weapon()
{
}

void Weapon::draw()
{
	Image::draw();
}

void Weapon::update(float frameTime)
{
}

void Weapon::attack()
{
}

void Weapon::attack(D3DXVECTOR2 position, D3DXVECTOR2 direction)
{
}

void Weapon::reload()
{
	
}

float Weapon::getAttackSpeed()
{
	return 0.0f;
}

int Weapon::getDamage()
{
	return 0;
}

bool Weapon::collide(Entity & entity, D3DXVECTOR2 & collisionVector)
{
	return false;
}

bool Weapon::initialize(Graphics * g, int width, int height, int ncols, TextureManager * textureM)
{
	return Image::initialize(g, width, height, ncols, textureM);
}
