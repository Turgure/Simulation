#pragma once

class Cursor{
public:
	Cursor(int x, int y);
	void update();
	void draw();
	int getX() const { return x; }
	int getY() const { return y; }

private:
	int x;
	int y;
	int image;

	int maptip;
};