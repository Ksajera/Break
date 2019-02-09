#include "InputComponent.h"

InputComponent::InputComponent(Game* game)
{
	input = game->getInput();
}

InputComponent::InputComponent()
{
}


InputComponent::~InputComponent()
{
}

bool InputComponent::getMovement(D3DXVECTOR2* pOut, bool *pSneakOut) {
	//Movement Controller
	D3DXVECTOR2 direction = D3DXVECTOR2(0, 0);

	bool isMoving = false;

	if (input->isKeyDown(VK_SHIFT))
		*pSneakOut = true;

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

bool InputComponent::getMouseInput(Entity* entity, D3DXVECTOR2 *pOut)
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
	*pOut = aimDirection;

	if (input->getMouseLButton()) {
		return true;
	}

	return false;
}

bool InputComponent::rightMouseClick() //prob need direction later
{
	if (input->getMouseRButton())
		return true;

	return false;
}

void InputComponent::update(Entity *entity, float frameTime)
{


}

