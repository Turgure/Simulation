#include <DxLib.h>
#include "Object.h"
#include "Keyboard.h"
#include "Event.h"

Player::Player(int x, int y, int id):pos(x, y){
	this->x = x, this->y = y, this->id = id;
	image = GetColor(0, 0, 255);
	mapsize = 32;
	command = SELECT;
	can_act = true;
}

void Player::update(){
}

void Player::draw(){
	//ÉvÉåÉCÉÑÅ[ÇÃï`âÊ
	DrawBox(x, y, x + mapsize, y + mapsize, image, true);
	DrawFormatString(x, y, GetColor(255,255,255), "%d", id);

	switch(command){
	case MOVE://à⁄ìÆîÕàÕ
		break;
	}

}

void Player::showCommand(){
	DrawFormatString(0, 16, GetColor(255,255,255), "player %d", id);
	DrawFormatString(0, 32, GetColor(255,255,255), "SELECT : key 1");
	DrawFormatString(0, 48, GetColor(255,255,255), "MOVE   : key 2");
	DrawFormatString(0, 64, GetColor(255,255,255), "ATTACK : key 3");
	DrawFormatString(0, 80, GetColor(255,255,255), "END    : key 4");
}

void Player::act(){
	if(can_act){
		showCommand();
		if(Keyboard::get(KEY_INPUT_1) == 1) command = SELECT;
		if(Keyboard::get(KEY_INPUT_2) == 1) command = MOVE;
		if(Keyboard::get(KEY_INPUT_3) == 1) command = ATTACK;
		if(Keyboard::get(KEY_INPUT_4) == 1) command = END;

		switch(command){
		case SELECT:
			break;
		case MOVE:
			Event::range(pos.getX(), pos.getY(), 5);
			break;
		case ATTACK:
			Event::spotReachTo(pos.getX(), pos.getY(), 2);
			Event::spotReachTo(pos.getX(), pos.getY(), 3);
			break;
		case END:
			can_act = false;
			break;
		}
	}
}