#include "Enemy.h"



Enemy::Enemy()
{
	//moveFOV();
	//enemy->moveFOV();
	//setRadians(direction * PI / 180); //convert degree(direction) to rad
	direction = RIGHT;
	spriteData.angle = direction * PI/180; //convert degree(direction) to rad
	velocity = D3DXVECTOR2(100, 1);

}

Enemy::~Enemy()
{
}

void Enemy::update(float frameTime, Player *player)
{
	handleStates();
	//state_->handleEnemy(this, &enemyAI);
	state_->update(this, player, &enemyAI,frameTime);
	//setVelocity(velo);
	physicsComponent.update(this, frameTime);
	enemyAI.update(this, player, frameTime);
	spriteData.angle = direction * PI / 180; //convert degree(direction) to rad
}

void Enemy::setPosition(D3DXVECTOR2 position)
{
	setX(position.x);
	setY(position.y);
}

D3DXVECTOR2 Enemy::getPosition()
{
	return D3DXVECTOR2(getX(), getY());
}

void Enemy::draw()
{
	Image::draw();

}


void Enemy::handleStates()
{
<<<<<<< HEAD
	EnemyState* state = state_->handleEnemy(this, &enemyAI);
	////EnemyState* combat = combat_->handleInput(this, &inputComponent);
	//
	//if (state != NULL) {
	//	state_->exit(this);
	//
	//	delete state_;
	//	state_ = state;
	//
	//	state_->enter(this);
	//}
=======
	EnemyState* state;
	state = state_->handleEnemy(this, &enemyAI);
	//EnemyState* combat = combat_->handleInput(this, &inputComponent);

	if (state != NULL) {
		state_->exit(this);
	
		delete state_;
		state_ = state;
	
		state_->enter(this);
	}
>>>>>>> 0980ab878cdccafea2b2f945ccaa9f0539b39be9

	//if (combat != NULL) {
	//	state_->exit(this);
	//
	//	delete combat_;
	//	combat_ = combat;
	//
	//	state_->enter(this);
	//}
}


int Enemy::getDirection() {
	return direction;
}

void Enemy::setDirection(int dir) {
	direction = dir;
}

D3DXVECTOR2 Enemy::getVelo() {
	return velocity;
}

void Enemy::setVelo(D3DXVECTOR2 vel) {
	velocity = vel;
}

void Enemy::initState()
{
	state_ = new PatrolState(&enemyAI);
}

bool Enemy::initialize(Game * gamePtr, int width, int height, int ncols, TextureManager * textureM)
{
	physicsComponent = PhysicsComponent();
	return Entity::initialize(gamePtr, width, height, ncols, textureM);
}
