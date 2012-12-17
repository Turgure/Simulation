#pragma once

class Map{
public:
	Map();
	void draw();

private:
	int current_map;
	static int maptips[10][10];
};