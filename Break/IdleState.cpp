#include "IdleState.h"



IdleState::IdleState()
{
}


IdleState::~IdleState()
{
}

void IdleState::update(Player * player, float frameTime)
{
}

PlayerState * IdleState::handleInput(Player * player, InputComponent * inputC)
{
	if (inputC->getMouseInput(player, &player->aimDirection)) {
		return new ShootingState();
	}

	return new IdleState();
}
