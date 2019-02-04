#include "ShootingState.h"



ShootingState::ShootingState()
{
}

ShootingState::ShootingState(float timeLeft)
{
	this->timeLeft = timeLeft;
}

ShootingState::~ShootingState()
{
}

void ShootingState::update(Player * player, float frameTime)
{
	if (timeLeft <= 0) {
		player->shootingComponent.fire(D3DXVECTOR2(player->getCenterX(), player->getCenterY()), player->aimDirection);
		timeLeft = FIRE_DELAY;
	}
	timeLeft -= frameTime;
}

PlayerState * ShootingState::handleInput(Player * player, InputComponent * inputC)
{
	if (!inputC->getMouseInput(player, &player->aimDirection)) {
		if (timeLeft <= 0)
			return new IdleState();
	}

	return new ShootingState(timeLeft);
}
