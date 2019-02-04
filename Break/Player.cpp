#include "Player.h"



Player::Player()
{
}

Player::~Player()
{

}

void Player::handleInput()
{
	PlayerState* state = state_->handleInput(this, &inputComponent);
	PlayerState* combat = combat_->handleInput(this, &inputComponent);

	if (state != NULL) {
		delete state_;
		state_ = state;
	}

	if (combat != NULL) {
		delete combat_;
		combat_ = combat;
	}

}

void Player::update(float frameTime)
{
	handleInput();

	Entity::update(frameTime);

	state_->update(this, frameTime);
	combat_->update(this, frameTime);

	inputComponent.update(this, frameTime);
	physics.update(this, &inputComponent, frameTime);

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

bool Player::initialize(Game * gamePtr, int width, int height, int ncols, TextureManager * textureM, ProjectilePool * pool)
{
	state_ = new StandingState();
	combat_ = new IdleState();
	shootingComponent = ShootingComponent(pool);
	inputComponent = InputComponent(gamePtr, &shootingComponent);
	physics = PlayerPhysicsComponent();

	direction = D3DXVECTOR2(0, 0);

	return Entity::initialize(gamePtr, width, height, ncols, textureM);

}

