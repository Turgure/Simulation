﻿#include <DxLib.h>
#include "BattleScene.h"
#include "HomeScene.h"
#include "Keyboard.h"
#include "Cursor.h"

BattleScene::BattleScene():cursor(5, 5){
	isMoving = false;
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

	for(auto& player : players){
		//check
		if(player.isMyTurn())
			isMoving = true;
		//sub ATBgauge
		if(!isMoving)
			player.update();
	}
	for(auto& enemy : enemies){
		//check
		if(enemy.isMyTurn())
			isMoving = true;
		//sub ATBgauge
		if(!isMoving)
			enemy.update();
	}

	//do action
	if(isMoving){
		for(auto& player : players){
			if(player.isMyTurn()){
				player.doAction();
				player.attack(enemies);
				if(Keyboard::get(KEY_INPUT_9) == 1){
					player.EndMyTurn();
					player.react();
					isMoving = false;
				}
			}
		}

		for(auto& enemy : enemies){
			if(enemy.isMyTurn()){
				while(!enemy.isCntOver()){
					enemy.doAction();
				}
				enemy.EndMyTurn();
				isMoving = false;
				break;
			}
		}

		cursor.update();
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
	if(!isMoving) DrawString(0, 32, "waiting...", GetColor(255,255,255));

	stage.draw();

	for(auto& player : players){
		player.draw();
	}
	for(auto& enemy : enemies){
		enemy.draw();
	}

	cursor.draw();
}