#pragma once
#include "MovingState.h"
class SneakingState :
	public MovingState
{
public:
	SneakingState();
	~SneakingState();

	// Inherited
	virtual void update(Player * player, float frameTime) override;
	virtual PlayerState * handleInput(Player * player, InputComponent * inputC) override;
};

