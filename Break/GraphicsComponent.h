#pragma once
#include "graphics.h"
class GraphicsComponent
{
private:
	SpriteData sd;
public:
	GraphicsComponent();
	~GraphicsComponent();
	virtual void draw(Graphics& graphics);
};

