#pragma once
#include "Player.h"
#include "PhysicsComponent.h"
//#include "entity.h"

class Enemy;

enum DIRECTION {
	UP = 0, RIGHT = 90,
	DOWN = 180, LEFT = 270
};

class EnemyAI
{
private:
	//Enemy* enemy1;

	PhysicsComponent physicsComponent;
	D3DXVECTOR2 VecEnemyToPlayer;
	D3DXVECTOR2 velo;

	float fovAngle;
	float startFovAngle;
	float endFovAngle;

public:
	EnemyAI();
	~EnemyAI();
	void update(Enemy *enemy, Player *player, float frameTime);

	void moveFOV(Enemy* enemy);
	float getEnemyToPlayerAngle();
	bool isPlayerInFov();
	bool playerInFov(Enemy* enemy);
	D3DXVECTOR2 getVecEnemyToPlayer();
	void setVecEnemyToPlayer(Enemy* enemy, Player *player);
	int getDirection(Enemy* enemy);
	void setDirection(Enemy* enemy, int dir);
	D3DXVECTOR2 getVelo(Enemy* enemy);
	void setVelo(Enemy* enemy, D3DXVECTOR2 vel);

};

