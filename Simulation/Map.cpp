#include <DxLib.h>
#include "Map.h"

Map::Map(){
	current_map = 1;
}

void Map::draw(){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			//if(maptips[j][i] == 1)
			DrawBox(100, 100, 100 + j*32, 100 + i*32, GetColor(0, 255, 0), false);
		}
	}
}