#include <DxLib.h>
#include "Object.h"
#include "Cursor.h"
#include "Event.h"
#include "MapchipDefinition.h"

Enemy::Enemy(int x, int y, int id):varpos(x, y){
	status.maxhp = 3;
	status.hp = status.maxhp;
	status.id = id;
	status.image = GetColor(255, 0, 0);
}

void Enemy::update(){
}

void Enemy::draw(){
	Event::DrawGraphOnMap(varpos.getX(), varpos.getY(), status.image);

	if(varpos.targetted(Cursor::getX(), Cursor::getY())){
		DrawFormatString(0, 100, GetColor(255,255,255), "enemy : %d", status.id);
		DrawFormatString(0, 116, GetColor(255,255,255), "hp %d", status.hp);
	}
}

void Enemy::setHP(int hp){ status.hp = hp; }
int Enemy::getHP() const { return status.hp; }