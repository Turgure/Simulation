#include <stdio.h>
#include <DxLib.h>
#include "Stage.h"
#include "MapchipDefinition.h"
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
	if((fp = fopen("data/stage/stage2/map.csv", "r")) == NULL){
		printfDx("mapdata load error.");
		return;
	}

	fscanf(fp, "%d, %d", &width, &height);	
	int h = 0, w = 0;
	while((ret = fscanf(fp, "%d, ", &mapid)) != EOF){
		mapchip[h][w].id = mapid;
		++w;
		if(w >= width){
			++h;
			w = 0;
		}
	}
	fclose(fp);

	for(int h = 0; h < height; h++){
		for(int w = 0; w < width; w++){
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
			Event::DrawGraphOnMap(w, h, mapchip[h][w].mapchip_color, false);
		}
	}
}

void Stage::drawBrightPoints(){
	for(int h = 0; h < height; h++){
		for(int w = 0; w < width; w++){
			if(mapchip[h][w].can_move_object){
				Event::DrawGraphOnMap(w, h, mapchip[h][w].bright_color, true);
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
		return (mapchip[y][x].id != 0);
	} else {
		return false;
	}
}

int Stage::getResistance(int x, int y){
	return mapchip[y][x].resistance;
}