#include "MovingState.h"



MovingState::MovingState()
{
}


MovingState::~MovingState()
{
}

void MovingState::update(Player * player, float frameTime)
{
	player->physics.Move(player, player->direction, frameTime);

}

PlayerState* MovingState::handleInput(Player * player, InputComponent *inputC)
{
	if (!inputC->getMovement(&player->direction))
		return new StandingState();

	return new MovingState();

}
