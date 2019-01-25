#include "InputComponent.h"

InputComponent::InputComponent(Game *gamePtr)
{
	input = gamePtr->getInput();
}

InputComponent::InputComponent()
{
}


InputComponent::~InputComponent()
{
}

void InputComponent::update(Entity *entity, float frameTime)
{
	if (input->isKeyDown('D'))
		entity->setVelocity(entity->getVelocity() + D3DXVECTOR2(1, 0) * 100 * frameTime);

}

