#pragma once

#include "BaseObject.h"

class Enemy/* : public BaseObject*/{
public:
	Enemy(int x, int y);
	void update();
	void draw();

private:
	int x;
	int y;
	int image;
	char* name;

	int mapsize;
};