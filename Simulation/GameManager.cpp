#include <DxLib.h>
#include "GameManager.h"
#include "Keyboard.h"

GameManager::GameManager(): cursor(132, 132){
}

void GameManager::create(){
	players.push_back(Player(100, 100) );

	for(int i = 5; i > 0; i--){
		int j = GetRand(8);
		enemies.push_back( Enemy(100 + i*32, 100 + 32*j) );
	}
}

void GameManager::update(){
	stageScene.update();

	for(auto player : players)
		player.update();
	for(auto enemy : enemies)
		enemy.update();
	
	//static int count = 0;
	//if(Keyboard::get(KEY_INPUT_Z) == 1){
	//	players.push_back( Player(100 + 32*GetRand(count), 100 + 32*GetRand(count)) );
	//	count++;
	//	count %= 10;
	//}

	cursor.update();
}

void GameManager::draw(){
	stageScene.draw();

	for(auto player : players)
		player.draw();
	for(auto enemy : enemies)
		enemy.draw();
	
	cursor.draw();
}