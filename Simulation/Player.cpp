#include <DxLib.h>
#include "Object.h"

Player::Player(int x, int y, int id){
	this->x = x, this->y = y, this->id = id;
	image = GetColor(0, 0, 255);
	mapsize = 32;
	command = MOVE;
}

void Player::update(){
}

void Player::draw(){
	DrawBox(x, y, x + mapsize, y + mapsize, image, true);
	DrawFormatString(x, y, GetColor(255,255,255), "%d", id);
}

void Player::showCommand(){
	DrawFormatString(0, 16, GetColor(255,255,255), "player %d", id);
	DrawFormatString(0, 32, GetColor(255,255,255), "MOVE   : key 1");
	DrawFormatString(0, 48, GetColor(255,255,255), "ATTACK : key 2");
	DrawFormatString(0, 64, GetColor(255,255,255), "END    : key 3");
	switch(command){
	case MOVE:
		break;
	case ATTACK:
		break;
	case END:
		break;
	}
}
