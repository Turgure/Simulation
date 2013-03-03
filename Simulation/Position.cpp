#include <DxLib.h>
#include "Position.h"
#include "GV.h"
#include "Stage.h"

Position::Position(int x, int y){
	this->x = x, this->y = y;
}

void Position::setXByPx(int toX){ x = Stage::getLeftupPositionX() + toX*mapsize; }
void Position::setYByPx(int toY){ y = Stage::getLeftupPositionY() + toY*mapsize; }
int Position::getXByPx() const { return Stage::getLeftupPositionX() + x*mapsize; }
int Position::getYByPx() const { return Stage::getLeftupPositionY() + y*mapsize; }
void Position::setXByMap(int toX){ x = toX; }
void Position::setYByMap(int toY){ y = toY; }
int Position::getXByMap() const { return x; }
int Position::getYByMap() const { return y; }

void Position::setByPx(int toX, int toY){
	x = Stage::getLeftupPositionX() + toX*mapsize;
	y = Stage::getLeftupPositionY() + toY*mapsize;
}
void Position::MoveByPx(int diffX, int diffY){
	x += diffX*mapsize;
	y += diffY*mapsize;
}
void Position::setByMap(int toX, int toY){
	x = toX, y = toY;
}
void Position::MoveByMap(int diffX, int diffY){
	x += diffX, y += diffY;
}

int Position::getDistByPx(int x, int y, int toX, int toY){
	return static_cast<int>( sqrt((x-toX)*(x-toX) + (y-toY)*(y-toY)) );
}
int Position::getDistByMap(int x, int y, int toX, int toY){
	return (abs(x - toX) + abs(y - toY));
}

bool Position::targetted(int x, int y){
	return (this->x == x && this->y == y);
}