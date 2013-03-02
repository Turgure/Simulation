#include <stdio.h>
#include <DxLib.h>
#include "Stage.h"
#include "GV.h"
#include "FileStream.h"
#include "Event.h"
#include "Cursor.h"

int Stage::width;
int Stage::height;
int Stage::leftup_positionX = 128;
int Stage::leftup_positionY = 128;
Stage::Mapchip Stage::mapchip[100][100];

Stage::Stage(){
	initialize();
}

void Stage::initialize(){
	current_map = 1;
	initID();
	initMap();
}

void Stage::initID(){
	//i => kind of id
	for(int i = 0; i < 5; i++)
		mapchipStatus.push_back( MapchipStatus(i) );

	for(auto& chip : mapchipStatus){
		switch(chip.id){
		case 0://chip which can't move 
			chip.mapchip_color = GetColor(255, 128, 0);
			chip.resistance = INT_MAX;
			break;

		case 1://movable（id=1 => 草原, id=2 => 岩…　などにする）
			chip.mapchip_color = GetColor(128, 255, 0);
			chip.resistance = 1;
			break;

		case 2://沼地的な
			chip.mapchip_color = GetColor(128, 0, 128);
			chip.resistance = 2;
			break;

		default:
			break;
		}
	}
}

void Stage::initMap(){
	vector<vector<string>> mapid;
	FileStream::load("data/stage/stage2/map.csv", mapid);
	
	//idの読み込み
	for(unsigned int h = 0; h < mapid.size(); ++h){
		for(unsigned int w = 0; w < mapid[h].size(); ++w){
			if(h == 0){
				width = stoi(mapid[h][0]);
				height = stoi(mapid[h][1]);
				break;
			}
			mapchip[h-1][w].id = stoi(mapid[h][w]);
		}
	}

	for(int h = 0; h < height; h++){
		for(int w = 0; w < width; w++){
			mapchip[h][w].varpos.setByMap(w, h);
			mapchip[h][w].can_move_object = false;

			for(auto& chip : mapchipStatus){
				if(mapchip[h][w].id == chip.id){
					mapchip[h][w].mapchip_color = chip.mapchip_color;
					mapchip[h][w].resistance = chip.resistance;
					break;
				}
			}
		}
	}
}

void Stage::update(){
	if(Cursor::pos().getXByPx() < mapsize*3){
		leftup_positionX += mapsize + 5;
		Cursor::pos().setXByPx(mapsize*3);
	}
	if(Cursor::pos().getYByPx() < mapsize*3){
		leftup_positionY += mapsize + 5;
		Cursor::pos().setYByPx(mapsize*3);
	}
	if(Cursor::pos().getXByPx() > DEFAULT_SCREEN_SIZE_X - mapsize*3){
		leftup_positionX -= mapsize - 5;
		Cursor::pos().setXByPx((DEFAULT_SCREEN_SIZE_X-leftup_positionX)/mapsize - 3);
	}
	if(Cursor::pos().getYByPx() > DEFAULT_SCREEN_SIZE_Y - mapsize*3){
		leftup_positionY -= mapsize - 5;
		Cursor::pos().setYByPx((DEFAULT_SCREEN_SIZE_Y-leftup_positionY)/mapsize - 3);
	}
}

void Stage::draw(){
	drawMap();
	drawBrightPoints();
}

void Stage::drawMap(){
	for(int h = 0; h < height; h++){
		for(int w = 0; w < width; w++){
			DrawBox(mapchip[h][w].varpos.getXByPx(), mapchip[h][w].varpos.getYByPx(),
				mapchip[h][w].varpos.getXByPx() + mapsize, mapchip[h][w].varpos.getYByPx() + mapsize, mapchip[h][w].mapchip_color, false);
		}
	}
}

void Stage::drawBrightPoints(){
	for(int h = 0; h < height; h++){
		for(int w = 0; w < width; w++){
			if(mapchip[h][w].can_move_object){
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 192);
				DrawBox(mapchip[h][w].varpos.getXByPx(), mapchip[h][w].varpos.getYByPx(),
					mapchip[h][w].varpos.getXByPx() + mapsize, mapchip[h][w].varpos.getYByPx() + mapsize, mapchip[h][w].bright_color, true);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			}
		}
	}
}

void Stage::setBrightPoint(int x, int y, int color){
	mapchip[y][x].can_move_object = true;
	mapchip[y][x].bright_color = color;
}

bool Stage::getBrightPoint(int x, int y){
	return mapchip[y][x].can_move_object;
}

void Stage::eraseBrightPoint(int x, int y){
	mapchip[y][x].can_move_object = false;
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
		return (mapchip[y][x].id != 0);
	} else {
		return false;
	}
}

int Stage::getResistance(int x, int y){
	return mapchip[y][x].resistance;
}