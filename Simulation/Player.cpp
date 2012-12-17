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
	if(canAct()){
	}
}

void Player::draw(){
	//ÉvÉåÉCÉÑÅ[ÇÃï`âÊ
	DrawBox(x, y, x + mapsize, y + mapsize, image, true);
	DrawFormatString(x, y, GetColor(255,255,255), "%d", id);
	DrawFormatString(100, 0, GetColor(255,255,255), "%d", command);

	switch(command){
	case MOVE://à⁄ìÆîÕàÕ
		break;
	}

}

bool Player::canAct(){
	if(can_act) return true;
	else return false;
}

void Player::showCommand(){
	DrawFormatString(0, 16, GetColor(255,255,255), "player %d", id);
	switch(command){
	case SELECT:
		DrawFormatString(0, 32, GetColor(255,255,255), "MOVE   : key 1");
		DrawFormatString(0, 48, GetColor(255,255,255), "ATTACK : key 2");
		DrawFormatString(0, 64, GetColor(255,255,255), "END    : key 3");
		break;
	}
}

void Player::act(){
	switch(command){
	case SELECT:
		showCommand();
		Event::lineFour(pos.getX(), pos.getY());
		if(Keyboard::get(KEY_INPUT_1) == 1) command = MOVE;
		if(Keyboard::get(KEY_INPUT_2) == 1) command = ATTACK;
		if(Keyboard::get(KEY_INPUT_3) == 1) command = END;
		break;
	case MOVE:
		break;
	case ATTACK:
		break;
	case END:
		can_act = false;
		break;
	}
}