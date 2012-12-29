#include <DxLib.h>
#include "BattleScene.h"
#include "Keyboard.h"
#include "Cursor.h"

BattleScene::BattleScene():cursor(5, 8){
	phase = PLAYER;
}

void BattleScene::initialize(){
	turn = 1;
	stage.initialize();
	players.push_back( Player(4, 3, players.size()) );
	for(int i = 0; i < 5; i++){
		int j = GetRand(9);
		int k = GetRand(9);
		enemies.push_back( Enemy(j, k, enemies.size()) );
	}
}

void BattleScene::update(){
	switch(phase){
	case PLAYER:
		for(auto& player : players){
			player.update();
			player.attack(enemies);
		}
		cursor.update();
		break;
	case ENEMY:
		phase = PLAYER;
		break;
	case NEUTRAL:
		phase = PLAYER;
		for(auto& player : players) player.react();
		++turn;
		break;
	}

	auto enemy = enemies.begin();
	while(enemy != enemies.end()){
		if(enemy->getHP() <= 0){
			enemy = enemies.erase(enemy);
		} else {
			enemy++;
		}
	}


	if(Keyboard::get(KEY_INPUT_9) == 1) phase = NEUTRAL;

	//if(enemies.empty())
		//changeScene(new homeScene)
}

void BattleScene::draw(){
	DrawFormatString(0, 0, GetColor(255,255,255), "turn : %d", turn);
	DrawFormatString(0, 16, GetColor(255,255,255), "phase : %d", phase);
	DrawString(0, 32, "change phase : key 9", GetColor(255,255,255));

	stage.draw();

	for(auto player : players){
		player.draw();
	}
	for(auto enemy : enemies){
		enemy.draw();
	}

	cursor.draw();
}