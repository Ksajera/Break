#include "MovingState.h"
#include "Player.h"

MovingState::MovingState()
{
}


MovingState::~MovingState()
{
}

void MovingState::enter(Player * player)
{
	player->setAnimFrame();
}

void MovingState::exit(Player * player)
{

}

void MovingState::update(Player * player, float frameTime)
{
	player->physics.Move(player, player->direction, frameTime);
}

PlayerState* MovingState::handleInput(Player * player, InputComponent *inputC)
{
	bool isSneaking = false;
	if (!inputC->getMovement(&player->direction, &isSneaking)) {
		return new StandingState();
	}
	else if (isSneaking)
		return new SneakingState();

	return new MovingState();

}
