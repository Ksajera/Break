#pragma once
#include "PlayerState.h"
#include "Player.h"
#include "MovingState.h"
class StandingState : public PlayerState
{
public:
	StandingState();
	~StandingState();
	void update(Player* player, float frameTime);
	virtual PlayerState* handleInput(Player * player, InputComponent *inputC);

};

