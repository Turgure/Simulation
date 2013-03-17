#pragma once

class Position{
public:
	int x, y;
	Position():x(0), y(0){};
	Position(int x, int y):x(x), y(y){};
	Position(const Position& pos):x(pos.x), y(pos.y){};

	//比較
	bool operator==(const Position& pos) const{
		return (x == pos.x && y == pos.y);
	}
	bool operator!=(const Position& pos) const{
		return (x != pos.x || y != pos.y);
	}
	
	//代入
	Position& operator=(const Position& pos){
		x = pos.x;
		y = pos.y;
		return *this;
	}

	//加減算
	Position operator+(const Position& pos) const{
		return Position(x + pos.x, y + pos.y);
	}
	Position& operator+=(const Position& pos){
		x += pos.x;
		y += pos.y;
		return *this;
	}
	Position operator-(const Position& pos) const{
		return Position(x - pos.x, y - pos.y);
	}
	Position& operator-=(const Position& pos){
		x -= pos.x;
		y -= pos.y;
		return *this;
	}

	void setX(int toX);
	void setY(int toY);
	int getX() const;
	int getY() const;
	void set(int toX, int toY);
	void Move(int diffX, int diffY);
	bool targetted(int x, int y);
	int getDist(int x, int y, int toX, int toY);
};