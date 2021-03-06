#include "Player.h"

using namespace PlayerNS;

Player::Player() : Entity()
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
	animFrame = getCurrentFrame();
}

Player::~Player()
{

}

void Player::handleInput()
{
	PlayerState* state = state_->handleInput(this, &inputComponent);
	CombatState* combat = combat_->handleInput(this, &inputComponent, weapon);

	if (state != NULL) {
		state_->exit(this);

		delete state_;
		state_ = state;

		state_->enter(this);
	}

	if (combat != NULL) {
		state_->exit(this);

		delete combat_;
		combat_ = combat;

		state_->enter(this);
	}

}

void Player::setAnimFrame(int frame)
{
	this->animFrame = frame;
	setFrames(animFrame, animFrame + cols + 1);
}

void Player::setAnimFrame()
{
	//float rad = atan2(direction.y, direction.x);
	float rad = atan2(direction.y, direction.x);

	//if (rad > -(7 * PI / 4) && rad < -(PI / 4))
	//	animFrame = UP_START_FRAME;

	//if (rad > (3 * PI / 4) && rad < (5 * PI / 4))
	//	animFrame = LEFT_START_FRAME;

	//if (rad > (PI / 4) && rad < (3 * PI / 4))
	//	animFrame = DOWN_START_FRAME;

	//if (rad > -(5 * PI / 4) && rad < -(7 * PI / 4))
	//	animFrame = RIGHT_START_FRAME;
	
	if (rad == atan2(1.0f, 0.0f))
		animFrame = DOWN_START_FRAME;

	if (rad == atan2(-1.0f, 0.0f))
		animFrame = UP_START_FRAME;

	if (rad == atan2(0.0f, 1.0f))
		animFrame = RIGHT_START_FRAME;

	if (rad == atan2(0.0f, -1.0f))
		animFrame = LEFT_START_FRAME;

	if (animFrame != getStartFrame()) {
		setFrames(animFrame, animFrame + cols - 1);
		setCurrentFrame(animFrame);
	}

}

void Player::stopMoving()
{
	setCurrentFrame(animFrame);
	setFrames(animFrame, animFrame);
}

void Player::update(float frameTime)
{
	handleInput();
	state_->update(this, frameTime);
	combat_->update(this, frameTime);
	Entity::update(frameTime);
	inputComponent.update(this, frameTime);
	weapon->update(frameTime);
	physics.update(this, &inputComponent, frameTime);
	//setAnimFrame();
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

D3DXVECTOR2 Player::getWeaponPosition()
{
	return D3DXVECTOR2(weapon->getCenterX(), weapon->getCenterY());
}

void Player::draw()
{
	Image::draw();
	weapon->draw();
}

void Player::equip(Weapon *w)
{
	weapon = w;
	weapon->User = this;
}

void Player::equip(RangedModel * model)
{
	weapon = model->newRanged(graphics);
	weapon->User = this;
}

void Player::scroll()
{
	////horizontal scrolling
	////float scrollX = SCREEN_WIDTH / 2 - getCenterX();
	//float levelExtentX = static_cast<float>(SCREEN_WIDTH * 3);

	//if (getCenterX() < SCREEN_WIDTH / 2)
	//	scrollX = 0.0f;
	//if (getCenterX() > levelExtentX - SCREEN_WIDTH / 2)
	//	scrollX = -(levelExtentX - SCREEN_WIDTH);

	////vertical scrolling (-ve cause its downwards)
	////float scrollY = SCREEN_HEIGHT / 2 - getCenterY();
	//float levelExtentY = static_cast<float>(SCREEN_HEIGHT * 2.f);

	//if (getCenterY() >= SCREEN_HEIGHT / 2)
	//	scrollY = 0.0f;
	//if (getCenterY() < -levelExtentY + SCREEN_HEIGHT + SCREEN_HEIGHT / 2)
	//	scrollY = levelExtentY - SCREEN_HEIGHT;

}

bool Player::initialize(Game * gamePtr, int width, int height, int ncols, TextureManager * textureM)
{
	state_ = new StandingState();
	combat_ = new IdleState();
	inputComponent = InputComponent(gamePtr);
	physics = PlayerPhysicsComponent();

	direction = D3DXVECTOR2(0, 0);

	return Entity::initialize(gamePtr, width, height, ncols, textureM);

}

