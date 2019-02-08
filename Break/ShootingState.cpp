#include "ShootingState.h"
#include "ReloadingState.h"
#include "IdleState.h"
#include "Ranged.h"

ShootingState::ShootingState(Weapon * weapon)
{
	this->weapon = dynamic_cast<Ranged*>(weapon);
	timeLeft = 0;
}

ShootingState::ShootingState(Weapon * weapon, float timeLeft)
{
	this->weapon = dynamic_cast<Ranged*>(weapon);
	this->timeLeft = timeLeft;
}

ShootingState::~ShootingState()
{
}

void ShootingState::update(Entity * entity, float frameTime)
{
	timeLeft -= frameTime;
	if (timeLeft <= 0) {
		D3DXVECTOR2 position = D3DXVECTOR2(entity->getCenterX(), entity->getCenterY());
		weapon->attack(position, weapon->direction);
		timeLeft = 1/weapon->getAttackSpeed();
	}

}

CombatState * ShootingState::handleInput(Entity * entity, InputComponent * inputC, Weapon *weapon)
{
	if (!inputC->getMouseInput(entity, &weapon->direction)) {
		return new IdleState();
	}	

	if (inputC->input->wasKeyPressed('R'))
		return new ReloadingState(weapon);

	return new ShootingState(weapon, timeLeft);
}
