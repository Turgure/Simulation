#include <DxLib.h>
#include "BattleScene.h"
#include "HomeScene.h"
#include "Keyboard.h"
#include "Cursor.h"

BattleScene::BattleScene():cursor(5, 8){
	phase = PLAYER;
}

void BattleScene::initialize(){
	turn = 1;
	stage.initialize();
	
	ObjectManager::create(players);

	for(int i = 0; i < 5; i++){
		int x, y;
		do{
			x = GetRand(9);
			y = GetRand(9);
		}while(!stage.canMove(x, y));

		enemies.push_back( Enemy(x, y, enemies.size(), 3, 3, 3, 3, 3) );
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
	
	if(enemies.empty()){
		changeScene(new HomeScene);
	}
}

void BattleScene::draw(){
	DrawFormatString(0, 0, GetColor(255,255,255), "turn : %d", turn);
	DrawFormatString(0, 16, GetColor(255,255,255), "phase : %d", phase);
	DrawString(0, 32, "change phase : key 9", GetColor(255,255,255));

	stage.draw();

	for(auto& player : players){
		player.draw();
	}
	for(auto& enemy : enemies){
		enemy.draw();
	}

	cursor.draw();
}