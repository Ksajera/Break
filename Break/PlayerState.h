#pragma once
#include "Entity.h"
//including Player.h causes circular dependency error
class PlayerState
{
public:
	PlayerState();
	~PlayerState();
	virtual void update(Entity* player, float frameTime) = 0;
	virtual void handleInput(Entity * player, Input *input) = 0;

};

