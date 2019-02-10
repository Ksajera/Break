#include "IdleState.h"



IdleState::IdleState()
{
}


IdleState::~IdleState()
{
}

void IdleState::update(Entity * player, float frameTime)
{
}

CombatState * IdleState::handleInput(Entity * entity, InputComponent * inputC, Weapon * weapon)
{
	if (inputC->getMouseInput(entity, &direction)) {
		return new ShootingState(weapon);
	}

	if (inputC->input->wasKeyPressed('R'))
		return new ReloadingState(weapon);

	//if (inputC->getMouseInput(entity, &direction))
	//	return new BackstabState();

	return new IdleState();
}
