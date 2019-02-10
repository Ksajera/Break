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
	sc.update(frameTime);
	if (User != nullptr) {
		setX(User->getCenterX() + direction.x);
		setY(User->getCenterY() + direction.y);
		setRadians(atan2(direction.y, direction.x));
		if (direction.x < 0)
			flipVertical(true);
		else
			flipVertical(false);
	}

}

void Ranged::attack(D3DXVECTOR2 position, D3DXVECTOR2 direction)
{
	sc.fire(position, direction);

}

bool Ranged::initialize(Graphics *g, RangedModel &model)
{
	reloadDuration = model.getReloadTime();
	fireRate = model.getFireRate();
	damage = model.getDamage();
	magazineSize = model.getClipSize();
	magazine.initialize(model.getProjectile(), magazineSize + (magazineSize/reloadDuration * fireRate));
	sc = ShootingComponent(&magazine, magazineSize);
	this->model = &model;
	return Weapon::initialize(g, model.getWidth(), model.getHeight(), model.getCols(), model.getTextureM());

}

bool Ranged::collide(Entity & entity, D3DXVECTOR2 & collisionVector)
{
	return magazine.collide(entity, collisionVector);
}


