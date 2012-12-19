#include <DxLib.h>
#include "BattleScene.h"
#include "Keyboard.h"
#include "Cursor.h"

BattleScene::BattleScene():cursor(100+32*5, 100+32*8){}

void BattleScene::initialize(){
	turn = 1;
	//Map::create();

	for(int i = 0; i < 1; i++){
		players.push_back( Player(196 + i*32, 196 + i*32, players.size()) );
	}
	
	for(int i = 0; i < 5; i++){
		int j = GetRand(8);
		enemies.push_back( Enemy(100 + i*32, 100 + 32*j, enemies.size()) );
	}
}

void BattleScene::update(){
	if(Keyboard::get(KEY_INPUT_0) == 1){
		turn++;
	}

	for(auto& player : players){
		player.update();
		if(player.pos().targetted(cursor.getX(), cursor.getY())){
			player.act();
		}
	}

	cursor.update();
	
	//if(enemies.empty())
		//changeScene(new homeScene)
}

void BattleScene::draw(){
	DrawFormatString(0, 0, GetColor(255,255,255), "turn : %d", turn);

	map.draw();

	for(auto& player : players){
		player.draw();
	}
	for(auto& enemy : enemies){
		enemy.draw();
	}

	cursor.draw();
}