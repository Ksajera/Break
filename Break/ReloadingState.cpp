#include "ReloadingState.h"
#include "IdleState.h"

ReloadingState::ReloadingState(Weapon * weapon) : ShootingState(weapon)
{
	reloadTimeLeft = this->weapon->getReloadDuration();
}

ReloadingState::ReloadingState(Weapon * weapon, float reloadTimeLeft) : ShootingState(weapon)
{
	this->reloadTimeLeft = reloadTimeLeft;
}

ReloadingState::~ReloadingState()
{

}

void ReloadingState::update(Entity * entity, float frameTime)
{
	reloadTimeLeft -= frameTime;

}

CombatState * ReloadingState::handleInput(Entity * entity, InputComponent * inputC, Weapon* weapon)
{
	if (reloadTimeLeft <= 0) {
		weapon->reload();
		if (inputC->getMouseInput(entity, &weapon->direction)) {
			return new ShootingState(weapon);
		}
		else
			return new IdleState();
	}
	else if (inputC->getMouseInput(entity, &weapon->direction)) {
		return new ShootingState(weapon);
	}

	return new ReloadingState(weapon, reloadTimeLeft);
}
