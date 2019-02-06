#pragma once
#include "entity.h"
#include "PhysicsComponent.h"
//#include "EnemyFOV.h"
#include "Player.h"
#include "EnemyAI.h"

enum DIRECTION {
	UP = 0, RIGHT = 90, 
	DOWN = 180, LEFT = 270
};

class Enemy: public Entity
{
private:
	PhysicsComponent physicsComponent;
	D3DXVECTOR2 VecEnemyToPlayer;
	EnemyAI enemyAI;
	//Player *player;
	D3DXVECTOR2 velo;

	int direction;
	float fovAngle;
	float startFovAngle;
	float endFovAngle;
public:
	Enemy();
	~Enemy();
	void update(float frameTime, Player *player);
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
	void setVecEnemyToPlayer(Player *player);
	void aiUpdate();
	int getDirection();
	void setDirection(int dir);
	D3DXVECTOR2 getVelo();
	void setVelo(D3DXVECTOR2 vel);
};

