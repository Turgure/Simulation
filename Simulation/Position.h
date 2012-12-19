#pragma once

class Position{
public:
	Position(int x, int y);
	void setX(int toX);
	void setY(int toY);
	int getX() const;
	int getY() const;
	
	void setXY(int toX, int toY);
	void Move(int diffX, int diffY);

	bool targetted(int x, int y);

private:
	int x, y;
	int mapsize;
};