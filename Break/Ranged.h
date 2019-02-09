#pragma once
#include "Weapon.h"
#include "ShootingComponent.h"
#include "RangedModel.h"
#include "ProjectilePool.h"

class Ranged :
	public Weapon
{
	friend class RangedModel;
public:
	Ranged();
	~Ranged();
	virtual void draw();
	virtual void reload();
	virtual void update(float frameTime);
	virtual void attack(D3DXVECTOR2 position, D3DXVECTOR2 direction);
	virtual bool initialize(Graphics *g, RangedModel &model );
	virtual bool collide(Entity &entity, D3DXVECTOR2 &collisionVector);
	float getReloadDuration() { return reloadDuration; }
	float getAttackSpeed() { return fireRate; }
	ShootingComponent sc;

private:
	RangedModel *model;
	float fireRate;
	int damage;
	int magazineSize;
	float reloadDuration;
	ProjectilePool magazine;

};

