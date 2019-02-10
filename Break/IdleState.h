#pragma once
#include "ShootingState.h"
#include "ReloadingState.h"

class IdleState :
	public CombatState
{
public:
	IdleState();
	~IdleState();

	// Inherited via PlayerState
	virtual void update(Entity * entity, float frameTime) override;
	virtual CombatState * handleInput(Entity * entity, InputComponent * inputC, Weapon* weapon) override;
};

