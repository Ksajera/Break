#include "Projectile.h"



Projectile::Projectile()
{
}


Projectile::~Projectile()
{
}

void Projectile::update(float frameTime)
{
	physics.update(this, frameTime);
}

bool Projectile::initialize(Game * gamePtr, int width, int height, int ncols, TextureManager * textureM)
{
	physics = PhysicsComponent();
	return Entity::initialize(gamePtr, width, height, ncols, textureM);

}

void Projectile::draw()
{
	Image::draw();
}
