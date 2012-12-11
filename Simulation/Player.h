#pragma once

#include "BaseObject.h"

class Player/* : public BaseObject*/{
public:
	Player(int x, int y);
	void update();
	void draw();

private:
	int x;
	int y;
	int image;
	char* name;

	int mapsize;
};