#include <DxLib.h>
#include "Object.h"
#include "Keyboard.h"
#include "Cursor.h"
#include "Event.h"
#include "Stage.h"
#include "MapchipDefinition.h"

Player::Player(int x, int y, int id):varpos(x, y){
	this->id = id;
	image = GetColor(0, 0, 255);
	state = SELECT;
	can_act = true;
	can_move = true;
	can_attack = true;
}

void Player::update(){
	switch(state){
		if(can_act){
	case SELECT:
		Stage::eraseBrightPoints();
		if(varpos.targetted(Cursor::getX(), Cursor::getY())){
			if(Keyboard::get(KEY_INPUT_1) == 1 && can_move) state = MOVE;
			if(Keyboard::get(KEY_INPUT_2) == 1 && can_attack) state = ATTACK;
			if(Keyboard::get(KEY_INPUT_3) == 1) state = END;
		}
		break;

	case MOVE:
		if(Keyboard::get(KEY_INPUT_3) == 1) state = SELECT;
		if(Keyboard::get(KEY_INPUT_1) == 1){
			state = SELECT;
			if(Stage::getBrightPoints(Cursor::getX(), Cursor::getY())){
				can_move = false;
				varpos.setXY(Cursor::getX(), Cursor::getY());
			}
		}
		break;

	case ATTACK:
		//attack(enemies);
		break;
		}

	case END:
		can_act = false;
		can_move = false;
		can_attack = false;
		Stage::eraseBrightPoints();
		break;
	}

	if(!can_move && !can_attack){
		state = END;
	}
}

void Player::draw(){
	Event::DrawGraphOnMap(varpos.getX(), varpos.getY(), image);
	if(varpos.targetted(Cursor::getX(), Cursor::getY())){
		DrawFormatString(200,  0, GetColor(255,255,255), "player : %d", id);
	}

	showCommand();

	switch(state){
	case SELECT:
		break;
	case MOVE:
		Event::range(varpos.getX(), varpos.getY(), 5);
		break;
	case ATTACK:
		Event::spotReachTo(varpos.getX(), varpos.getY(), 1, 3);
		break;
	}
}

void Player::showCommand(){
	switch(state){
	case SELECT:
		if(varpos.targetted(Cursor::getX(), Cursor::getY())){
			if(can_move){
				DrawString(200,  16, "MOVE   : key 1", GetColor(255,255,255));
			}
			if(can_attack){
				DrawString(200, 32, "ATTACK : key 2", GetColor(255,255,255));
			}
			DrawString(200, 48, "END    : key 3", GetColor(255,255,255));
		}
		break;
	case MOVE:
		DrawString(200, 16, "where?", GetColor(255,255,255));
		DrawString(200, 32, "assign : key 1", GetColor(255,255,255));
		DrawString(200, 48, "cancel : key 3", GetColor(255,255,255));
		break;
	case ATTACK:
		DrawString(200, 16, "to whom?", GetColor(255,255,255));
		DrawString(200, 32, "assign : key 1", GetColor(255,255,255));
		DrawString(200, 48, "cancel : key 3", GetColor(255,255,255));
		break;
	case END:
		if(varpos.targetted(Cursor::getX(), Cursor::getY())) 
			DrawString(200, 16, "end.", GetColor(255,255,255));
		break;
	}
}

void Player::react(){
	state = SELECT;
	can_act = true;
	can_move = true;
	can_attack = true;
}

void Player::attack(vector<Enemy>& enemies){
	if(state != ATTACK) return;

	if(Keyboard::get(KEY_INPUT_3) == 1) state = SELECT;
	if(Keyboard::get(KEY_INPUT_1) == 1){
		state = SELECT;
		for(auto& enemy : enemies){
			if(Stage::getBrightPoints(Cursor::getX(), Cursor::getY())){
				if(enemy.pos().targetted(Cursor::getX(), Cursor::getY())){
					can_attack = false;
					enemy.setHP(enemy.getHP() - 1);
					break;
				}
			}
		}
	}
}