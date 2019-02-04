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
<<<<<<< HEAD
	EnemyFOV *enemyFOV;
	D3DXVECTOR2 enemyForwardVec;
=======
	//EnemyFOV* enemyFOV;
>>>>>>> dde460914554f159b2601505f1a93c79a9c45db7

	int direction;
	float fovAngle;
	float startFovAngle;
	float endFovAngle;
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

