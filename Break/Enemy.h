#pragma once
#include "entity.h"
#include "PhysicsComponent.h"
#include "EnemyFOV.h"
#include "Player.h"

enum DIRECTION {
	LEFT = 0, UP = 90,
	RIGHT = 180, DOWN = 270
};

class Enemy: public Entity
{
private:
	PhysicsComponent physicsComponent;
	D3DXVECTOR2 VecEnemyToPlayer;
	Player *player;

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
	float getEnemyToPlayerAngle();
	bool isPlayerInFov();
	void playerInFov();
	void setPlayerPos();
};

