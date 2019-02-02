#pragma once
#include <vector>
#include "game.h"
#include "Projectile.h"

class ProjectilePool
{
private:
	std::vector<Projectile> projectiles;
public:
	ProjectilePool();
	~ProjectilePool();
	void create(D3DXVECTOR2 position, D3DXVECTOR2 velocity);
	void initialize(Projectile *projectile, int size);
	void update(float frameTime);
	void draw();

};

