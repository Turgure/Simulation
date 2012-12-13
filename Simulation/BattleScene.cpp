#include <DxLib.h>
#include "BattleScene.h"
#include "Keyboard.h"
#include "Cursor.h"

BattleScene::BattleScene():cursor(100+32*5, 100+32*8){}

void BattleScene::initialize(){
	turn = 1;
	//Map::create();

	for(int i = 0; i < 5; i++){
		players.push_back( Player(100 + i*32, 100 + i*32, i) );
	}
	
	for(int i = 0; i < 5; i++){
		int j = GetRand(8);
		enemies.push_back( Enemy(100 + i*32, 100 + 32*j, i) );
	}
}

void BattleScene::update(){
	if(Keyboard::get(KEY_INPUT_0) == 1){
		turn++;
	}

	//if(enemies.size() == 0)
		//changeScene(new homeScene)

	cursor.update();
}

void BattleScene::draw(){
	DrawFormatString(0, 0, GetColor(255,255,255), "turn : %d", turn);

	map.draw();

	for(auto player : players){
		player.draw();
		if(player.getX() == cursor.getX() && player.getY() == cursor.getY()){
			player.showCommand();
		}
	}
	for(auto enemy : enemies){
		enemy.draw();
	}

	cursor.draw();
}