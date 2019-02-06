#include "Enemy.h"



Enemy::Enemy()
{
	direction = DIRECTION::UP;
	direction = RIGHT;
	moveFOV();
	spriteData.angle = direction * PI/180; //convert degree(direction) to rad
	velo = D3DXVECTOR2(1000, 1);
}


Enemy::~Enemy()
{
}

void Enemy::update(float frameTime, Player *player)
{
	//enemyAI.update(this, physicsComponent, frameTime);
	setVecEnemyToPlayer(player); // set VecEnemyToPlayer variable
	playerInFov();
	physicsComponent.update(this, frameTime);

	aiUpdate();
	moveFOV();
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

bool Enemy::initialize(Game * gamePtr, int width, int height, int ncols, TextureManager * textureM)
{
	physicsComponent = PhysicsComponent();
	return Entity::initialize(gamePtr, width, height, ncols, textureM);
}

void Enemy::checkDirection() 
{
	//prob dont need this func 
	//or at least change it to be called in another class to set direction in enemy ai 
}

void Enemy::moveFOV() 
{
	startFovAngle = direction - ENEMY_FOV_ANGLE_START -90; 
	endFovAngle = direction + ENEMY_FOV_ANGLE_START   -90;
}

float Enemy::getEnemyToPlayerAngle() 
{
	float angle = 0;
	angle = atan2(VecEnemyToPlayer.y, VecEnemyToPlayer.x) * 180 / PI; //no need  * 180 / PI because image.angle is in rad
	return angle; 
}

bool Enemy::isPlayerInFov()
{
	/*
	if player within min angle and max angle
		return true
	else
		return false
	*/
	if (getEnemyToPlayerAngle() > startFovAngle && getEnemyToPlayerAngle() < endFovAngle)
		return true;
	else
		return false;
}

void Enemy::playerInFov()
{
	if (isPlayerInFov()) {
		//do the count down and stuff i guess
		//change sprite image color to test?
		active = false;
		visible = false;
	}
	else {
		active = true;
		visible = true;
	}
}

void Enemy::setVecEnemyToPlayer(Player *player) //call in update()
{
	VecEnemyToPlayer = player->getPosition() - getPosition(); 
}

void Enemy::aiUpdate() 
{
	// collide game width/height and bounce around
	if (getX() + getWidth() > GAME_WIDTH) { // top right
		setX(GAME_WIDTH - getWidth());
		//direction = DIRECTION(rand() % 4);
		direction = DOWN;
		velo = D3DXVECTOR2(1, 100);
	}

	if (getY() + getHeight() > GAME_HEIGHT) { //bottom right
		setY(GAME_HEIGHT - getHeight());
		//direction = DIRECTION(rand() % 4);
		direction = LEFT;
		velo = D3DXVECTOR2(-100, 1);
	}

	if ((getX() + TILE_SIZE) < 0) { // bottom left
		setX(0);
		//direction = DIRECTION(rand() % 4);
		direction = UP;
		velo = D3DXVECTOR2(1, -100);

	}

	if ((getY() + TILE_SIZE) < 0) { // top left
		setY(0);
		//direction = DIRECTION(rand() % 4);
		direction = RIGHT;
		velo = D3DXVECTOR2(100, 1);

	}

	setVelocity(velo);
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
