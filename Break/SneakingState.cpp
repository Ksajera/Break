#include "SneakingState.h"
#include "Player.h"

SneakingState::SneakingState()
{
}


SneakingState::~SneakingState()
{
}

void SneakingState::update(Player * player, float frameTime)
{
	player->physics.Sneak(player, player->direction, frameTime);

}

PlayerState * SneakingState::handleInput(Player * player, InputComponent * inputC)
{
	return MovingState::handleInput(player, inputC);
}
