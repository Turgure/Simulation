#include <DxLib.h>
#include "Object.h"

bool BaseObject::isMyTurn(){
	if(ATBgauge <= 0){
		ATBgauge = 0;
		return true;
	}
	else return false;
}

void BaseObject::showStatus(Status st){
	DrawFormatString(200,  0, GetColor(255,255,255), "id  %d", st.id);
	DrawFormatString(200, 16, GetColor(255,255,255), "hp  %d/%d", st.hp, st.maxhp);
	DrawFormatString(200, 32, GetColor(255,255,255), "mp  %d/%d", st.mp, st.maxmp);
	DrawFormatString(200, 48, GetColor(255,255,255), "str %d", st.str);
	DrawFormatString(200, 64, GetColor(255,255,255), "def %d", st.def);
	DrawFormatString(200, 80, GetColor(255,255,255), "agi %d", st.agi);
}


int ObjectManager::id;
int ObjectManager::hp;
int ObjectManager::mp;
int ObjectManager::str;
int ObjectManager::def;
int ObjectManager::agi;
FILE* ObjectManager::fp;
int ObjectManager::ret;

void ObjectManager::create(vector<Player> &players, const char* file, int x, int y){
	fp = fopen(file, "r");
	if(fp != NULL){
		if((ret = fscanf(fp, "%d, %d, %d, %d, %d, %d", &id, &hp, &mp, &str, &def, &agi)) != EOF){
			players.push_back( Player(x, y, id, hp, mp, str, def, agi) );
		}
	}
	fclose(fp);
}

void ObjectManager::create(vector<Enemy> &enemies, const char* file, int x, int y){
	fp = fopen(file, "r");
	if(fp != NULL){
		if((ret = fscanf(fp, "%d, %d, %d, %d, %d, %d", &id, &hp, &mp, &str, &def, &agi)) != EOF){
			enemies.push_back( Enemy(x, y, id, hp, mp, str, def, agi) );
		}
	}
	fclose(fp);
}