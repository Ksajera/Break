#pragma once
#include "entity.h"
#include "PhysicsComponent.h"

class Enemy: public Entity
{
private:
	PhysicsComponent physicsComponent;
public:
	Enemy();
	~Enemy();
	void update(float frameTime);
	void setPosition(D3DXVECTOR2 position);
	D3DXVECTOR2 getPosition();
	void draw();
	bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
};

