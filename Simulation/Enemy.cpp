#include <DxLib.h>
#include "Object.h"

Enemy::Enemy(int x, int y, int id):varpos(x, y){
	this->id = id;
	image = GetColor(255, 0, 0);
	mapsize = 32;
}

void Enemy::update(){
}

void Enemy::draw(){
	DrawBox(varpos.getX(), varpos.getY(), varpos.getX() + mapsize, varpos.getY() + mapsize, image, true);
	DrawFormatString(varpos.getX(), varpos.getY(), GetColor(255,255,255), "%d", id);
}