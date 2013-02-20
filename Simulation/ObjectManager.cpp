#include <stdio.h>
#include "ObjectManager.h"

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
