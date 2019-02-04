#pragma once
#include "PlayerState.h"
#include "ShootingState.h"
#include "Player.h"
class IdleState :
	public PlayerState
{
public:
	IdleState();
	~IdleState();

	// Inherited via PlayerState
	virtual void update(Player * player, float frameTime) override;
	virtual PlayerState * handleInput(Player * player, InputComponent * inputC) override;
};

