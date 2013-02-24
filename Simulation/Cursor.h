#pragma once
#include "Position.h"

class Cursor{
public:
	Cursor(int x, int y);
	void update();
	void draw();
	static void set(int x, int y);
	
	static Position pos(){ return varpos; }

private:
	int image;

	static Position varpos;
};