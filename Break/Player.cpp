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
	physicsComponent.update(this, frameTime);

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

bool Player::initialize(Game * gamePtr, int width, int height, int ncols, TextureManager * textureM)
{
	inputComponent = InputComponent(gamePtr);
	physicsComponent = PhysicsComponent();
	return Entity::initialize(gamePtr, width, height, ncols, textureM);
}

