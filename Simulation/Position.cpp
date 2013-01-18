#include <DxLib.h>
#include "Position.h"

Position::Position(int x, int y){
	this->x = x, this->y = y;
}

void Position::setX(int toX){ x = toX; }
void Position::setY(int toY){ y = toY; }
int Position::getX() const { return x; }
int Position::getY() const { return y; }

void Position::setXY(int toX, int toY){
	x = toX, y = toY;
}

void Position::Move(int diffX, int diffY){
	x += diffX, y += diffY;
}

bool Position::targetted(int x, int y){
	if(this->x == x && this->y == y){
		return true;
	} else {
		return false;
	}
}