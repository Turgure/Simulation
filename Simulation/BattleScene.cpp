#include <DxLib.h>
#include "BattleScene.h"
#include "Keyboard.h"
#include "Cursor.h"

BattleScene::BattleScene():cursor(100+32*5, 100+32*8){
	phase = PLAYER;
}

void BattleScene::initialize(){
	turn = 1;
	//Map::create();

	for(int i = 0; i < 1; i++){
		players.push_back( Player(100 + (i+4)*32, 100 + (i+4)*32, players.size()) );
	}

	for(int i = 0; i < 5; i++){
		int j = GetRand(8);
		enemies.push_back( Enemy(100 + i*32, 100 + 32*j, enemies.size()) );
	}
}

void BattleScene::update(){
	switch(phase){
	case PLAYER:
		for(auto& player : players){
			player.update();
		}
		cursor.update();
		break;
	case ENEMY:
		phase = PLAYER;
		break;
	case NEUTRAL:
		phase = PLAYER;
		for(auto& player :players) player.react();
		++turn;
		break;
	}

	if(Keyboard::get(KEY_INPUT_9) == 1) phase = NEUTRAL;

	//if(enemies.empty())
	//changeScene(new homeScene)
}

void BattleScene::draw(){
	DrawFormatString(0, 0, GetColor(255,255,255), "turn : %d", turn);
	DrawFormatString(0, 16, GetColor(255,255,255), "phase : %d", phase);
	DrawString(0, 32, "change phase : key 9", GetColor(255,255,255));

	map.draw();

	for(auto& player : players){
		player.draw();
	}
	for(auto& enemy : enemies){
		enemy.draw();
	}

	cursor.draw();
}