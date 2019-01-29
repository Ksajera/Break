#include "Player.h"



Player::Player()
{
}

Player::~Player()
{

}

void Player::update(float frameTime)
{
	Entity::update(frameTime);
	inputComponent.update(this, frameTime);
	physics.update(this, frameTime);

}

void Player::setPosition(D3DXVECTOR2 position)
{
	setX(position.x);
	setY(position.y);
}

D3DXVECTOR2 Player::getPosition()
{
	return D3DXVECTOR2(getX(), getY());
}

void Player::draw()
{
	Image::draw();

}

bool Player::initialize(Game * gamePtr, int width, int height, int ncols, TextureManager * textureM, ProjectilePool * pool)
{
	shootingComponent = ShootingComponent(pool);
	inputComponent = InputComponent(gamePtr, &shootingComponent);
	physics = PlayerPhysicsComponent();

	return Entity::initialize(gamePtr, width, height, ncols, textureM);

}

