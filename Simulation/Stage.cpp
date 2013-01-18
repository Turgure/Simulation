#include <DxLib.h>
#include "Stage.h"
#include "MapchipDefinition.h"

int Stage::map[height][width] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 1, 1, 0, 0, 0, 1},
	{1, 1, 1, 1, 0, 0, 1, 1, 1, 1},
	{1, 1, 1, 1, 0, 0, 1, 1, 1, 1},
	{1, 0, 0, 0, 1, 1, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

Stage::Mapchip Stage::mapchip[height][width];

Stage::Stage(){
	initialize();
}

void Stage::initialize(){
	current_map = 1;
	initID();
	initMap();
}

void Stage::initID(){
	for(int i = 0; i < 5; i++)
		mapchipStatus.push_back( MapchipStatus(i) );

	for(auto& chip : mapchipStatus){
		switch(chip.id){
		case 0://移動不可
			chip.movable = false;
			chip.mapchip_color = GetColor(255, 128, 0);
			break;

		case 1://移動可能（1:草原, 2:岩…　などにする）
			chip.movable = true;
			chip.mapchip_color = GetColor(128, 255, 0);
			break;

		default:
			break;
		}
	}
}

void Stage::initMap(){
	for(int h = 0; h < height; h++){
		for(int w = 0; w < width; w++){
			mapchip[h][w].can_move_object = false;
		
			for(auto& chip : mapchipStatus){
				if(map[h][w] == chip.id){
					mapchip[h][w].mapchip_color = chip.mapchip_color;
					continue;
				}
			}
		}
	}
}

void Stage::draw(){
	drawMap();
	drawBrightPoints();
}

void Stage::drawMap(){
	for(int h = 0; h < height; h++){
		for(int w = 0; w < width; w++){
			DrawBox(100 + w*mapsize, 100 + h*mapsize, 100 + (w+1)*mapsize, 100 + (h+1)*mapsize, mapchip[h][w].mapchip_color, false);
		}
	}
}

void Stage::drawBrightPoints(){
	for(int h = 0; h < height; h++){
		for(int w = 0; w < width; w++){
			if(mapchip[h][w].can_move_object){
				DrawBox(100 + w*mapsize, 100 + h*mapsize, 100 + (w+1)*mapsize, 100 + (h+1)*mapsize, mapchip[h][w].bright_color, true);
			}
		}
	}
}

void Stage::setBrightPoints(int x, int y, int color){
	mapchip[y][x].can_move_object = true;
	mapchip[y][x].bright_color = color;
}

bool Stage::getBrightPoints(int x, int y){
	return mapchip[y][x].can_move_object;
}

void Stage::eraseBrightPoints(){
	for(int h = 0; h < height; h++){
		for(int w = 0; w < width; w++){
			mapchip[h][w].can_move_object = false;
		}
	}
}

bool Stage::canMove(int x, int y){
	if(x >= 0 && y >= 0 && x < width && y < height){
		if(map[y][x] != 0) return true;
		else return false;
	} else {
		return false;
	}
}