#pragma once
#include "PlayerState.h"
class BackstabState :
	public PlayerState
{
public:
	BackstabState();
	~BackstabState();

	// Inherited via PlayerState
	virtual void update(Player * player, float frameTime) override;
	virtual PlayerState * handleInput(Player * player, InputComponent * inputC) override;
};

