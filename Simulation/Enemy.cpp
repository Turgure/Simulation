#include <DxLib.h>
#include "Enemy.h"

Enemy::Enemy(int x, int y){
	this->x = x, this->y = y;
	image = GetColor(255, 0, 0);
	mapsize = 32;
}

void Enemy::update(){
}

void Enemy::draw(){
	DrawBox(x, y, x + mapsize, y + mapsize, image, true);
}