#pragma once

class Cursor{
public:
	Cursor(int x, int y);
	void update();
	void draw();

private:
	int x;
	int y;
	int image;

	int maptip;
};