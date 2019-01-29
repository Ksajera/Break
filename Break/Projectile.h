#pragma once
#include "entity.h"
#include "PhysicsComponent.h"
class Projectile : public Entity
{
private:
	PhysicsComponent physics;

public:
	Projectile();
	~Projectile();
	void update(float frameTime);
	bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
	void draw();

};

