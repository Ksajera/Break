#pragma once
#include "CombatState.h"
#include "Ranged.h"

class ReloadingState;
class IdleState;

class ShootingState :
	public CombatState
{
private:
	float timeLeft;

protected:
	Ranged* weapon;

public:
	ShootingState(Weapon * weapon);
	ShootingState(Weapon * weapon, float timeLeft);
	~ShootingState();

	// Inherited via PlayerState
	virtual void update(Entity * player, float frameTime) override;
	virtual CombatState * handleInput(Entity * entity, InputComponent * inputC, Weapon *weapon) override;
};

