#include <DxLib.h>
#include "Object.h"
#include "Keyboard.h"
#include "Cursor.h"
#include "Event.h"

Player::Player(int x, int y, int id):varpos(x, y){
	this->id = id;
	image = GetColor(0, 0, 255);
	mapsize = 32;
	command = SELECT;
	can_act = true;
}

void Player::update(){
	if(can_act){
		switch(command){
		case SELECT:
			break;
		case MOVE:
		case ATTACK:
			if(Keyboard::get(KEY_INPUT_1) == 1) command = SELECT;
			if(Keyboard::get(KEY_INPUT_2) == 1){
				command = END;
				varpos.setXY(Cursor::getX(), Cursor::getY());
			}
			break;
		case END:
			break;
		}
	}
}

void Player::draw(){
	//ÉvÉåÉCÉÑÅ[ÇÃï`âÊ
	DrawBox(varpos.getX(), varpos.getY(), varpos.getX() + mapsize, varpos.getY() + mapsize, image, true);
	DrawFormatString(varpos.getX(), varpos.getY(), GetColor(255,255,255), "%d", id);
	showCommand();

	switch(command){
	case SELECT:
		break;
	case MOVE:
		Event::range(varpos.getX(), varpos.getY(), 5);
		break;
	case ATTACK:
		Event::spotReachTo(varpos.getX(), varpos.getY(), 2);
		Event::spotReachTo(varpos.getX(), varpos.getY(), 3);
		break;
	}
}

void Player::showCommand(){
	DrawFormatString(0, 16, GetColor(255,255,255), "player %d", id);
	switch(command){
	case SELECT:
		DrawString(0, 48, "MOVE   : key 2", GetColor(255,255,255));
		DrawString(0, 64, "ATTACK : key 3", GetColor(255,255,255));
		DrawString(0, 80, "END    : key 4", GetColor(255,255,255));
		break;
	case MOVE:
		DrawString(0, 48, "where?", GetColor(255,255,255));
		DrawString(0, 64, "cancel : key 1", GetColor(255,255,255));
		DrawString(0, 80, "assign : key 2", GetColor(255,255,255));
		break;
	case ATTACK:
		DrawString(0, 48, "to whom?", GetColor(255,255,255));
		DrawString(0, 64, "cancel : key 1", GetColor(255,255,255));
		DrawString(0, 80, "assign : key 2", GetColor(255,255,255));
		break;
	case END:
		DrawString(0, 48, "end.", GetColor(255,255,255));
		break;
	}
}

void Player::act(){
	if(can_act){
		switch(command){
		case SELECT:
			if(Keyboard::get(KEY_INPUT_2) == 1) command = MOVE;
			if(Keyboard::get(KEY_INPUT_3) == 1) command = ATTACK;
			if(Keyboard::get(KEY_INPUT_4) == 1) command = END;
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
}