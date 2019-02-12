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

	float angleFaced;

public:
	EnemyAI();
	~EnemyAI();
	void update(Enemy *enemy, Player *player, float frameTime);

	void rotateEnemy(Enemy* enemy);
	void moveFOV(Enemy* enemy);
	float getEnemyToPlayerAngle();
	void calcAngleFaced(D3DXVECTOR2 vec);
	void setAngleFaced(float angle);
	bool isPlayerInFov();
	bool playerInFov(Enemy* enemy);
	D3DXVECTOR2 getVecEnemyToPlayer();
	void setVecEnemyToPlayer(Enemy* enemy, Player *player);
	int getDirection(Enemy* enemy);
	void setDirection(Enemy* enemy, int dir);
	D3DXVECTOR2 getVelo(Enemy* enemy);
	void setVelo(Enemy* enemy, D3DXVECTOR2 vel);
	void StayInScreen(Enemy* enemy);

	//use in SuspiciousState
	float countUpIgnore, countUpAlert,
	//use in PatrolState
		countUpPatrol, countUpIdle;
	D3DXVECTOR2 randoDir; 
};

