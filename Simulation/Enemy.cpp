#include <DxLib.h>
#include "Object.h"
#include "Cursor.h"
#include "Event.h"
#include "Stage.h"

Enemy::Enemy(int x, int y, int id, int hp, int mp, int str, int def, int agi, int mobility):varpos(x, y){
	status.image = GetColor(255, 0, 0);
	status.id = id;
	status.maxhp = hp, status.hp = status.maxhp;
	status.maxmp = mp, status.mp = status.maxmp;
	status.str = str;
	status.def = def;
	status.agi = agi;
	status.mobility = mobility;
	state = SELECT;
	ATBgauge = 100;
	cnt = 0;
}

void Enemy::update(){
	ATBgauge -= status.agi;
}

void Enemy::draw(){
	Event::DrawGraphOnMap(varpos.getXByMap(), varpos.getYByMap(), status.image);
	//show id
	DrawFormatString(varpos.getXByPx(), varpos.getYByPx(), GetColor(255,255,255), "%d", status.id);

	if(varpos.targetted(Cursor::pos().getXByMap(), Cursor::pos().getYByMap())){
		showStatus(status);
	}
}

void Enemy::doAction(){
	DrawFormatString(0, 80, GetColor(255,255,255), "enemy %d's turn.", status.id);
	showStatus(status);

	switch(state){
	case SELECT:
		Stage::eraseBrightPoints();
		state = MOVE;
		break;

	case MOVE:
		Event::range(varpos.getXByMap(), varpos.getYByMap(), status.mobility, true);

		int x, y;
		do{
			x = GetRand(Stage::getWidth());
			y = GetRand(Stage::getHeight());
		}while(!Stage::getBrightPoints(x, y));
		
		Cursor::set(x, y);
		can_move = false;
		state = WAIT;
		break;

	case ACTION:
		//attack(players);
		state = END;
		break;

	case END:
		can_move = false;
		can_act = false;
		Stage::eraseBrightPoints();
		break;

	case WAIT:
		if(++cnt > 30){
			varpos.setXYByMap(Cursor::pos().getXByMap(), Cursor::pos().getYByMap());
			if(!can_move){
				if(!can_act){ state = END; break; }
				else { state = ACTION; break; }
			}
			if(!can_act) state = MOVE;
		}
		break;
	}

	if(!can_move && !can_act){
		state = END;
	}
}

void Enemy::EndMyTurn(){
	state = SELECT;
	ATBgauge =  100;
	cnt = 0;
}

bool Enemy::isCntOver(){
	return (cnt >= 30);
}
