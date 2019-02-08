#pragma once
#include "ShootingState.h"

class IdleState;

class ReloadingState :
	public ShootingState
{
private:
	float reloadTimeLeft;

public:
	ReloadingState(Weapon * weapon);
	ReloadingState(Weapon * weapon, float reloadTimeLeft);
	~ReloadingState();

	// Inherited via PlayerState
	virtual void update(Entity * player, float frameTime) override;
	virtual CombatState * handleInput(Entity * player, InputComponent * inputC, Weapon* weapon) override;
};

