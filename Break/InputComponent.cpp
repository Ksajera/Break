#include "InputComponent.h"

InputComponent::InputComponent(Game *gamePtr, ShootingComponent *pewpew)
{
	input = gamePtr->getInput();
	sc = pewpew;
}

InputComponent::InputComponent()
{
}


InputComponent::~InputComponent()
{
}

bool InputComponent::getMovement(D3DXVECTOR2* pOut) {
	//Movement Controller
	D3DXVECTOR2 direction = D3DXVECTOR2(0, 0);
	bool isMoving = false;

	if (input->isKeyDown('D'))
		direction.x = 1;
	else if (input->isKeyDown('A'))
		direction.x = -1;
	if (input->isKeyDown('S'))
		direction.y = 1;
	else if (input->isKeyDown('W'))
		direction.y = -1;

	if (direction != D3DXVECTOR2(0, 0))
		isMoving = true;

	*pOut = direction;
	return isMoving;
}

void InputComponent::update(Entity *entity, float frameTime)
{

	D3DXVECTOR2 mousePos;
	D3DXVECTOR2 position;
	D3DXVECTOR2 aimDirection;

	mousePos.x = input->getMouseX();
	mousePos.y = input->getMouseY();

	position.x = entity->getCenterX();
	position.y = entity->getCenterY();

	aimDirection = mousePos - position;
	D3DXVec2Normalize(&aimDirection, &aimDirection);

	if (input->getMouseLButton()) {
		sc->fire(position, aimDirection);

	}

}

