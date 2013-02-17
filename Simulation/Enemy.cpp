#include <DxLib.h>
#include "Object.h"
#include "Cursor.h"
#include "Event.h"
#include "MapchipDefinition.h"

Enemy::Enemy(int x, int y, int id, int hp, int mp, int str, int def, int agi):varpos(x, y){
	status.image = GetColor(255, 0, 0);
	status.id = id;
	status.maxhp = hp, status.hp = status.maxhp;
	status.maxmp = mp, status.mp = status.maxmp;
	status.str = str;
	status.def = def;
	status.agi = agi;
}

void Enemy::update(){
}

void Enemy::draw(){
	Event::DrawGraphOnMap(varpos.getX(), varpos.getY(), status.image);

	if(varpos.targetted(Cursor::getX(), Cursor::getY())){
		showStatus(status);
	}
}
