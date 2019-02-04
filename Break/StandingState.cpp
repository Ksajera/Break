#include "StandingState.h"



StandingState::StandingState()
{
}


StandingState::~StandingState()
{
}

void StandingState::update(Player * player, float frameTime)
{
	player->physics.Stop(player, frameTime);
}

PlayerState* StandingState::handleInput(Player * player, InputComponent *inputC)
{
	if (inputC->getMovement(&player->direction))
		return new MovingState();

	return new StandingState();

}
