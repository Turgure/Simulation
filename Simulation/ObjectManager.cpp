#include <stdio.h>
#include "ObjectManager.h"

int ObjectManager::id;
int ObjectManager::hp;
int ObjectManager::mp;
int ObjectManager::str;
int ObjectManager::def;
int ObjectManager::agi;
int ObjectManager::ret;
FILE* ObjectManager::fp;

void ObjectManager::create(vector<Player> &players){
	fp = fopen("data/chara/player1.csv", "r");
	if(fp != NULL){
		if((ret = fscanf(fp, "%d, %d, %d, %d, %d, %d", &id, &hp, &mp, &str, &def, &agi)) != EOF){
			players.push_back( Player(4, 3, id, hp, mp, str, def, agi) );
		}
	}
	fclose(fp);
}


void ObjectManager::create(vector<Enemy> &enemies){
	fp = fopen("data/stage/enemy.csv", "r");
	if(fp != NULL){
		if((ret = fscanf(fp, "%d, %d, %d, %d, %d, %d", &id, &hp, &mp, &str, &def, &agi)) != EOF){
			enemies.push_back( Enemy(4, 3, id, hp, mp, str, def, agi) );
		}
	}
	fclose(fp);
}