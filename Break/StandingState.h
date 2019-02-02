#pragma once
#include "PlayerState.h"
class StandingState : public PlayerState
{
public:
	StandingState();
	~StandingState();
	void update(Entity* player, float frameTime);
	void handleInput(Entity* player);

};

