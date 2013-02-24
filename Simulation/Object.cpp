#include <DxLib.h>
#include "Object.h"
#include "FileStream.h"
#include "Stage.h"

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
	DrawFormatString(200, 94, GetColor(255,255,255), "mob %d", st.mobility);
}


void ObjectManager::create(vector<Player> &players, string filename, int x, int y){
	vector<string> status;
	FileStream::load(filename, status);

	//intŒ^‚É•ÏŠ·
	vector<int> d;
	for(auto& s : status){
		d.push_back(atoi(s.c_str()));
	}
	players.push_back( Player(x, y, d[0], d[1], d[2], d[3], d[4], d[5], d[6]) );
}

void ObjectManager::create(vector<Enemy> &enemies, string filename){
	vector<vector<string>> status;
	FileStream::load(filename, status);
	
	int x, y;

	//intŒ^‚É•ÏŠ·
	int d[256][256];
	for(unsigned int i = 0; i < status.size(); ++i){
		for(unsigned int j = 0; j < status[i].size(); ++j){
			d[i][j] = atoi(status[i][j].c_str());
		}

		do{
			x = GetRand(9);
			y = GetRand(9);
		}while(!Stage::canMove(x, y));
		enemies.push_back( Enemy(x, y, d[i][0], d[i][1], d[i][2], d[i][3], d[i][4], d[i][5], d[i][6]) );
	}
}