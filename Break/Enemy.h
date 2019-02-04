#pragma once
#include "entity.h"
#include "PhysicsComponent.h"
#include "EnemyFOV.h"

enum DIRECTION {
	UP = -1, DOWN = 1,
	LEFT = -2, RIGHT = 2
};

class Enemy: public Entity
{
private:
	PhysicsComponent physicsComponent;
	//EnemyFOV* enemyFOV;

	int direction;
public:
	Enemy();
	~Enemy();
	void update(float frameTime);
	D3DXVECTOR2 getPosition();
	void setPosition(D3DXVECTOR2 position);
	void draw();
	bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
	void checkDirection();
	void moveFOV();
};

