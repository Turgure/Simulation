#pragma once

class Position{
public:
	Position(int x, int y);

	void setXByPx(int toX);
	void setYByPx(int toY);
	int getXByPx() const;
	int getYByPx() const;
	void setX(int toX);
	void setY(int toY);
	int getX() const;
	int getY() const;

	void setByPx(int toX, int toY);
	void MoveByPx(int diffX, int diffY);
	void set(int toX, int toY);
	void Move(int diffX, int diffY);

	int getDistByPx(int x, int y, int toX, int toY);
	int getDist(int x, int y, int toX, int toY);

	bool targetted(int x, int y);

private:
	int x, y;
};