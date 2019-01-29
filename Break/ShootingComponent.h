#pragma once
#include "ProjectilePool.h"
class ShootingComponent
{
private:
	ProjectilePool * projectilesPool;
public:
	ShootingComponent();
	ShootingComponent(ProjectilePool * pool);
	~ShootingComponent();
	void fire(D3DXVECTOR2 position, D3DXVECTOR2 direction);

};

