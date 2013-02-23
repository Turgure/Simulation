#include <DxLib.h>
#include "Object.h"
#include "Cursor.h"
#include "Event.h"
#include "Stage.h"

Enemy::Enemy(int x, int y, int id, int hp, int mp, int str, int def, int agi):varpos(x, y){
	status.image = GetColor(255, 0, 0);
	status.id = id;
	status.maxhp = hp, status.hp = status.maxhp;
	status.maxmp = mp, status.mp = status.maxmp;
	status.str = str;
	status.def = def;
	status.agi = agi;
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
	++cnt;
}

void Enemy::EndMyTurn(){
	cnt = 0;
	ATBgauge =  100;
}

bool Enemy::isCntOver(){
	return (cnt >= 20000);
}
