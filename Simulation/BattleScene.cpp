#include <DxLib.h>
#include "BattleScene.h"
#include "HomeScene.h"
#include "Keyboard.h"
#include "Cursor.h"

BattleScene::BattleScene():cursor(5, 8){
	cnt = 0;
	isMoving = false;
}

void BattleScene::initialize(){
	turn = 1;
	stage.initialize();

	ObjectManager::create(players, "data/chara/player1.csv", 4, 3);
	ObjectManager::create(players, "data/chara/player2.csv", 5, 3);

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
	//check
	for(auto& player : players){
		if(player.isMyTurn()){
			isMoving = true;
		}
	}
	for(auto& enemy : enemies){
		if(enemy.isMyTurn()){
			isMoving = true;
		}
	}

	//add ATBgage
	if(!isMoving){
		for(auto& player : players){
			player.update();
		}
		for(auto& enemy : enemies){
			enemy.update();
		}
	}
	//do action
	else {
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