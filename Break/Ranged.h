#pragma once
#include "Weapon.h"
#include "ShootingComponent.h"
#include "ProjectilePool.h"
class Ranged :
	public Weapon
{
public:
	Ranged();
	~Ranged();
	virtual void draw();
	virtual void update(float frameTime);
	virtual void attack(D3DXVECTOR2 position, D3DXVECTOR2 direction);
	virtual bool initialize(Graphics * g, int width, int height, int ncols, TextureManager * textureM, Projectile * bullet, int magazineSize);
	virtual bool collide(Entity &entity, D3DXVECTOR2 &collisionVector);
	virtual void reload();
	ShootingComponent sc;

private:
	float fireRate;
	int damage;
	int magazineSize;
	float reloadDuration;
	float reloadTimeLeft;
	ProjectilePool magazine;

};

