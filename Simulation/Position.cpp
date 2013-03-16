#include <DxLib.h>
#include "Position.h"
#include "GV.h"
#include "Stage.h"

Position::Position(int x, int y){
	this->x = x, this->y = y;
}

void Position::setX(int toX){ x = toX; }
void Position::setY(int toY){ y = toY; }
int Position::getX() const { return x; }
int Position::getY() const { return y; }

void Position::set(int toX, int toY){
	x = toX, y = toY;
}
void Position::Move(int diffX, int diffY){
	x += diffX, y += diffY;
}

int Position::getDist(int x, int y, int toX, int toY){
	return (abs(x - toX) + abs(y - toY));
}

bool Position::targetted(int x, int y){
	return (this->x == x && this->y == y);
}