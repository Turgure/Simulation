#include <DxLib.h>
#include "BattleScene.h"
#include "HomeScene.h"
#include "Keyboard.h"
#include "Cursor.h"

BattleScene::BattleScene():cursor(5, 5){
	has_come_turn = false;
	act_only_one = false;
}

void BattleScene::initialize(){
	turn = 1;
	stage.initialize();

	ObjectManager::create(players, "data/chara/player1.csv", 4, 3);
	ObjectManager::create(players, "data/chara/player2.csv", 5, 3);

	ObjectManager::create(enemies, "data/stage/stage2/enemy.csv");
}

void BattleScene::update(){
	stage.update();
	cursor.update();

	//calculate
	while(!has_come_turn){
		for(auto& player : players){
			//sub ATBgauge
			player.update();

			//check
			if(player.isMyTurn()){
				has_come_turn = true;
				cursor.set(player.pos().getXByMap(), player.pos().getYByMap());
				break;
			}
		}
		//敵との重複を避ける
		if(has_come_turn) break;

		for(auto& enemy : enemies){
			//sub ATBgauge
			enemy.update();

			//check
			if(enemy.isMyTurn()){
				has_come_turn = true;
				cursor.set(enemy.pos().getXByMap(), enemy.pos().getYByMap());
				break;
			}
		}
		break;
	}

	//do action
	while(has_come_turn){
		for(auto& player : players){
			if(!player.isMyTurn()) continue;
			act_only_one = true;

			player.doAction();
			player.attack(enemies);
			if(Keyboard::get(KEY_INPUT_9) == 1){
				player.EndMyTurn();
				player.react();
				has_come_turn = false;
				act_only_one = false;
			}
			break;
		}
		//敵との重複を避ける
		if(act_only_one) break;

		for(auto& enemy : enemies){
			if(!enemy.isMyTurn()) continue;

			enemy.doAction();
			if(enemy.getState() == 3){
				enemy.EndMyTurn();
				has_come_turn = false;
			}
			break;
		}
		break;
	}

	//++turn;

	//delete
	auto enemy = enemies.begin();
	while(enemy != enemies.end()){
		if(enemy->getHP() <= 0){
			enemy = enemies.erase(enemy);
		} else {
			enemy++;
		}
	}

	//change scene
	if(enemies.empty()){
		changeScene(new HomeScene);
	}
}

void BattleScene::draw(){
	DrawFormatString(0, 0, GetColor(255,255,255), "turn : %d", turn);
	DrawString(0, 16, "turn end : key 9", GetColor(255,255,255));
	if(!has_come_turn) DrawString(0, 32, "waiting...", GetColor(255,255,255));

	stage.draw();
	cursor.draw();

	for(auto& player : players){
		player.draw();
	}
	for(auto& enemy : enemies){
		enemy.draw();
	}
}