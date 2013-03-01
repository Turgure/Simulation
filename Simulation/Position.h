#pragma once

class Position{
public:
	Position(int x, int y);

	void setXByPx(int toX);
	void setYByPx(int toY);
	int getXByPx() const;
	int getYByPx() const;
	void setXByMap(int toX);
	void setYByMap(int toY);
	int getXByMap() const;
	int getYByMap() const;

	void setByPx(int toX, int toY);
	void MoveByPx(int diffX, int diffY);
	void setByMap(int toX, int toY);
	void MoveByMap(int diffX, int diffY);

	int getDistByPx(int x, int y, int toX, int toY);
	int getDistByMap(int x, int y, int toX, int toY);

	bool targetted(int x, int y);

private:
	int x, y;
};