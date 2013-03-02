#include <math.h>
#include <DxLib.h>
#include "BattleScene.h"
#include "HomeScene.h"
#include "Keyboard.h"
#include "Cursor.h"
#include "Event.h"

BattleScene::BattleScene():cursor(0, 0){
	has_come_turn = false;
	act_only_one = false;
}

void BattleScene::initialize(){
	turn = 1;
	stage.initialize();

	ObjectManager::create(players, "data/chara/player1.csv", 3, 7);
	ObjectManager::create(players, "data/chara/player2.csv", 6, 7);

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

	//action
	while(has_come_turn){
		for(auto& player : players){
			if(!player.isMyTurn()) continue;
			act_only_one = true;

			player.action();
			player.attack(enemies);
			if(Keyboard::get(KEY_INPUT_9) == 1){
				player.endMyTurn();
				has_come_turn = false;
				act_only_one = false;
			}
			break;
		}
		//敵との重複を避ける
		if(act_only_one) break;

		for(auto& enemy : enemies){
			if(!enemy.isMyTurn()) continue;

			if(enemy.getState() == 0){
				enemy.calcMove(players);
				enemy.calcAttack(players);
			}
			enemy.action();
			enemy.attack(players);

			if(enemy.getState() == 3){
				enemy.endMyTurn();
				has_come_turn = false;
			}
			break;
		}
		break;
	}

	//++turn;

	//delete
	auto player = players.begin();
	while(player != players.end()){
		if(player->getHP() <= 0){
			player = players.erase(player);
		} else {
			player++;
		}
	}
	auto enemy = enemies.begin();
	while(enemy != enemies.end()){
		if(enemy->getHP() <= 0){
			enemy = enemies.erase(enemy);
		} else {
			enemy++;
		}
	}

	//change scene
	if(players.empty() || enemies.empty()){
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