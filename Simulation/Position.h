#pragma once

class Position{
public:
	Position(int x, int y);

	void setXByPx(int toX);
	void setYByPx(int toY);
	int getXByPx() const;
	int getYByPx() const;
	void setXYByPx(int toX, int toY);
	void MoveByPx(int diffX, int diffY);
	
	void setXByMap(int toX);
	void setYByMap(int toY);
	int getXByMap() const;
	int getYByMap() const;
	void setXYByMap(int toX, int toY);
	void MoveByMap(int diffX, int diffY);

	bool targetted(int x, int y);

private:
	int x, y;
};