#include "Enemy.h"

using namespace EnemyNS;

Enemy::Enemy() : Entity()
{
	spriteData.width = WIDTH;           // size of EntityPlayer
	spriteData.height = HEIGHT;
	spriteData.x = X;                   // location on screen
	spriteData.y = Y;
	spriteData.rect.bottom = HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = WIDTH;
	edge.top = 0;             // ROTATED_BOX collision edges
	edge.bottom = HEIGHT;
	edge.left = 0;
	edge.right = WIDTH;
	velocity.x = 0;
	velocity.y = 0;
	frameDelay = 0.1f;
	startFrame = 0;     // first frame of animation
	endFrame = cols - 1;     // last frame of animation
	currentFrame = startFrame;
	radius = WIDTH / 2.0;
	collisionType = entityNS::BOX;
	//moveFOV();
	//enemy->moveFOV();
	//setRadians(direction * PI / 180); //convert degree(direction) to rad
	//direction = RIGHT;
	//spriteData.angle = direction * PI/180; //convert degree(direction) to rad
	//velocity = D3DXVECTOR2(100, 1);
}

Enemy::~Enemy()
{
}

void Enemy::update(float frameTime, Player *player)
{
	handleStates(frameTime);
	state_->update(this, player, &enemyAI,frameTime);
	//setVelocity(velo);
	physicsComponent.update(this, frameTime);
	enemyAI.update(this, player, frameTime);
	//spriteData.angle = direction * PI / 180; //convert degree(direction) to rad
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


void Enemy::handleStates(float frameTime)
{
	EnemyState* state = state_->handleEnemy(this, &enemyAI, frameTime);

	if (state != NULL) {
		state_->exit(this);
	
		delete state_;
		state_ = state;
	
		state_->enter(this);
	}
}

void Enemy::damage(int value)
{
	if (health > 0)
		health -= value;

	if (health <= 0) {
		setVisible(false);
		setActive(false);
	}
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
