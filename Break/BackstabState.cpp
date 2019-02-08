#include "BackstabState.h"
#include "MovingState.h"
#include "Player.h"


BackstabState::BackstabState()
{
}


BackstabState::~BackstabState()
{
}

void BackstabState::update(Player * player, float frameTime)
{
}

PlayerState * BackstabState::handleInput(Player * player, InputComponent * inputC)
{
	//return MovingState::handleInput(player, inputC);
	return nullptr;
}
