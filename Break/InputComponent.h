#pragma once
#include "input.h"
#include "Entity.h"
class InputComponent
{
public:
	Input * input;
	InputComponent(Game * game);
	InputComponent();
	~InputComponent();
	virtual void update(Entity *entity, float frameTime);
	bool getMovement(D3DXVECTOR2* pOut, bool *pSneakOut);
	bool getMouseInput(Entity *entity, D3DXVECTOR2 *pOut); //returns true if left mouse is clicked, mouse position assigned to pOut

};


