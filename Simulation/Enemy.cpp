#include <DxLib.h>
#include "Object.h"
#include "Cursor.h"
#include "Event.h"
#include "Stage.h"

Enemy::Enemy(int x, int y, int id, int hp, int mp, int str, int def, int agi, int mobility):varpos(x, y), calcpos(x, y){
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
	wait_time = 0;
	attack_range = 3;
}

void Enemy::update(){
	ATBgauge -= status.agi;
}

void Enemy::draw(){
	Event::DrawGraphOnMap(varpos.getXByMap(), varpos.getYByMap(), status.image);
	//show id on object
	DrawFormatString(varpos.getXByPx(), varpos.getYByPx(), GetColor(255,255,255), "%d", status.id);

	if(varpos.targetted(Cursor::pos().getXByMap(), Cursor::pos().getYByMap())){
		showStatus(status);
	}
}

void Enemy::action(){
	DrawFormatString(0, 48, GetColor(255,255,255), "enemy %d's turn.", status.id);

	switch(state){
	case SELECT:
		Stage::eraseBrightPoints();
		if(can_move) state = MOVE;
		else if(can_act) state = ACTION;
		break;

	case MOVE:
		//calcMove(player.pos());
		Cursor::set(calcpos.getXByMap(), calcpos.getYByMap());
		state = WAIT;
		break;

	case ACTION:
		//calcAttack(players);
		Cursor::set(calcpos.getXByMap(), calcpos.getYByMap());
		state = WAIT;
		//attack(players);
		break;

	case END:
		can_move = false;
		can_act = false;
		Stage::eraseBrightPoints();
		break;

	case WAIT:
		if(isCountOver(30)){
			if(can_move){
				can_move = false;
				wait_time = 0;
				varpos.setByMap(Cursor::pos().getXByMap(), Cursor::pos().getYByMap());
				Stage::eraseBrightPoints();
				state = SELECT;
			} else if(can_act){
				can_act = false;
				state = END;
			}
		}
		break;
	}
}

void Enemy::endMyTurn(){
	state = SELECT;
	ATBgauge =  100;
	wait_time = 0;
	can_move = true;
	can_act = true;
}

bool Enemy::isCountOver(int time){
	return (++wait_time > time);
}

void Enemy::calcMove(vector<Player>& players){
	if(state != MOVE) return;
	Event::range(varpos.getXByMap(), varpos.getYByMap(), status.mobility, true);

	int finalX = -1, finalY = -1;
	int dist = INT_MAX, diff;

	for(int y = 0; y < Stage::getHeight(); ++y){
		for(int x = 0; x < Stage::getWidth(); ++x){
			if(!Stage::getBrightPoint(x, y)) continue;

			for(auto& player : players){
				diff = varpos.getDistByMap(x, y, player.pos().getXByMap(), player.pos().getYByMap());
				//最適な間合い（？）
				if(diff == attack_range){
					finalX = x, finalY = y;
					calcpos.setByMap(finalX, finalY);
					return;
				}
				
				if(diff <= dist){
					finalX = x, finalY = y;
					dist = diff;

				}
			}
		}
	}
	calcpos.setByMap(finalX, finalY);
}

void Enemy::calcAttack(vector<Player>& players){
	if(state != ACTION) return;
	Event::reachTo(varpos.getXByMap(), varpos.getYByMap(), Event::GetColorAttack(), 1, attack_range);

	int finalX = -1, finalY = -1;
	int dist = INT_MAX, diff;

	for(int y = 0; y < Stage::getHeight(); ++y){
		for(int x = 0; x < Stage::getWidth(); ++x){
			if(!Stage::getBrightPoint(x, y)) continue;

			for(auto& player : players){
				diff = varpos.getDistByMap(x, y, player.pos().getXByMap(), player.pos().getYByMap());
				if(diff == 0){
					finalX = x, finalY = y;
					calcpos.setByMap(finalX, finalY);
					return;
				}
			}
		}
	}
	//探索にヒットしなかったら
	calcpos.setByMap(varpos.getXByMap(), varpos.getYByMap());
}

void Enemy::attack(vector<Player>& players){
	if(!can_act) return;

	for(auto& player : players){
		if(Stage::getBrightPoint(Cursor::pos().getXByMap(), Cursor::pos().getYByMap())){
			int diff = status.str - player.getDef();
			if(diff <= 0) continue;

			if(player.pos().targetted(Cursor::pos().getXByMap(), Cursor::pos().getYByMap())){
				player.setHP(player.getHP() - diff);
				break;
			}
		}
	}
}