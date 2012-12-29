#include <DxLib.h>
#include "Object.h"
#include "Cursor.h"
#include "Event.h"
#include "MapchipDefinition.h"

Enemy::Enemy(int x, int y, int id):varpos(x, y){
	hp = 3;
	this->id = id;
	image = GetColor(255, 0, 0);
}

void Enemy::update(){
}

void Enemy::draw(){
	Event::DrawGraphOnMap(varpos.getX(), varpos.getY(), image);

	if(varpos.targetted(Cursor::getX(), Cursor::getY())){
		DrawFormatString(0, 100, GetColor(255,255,255), "enemy : %d", id);
		DrawFormatString(0, 116, GetColor(255,255,255), "hp %d", hp);
	}
}

void Enemy::setHP(int hp){ this->hp = hp; }
int Enemy::getHP() const { return hp; }