#pragma once
#include "PlayerState.h"
#include "Player.h"
#include "SneakingState.h"

class StandingState : public PlayerState
{
public:
	StandingState();
	~StandingState();
	virtual void enter(Player * player);
	virtual void exit(Player * player);
	void update(Player* player, float frameTime);
	virtual PlayerState* handleInput(Player * player, InputComponent *inputC);

};

