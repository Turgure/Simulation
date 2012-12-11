#include <DxLib.h>
#include "Player.h"

Player::Player(int x, int y){
	this->x = x, this->y = y;
	image = GetColor(0, 0, 255);
	mapsize = 32;
}

void Player::update(){
}

void Player::draw(){
	DrawBox(x, y, x + mapsize, y + mapsize, image, true);
}