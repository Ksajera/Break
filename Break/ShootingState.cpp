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
		player->shootingComponent.fire(player->getPosition(), player->aimDirection);
		timeLeft = FIRE_RATE;
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
