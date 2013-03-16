#include <DxLib.h>
#include "Position.h"
#include "GV.h"
#include "Stage.h"

Position::Position(int x, int y){
	this->x = x, this->y = y;
}

void Position::setXByPx(int toX){ x = Stage::getLeftupPositionX() + toX*chipsize; }
void Position::setYByPx(int toY){ y = Stage::getLeftupPositionY() + toY*chipsize; }
int Position::getXByPx() const { return Stage::getLeftupPositionX() + x*chipsize; }
int Position::getYByPx() const { return Stage::getLeftupPositionY() + y*chipsize; }
void Position::setX(int toX){ x = toX; }
void Position::setY(int toY){ y = toY; }
int Position::getX() const { return x; }
int Position::getY() const { return y; }

void Position::setByPx(int toX, int toY){
	x = Stage::getLeftupPositionX() + toX*chipsize;
	y = Stage::getLeftupPositionY() + toY*chipsize;
}
void Position::MoveByPx(int diffX, int diffY){
	x += diffX*chipsize;
	y += diffY*chipsize;
}
void Position::set(int toX, int toY){
	x = toX, y = toY;
}
void Position::Move(int diffX, int diffY){
	x += diffX, y += diffY;
}

int Position::getDistByPx(int x, int y, int toX, int toY){
	return static_cast<int>( sqrt((x-toX)*(x-toX) + (y-toY)*(y-toY)) );
}
int Position::getDist(int x, int y, int toX, int toY){
	return (abs(x - toX) + abs(y - toY));
}

bool Position::targetted(int x, int y){
	return (this->x == x && this->y == y);
}