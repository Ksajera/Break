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
	void destroy();
	void destroy(std::vector<Projectile>::iterator &it);
	bool collide(Entity &entity, D3DXVECTOR2 &collisionVector);
	void initialize(Projectile *projectile, int size);
	void update(float frameTime);
	void draw();
	void reload(int magazineSize);

};

