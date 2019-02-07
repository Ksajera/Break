#pragma once
#include "ProjectilePool.h"
class ShootingComponent
{
private:
	ProjectilePool * projectilesPool;
	int maxProjectiles;
	int projectilesLeft;
	float timeReload;
	bool isReloading;

public:
	ShootingComponent();
	ShootingComponent(ProjectilePool * pool, int size);
	~ShootingComponent();
	bool fire(D3DXVECTOR2 position, D3DXVECTOR2 direction);
	void reload(float reloadDuration);
	void update(float frameTime);

};

