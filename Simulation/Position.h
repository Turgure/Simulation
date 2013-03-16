#pragma once

class Position{
public:
	Position(int x, int y);

	void setX(int toX);
	void setY(int toY);
	int getX() const;
	int getY() const;
	void set(int toX, int toY);
	void Move(int diffX, int diffY);
	int getDist(int x, int y, int toX, int toY);

	bool targetted(int x, int y);

private:
	int x, y;
};