#pragma once
#include "entity.h"
#include "PhysicsComponent.h"

namespace ProjectileNS
{
	const int   WIDTH = 8;                // image width (each frame)
	const int   HEIGHT = 8;               // image height
	const int   X = GAME_WIDTH / 2 - WIDTH; // location on screen
	const int   Y = GAME_HEIGHT / 2 - HEIGHT;
}

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

