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
	virtual void reload();
	virtual void update(float frameTime);
	virtual void attack(D3DXVECTOR2 position, D3DXVECTOR2 direction);
	virtual float getAttackSpeed();
	virtual float getReloadDuration();
	virtual bool initialize(Graphics * g, int width, int height, int ncols, TextureManager * textureM, Projectile * bullet, int magazineSize, float reloadTime, float firerate);
	virtual bool collide(Entity &entity, D3DXVECTOR2 &collisionVector);
	ShootingComponent sc;

private:
	float fireRate;
	int damage;
	int magazineSize;
	float reloadDuration;
	ProjectilePool magazine;

};

