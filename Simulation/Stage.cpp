#include <DxLib.h>
#include "Stage.h"
#include "GV.h"
#include "FileStream.h"
#include "Cursor.h"

int Stage::width;
int Stage::depth;
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
		mapchipDefinition.push_back( MapchipDefinition(i) );

	for(auto& chip : mapchipDefinition){
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


	auto& header = mapid[0];
	width = stoi(header[0]);
	depth = stoi(header[1]);
	//idの読み込み

	for(unsigned int h = 1; h < mapid.size(); ++h){
		for(unsigned int w = 0; w < mapid[h].size(); ++w){
			mapchip[h-1][w].id = stoi(mapid[h][w]);
		}
	}

	for(int h = 0; h < depth; h++){
		for(int w = 0; w < width; w++){
			mapchip[h][w].is_brighting = false;
			mapchip[h][w].object = nullptr;

			for(auto& chip : mapchipDefinition){
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
	if(Cursor::pos().getXByPx() < chipsize*3){
		leftup_positionX += chipsize + 5;
		Cursor::pos().setXByPx(chipsize*3);
	}
	if(Cursor::pos().getYByPx() < chipsize*3){
		leftup_positionY += chipsize + 5;
		Cursor::pos().setYByPx(chipsize*3);
	}
	if(Cursor::pos().getXByPx() > DEFAULT_SCREEN_SIZE_X - chipsize*3){
		leftup_positionX -= chipsize - 5;
		Cursor::pos().setXByPx((DEFAULT_SCREEN_SIZE_X-leftup_positionX)/chipsize - 3);
	}
	if(Cursor::pos().getYByPx() > DEFAULT_SCREEN_SIZE_Y - chipsize*3){
		leftup_positionY -= chipsize - 5;
		Cursor::pos().setYByPx((DEFAULT_SCREEN_SIZE_Y-leftup_positionY)/chipsize - 3);
	}
}

void Stage::draw(){
	drawMap();
	drawBrightPoints();
}

void Stage::drawMap(){
	for(int h = 0; h < depth; h++){
		for(int w = 0; w < width; w++){
			DrawBox(getLeftupPositionX() + w*chipsize, getLeftupPositionY() + h*chipsize,
				getLeftupPositionX() + w*chipsize + chipsize, getLeftupPositionY() + h*chipsize + chipsize, mapchip[h][w].mapchip_color, false);
		}
	}
}

void Stage::drawBrightPoints(){
	for(int h = 0; h < depth; h++){
		for(int w = 0; w < width; w++){
			if(mapchip[h][w].is_brighting){
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 192);
				DrawBox(getLeftupPositionX() + w*chipsize, getLeftupPositionY() + h*chipsize,
					getLeftupPositionX() + w*chipsize + chipsize, getLeftupPositionY() + h*chipsize + chipsize, mapchip[h][w].bright_color, true);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			}
		}
	}
}

void Stage::lateUpdate(){
	for(int h = 0; h < depth; h++){
		for(int w = 0; w < width; w++){
			mapchip[h][w].object = nullptr;
		}
	}
}

void Stage::setBrightPoint(int x, int y, int color){
	mapchip[y][x].is_brighting = true;
	mapchip[y][x].bright_color = color;
}

bool Stage::getBrightPoint(int x, int y){
	return mapchip[y][x].is_brighting;
}

void Stage::eraseBrightPoint(int x, int y){
	mapchip[y][x].is_brighting = false;
}

void Stage::eraseBrightPoints(){
	for(int h = 0; h < depth; h++){
		for(int w = 0; w < width; w++){
			eraseBrightPoint(w, h);
		}
	}
}

void Stage::setObjectAt(int x, int y, BaseObject* obj){
	mapchip[y][x].object = obj;
}

BaseObject* Stage::getObjectAt(int x, int y){
	return mapchip[y][x].object;
}

bool Stage::canMove(int x, int y){
	if(x >= 0 && y >= 0 && x < width && y < depth){
		return (mapchip[y][x].id != 0);
	} else {
		return false;
	}
}

int Stage::getResistance(int x, int y){
	return mapchip[y][x].resistance;
}