#include "StandingState.h"



StandingState::StandingState()
{
}


StandingState::~StandingState()
{
}

void StandingState::enter(Player * player)
{
	player->stopMoving();
}

void StandingState::exit(Player * player)
{

}

void StandingState::update(Player * player, float frameTime)
{
	player->physics.Stop(player, frameTime);
}

PlayerState* StandingState::handleInput(Player * player, InputComponent *inputC)
{
	bool isSneaking = false;
	if (inputC->getMovement(&player->direction, &isSneaking)) {
		if (isSneaking)
			return new SneakingState();

		return new MovingState();
	}

	return new StandingState();

}
