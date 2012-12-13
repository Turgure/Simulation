#include <DxLib.h>
#include "Object.h"

Enemy::Enemy(int x, int y, int id){
	this->x = x, this->y = y, this->id = id;
	image = GetColor(255, 0, 0);
	mapsize = 32;
}

void Enemy::update(){
}

void Enemy::draw(){
	DrawBox(x, y, x + mapsize, y + mapsize, image, true);
	DrawFormatString(x, y, GetColor(255,255,255), "%d", id);
}