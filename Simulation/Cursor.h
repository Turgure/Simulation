#pragma once

class Cursor{
public:
	Cursor(int x, int y);
	void update();
	void draw();
	static int getX(){ return x; }
	static int getY(){ return y; }

private:
	static int x;
	static int y;
	int image;
};