#pragma once
#include "image.h"
class Tile
{
private:
	TextureManager texture;
	Image imageComponent;
	bool booga;

public:
	Tile();
	~Tile();
	void initialize(Graphics *g, const char *file);
	void draw();
	void setPosition(int x, int y);

};

