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

void Player::scroll()
{
	//horizontal scrolling
	float scrollX = SCREEN_WIDTH / 2 - getCenterX();
	float levelExtentX = static_cast<float>(SCREEN_WIDTH * 3);

	if (getCenterX() < SCREEN_WIDTH / 2)
		scrollX = 0.0f;
	if (getCenterX() > levelExtentX - SCREEN_WIDTH / 2)
		scrollX = -(levelExtentX - SCREEN_WIDTH);

	//vertical scrolling (-ve cause its downwards)
	float scrollY = SCREEN_HEIGHT / 2 - getCenterY();
	float levelExtentY = static_cast<float>(SCREEN_HEIGHT * 2.f);

	if (getCenterY() >= SCREEN_HEIGHT / 2)
		scrollY = 0.0f;
	if (getCenterY() < -levelExtentY + SCREEN_HEIGHT + SCREEN_HEIGHT / 2)
		scrollY = levelExtentY - SCREEN_HEIGHT;

}

bool Player::initialize(Game * gamePtr, int width, int height, int ncols, TextureManager * textureM)
{
	inputComponent = InputComponent(gamePtr);
	physicsComponent = PhysicsComponent();
	return Entity::initialize(gamePtr, width, height, ncols, textureM);
}

