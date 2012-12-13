#include <DxLib.h>
#include "GameManager.h"
#include "Keyboard.h"

GameManager::GameManager(): cursor(132, 132){
}

void GameManager::create(){
	//map.load();
	
}

void GameManager::update(){
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
	map.draw();

	for(auto player : players)
		player.draw();
	for(auto enemy : enemies)
		enemy.draw();
	
	cursor.draw();
}