#include <DxLib.h>
#include "Object.h"
#include "Keyboard.h"
#include "Cursor.h"
#include "Event.h"

Player::Player(int x, int y, int id):varpos(x, y){
	this->id = id;
	image = GetColor(0, 0, 255);
	mapsize = 32;
	state = SELECT;
	can_act = true;
}

void Player::update(){
	if(can_act){
		switch(state){
		case SELECT:
			if(varpos.targetted(Cursor::getX(), Cursor::getY())){
				if(Keyboard::get(KEY_INPUT_2) == 1) state = MOVE;
				if(Keyboard::get(KEY_INPUT_3) == 1) state = ATTACK;
				if(Keyboard::get(KEY_INPUT_4) == 1) state = END;
			}
			break;

		case MOVE:
		case ATTACK:
			if(Keyboard::get(KEY_INPUT_1) == 1) state = SELECT;
			if(Keyboard::get(KEY_INPUT_2) == 1){
				state = END;
				varpos.setXY(Cursor::getX(), Cursor::getY());
			}
			break;

		case END:
			can_act = false;
			break;
		}
	}
}

void Player::draw(){
	//ÉvÉåÉCÉÑÅ[ÇÃï`âÊ
	DrawBox(varpos.getX(), varpos.getY(), varpos.getX() + mapsize, varpos.getY() + mapsize, image, true);
	DrawFormatString(varpos.getX(), varpos.getY(), GetColor(255,255,255), "%d", id);

	showCommand();

	switch(state){
	case SELECT:
		break;
	case MOVE:
		Event::rangeInField(varpos.getX(), varpos.getY(), 5);
		break;
	case ATTACK:
		Event::spotReachTo(varpos.getX(), varpos.getY(), 2);
		Event::spotReachTo(varpos.getX(), varpos.getY(), 3);
		break;
	}
}

void Player::showCommand(){
	switch(state){
	case SELECT:
		if(varpos.targetted(Cursor::getX(), Cursor::getY())){
			DrawString(200, 0, "MOVE   : key 2", GetColor(255,255,255));
			DrawString(200, 16, "ATTACK : key 3", GetColor(255,255,255));
			DrawString(200, 32, "END    : key 4", GetColor(255,255,255));
		}
		break;
	case MOVE:
		DrawString(200, 0, "where?", GetColor(255,255,255));
		DrawString(200, 16, "cancel : key 1", GetColor(255,255,255));
		DrawString(200, 32, "assign : key 2", GetColor(255,255,255));
		break;
	case ATTACK:
		DrawString(200, 0, "to whom?", GetColor(255,255,255));
		DrawString(200, 16, "cancel : key 1", GetColor(255,255,255));
		DrawString(200, 32, "assign : key 2", GetColor(255,255,255));
		break;
	case END:
		if(varpos.targetted(Cursor::getX(), Cursor::getY())) 
			DrawString(200, 0, "end.", GetColor(255,255,255));
		break;
	}
}

void Player::react(){
	state = SELECT;
	can_act = true;
}