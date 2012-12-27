#include <DxLib.h>
#include "Stage.h"
#include "MapChipDefinition.h"

int Stage::map[height][width] = {
	{ 1,  1,  1,  1,  1,  1,  1,  1,  1,  1},
	{ 1,  1,  1,  1,  1,  1,  1,  1,  1,  1},
	{ 1,  1,  1,  1,  1,  1,  1,  1,  1,  1},
	{ 1, -1, -1, -1,  1,  1, -1, -1, -1,  1},
	{ 1,  1,  1,  1, -1, -1,  1,  1,  1,  1},
	{ 1,  1,  1,  1, -1, -1,  1,  1,  1,  1},
	{ 1, -1, -1, -1,  1,  1, -1, -1, -1,  1},
	{ 1,  1,  1,  1,  1,  1,  1,  1,  1,  1},
	{ 1,  1,  1,  1,  1,  1,  1,  1,  1,  1},
	{ 1,  1,  1,  1,  1,  1,  1,  1,  1,  1}
};

Stage::Cell Stage::cell[];

Stage::Stage(){
	current_map = 1;
	for(int h = 0; h < height; h++){
		for(int w = 0; w < width; w++){
			cell[(h*10)+w].id = map[h][w];
			cell[(h*10)+w].can_move_object = false;
		}
	}
	checkID();
}

void Stage::checkID(){
	for(int h = 0; h < height; h++){
		for(int w = 0; w < width; w++){
			switch(cell[(h*10)+w].id){
			case 1://ˆÚ“®‰Â”\
				cell[(h*10)+w].mapchip_color = GetColor(0, 255, 255);
				break;
			default://ˆÚ“®•s‰Â
				cell[(h*10)+w].mapchip_color = GetColor(126, 126, 0);
				break;
			}
		}
	}
}

void Stage::draw(){
	drawStage();
	drawObject();
}

void Stage::drawStage(){
	for(int h = 0; h < height; h++){
		for(int w = 0; w < width; w++){
			DrawBox(100 + w*mapsize, 100 + h*mapsize, 100 + (w+1)*mapsize, 100 + (h+1)*mapsize, cell[(h*10)+w].mapchip_color, false);
		}
	}
}

void Stage::drawObject(){
	for(int h = 0; h < height; h++){
		for(int w = 0; w < width; w++){
			if(cell[(h*10)+w].can_move_object){
				DrawBox(100 + w*mapsize, 100 + h*mapsize, 100 + (w+1)*mapsize, 100 + (h+1)*mapsize, cell[(h*10)+w].color, true);
			}
		}
	}
}

void Stage::setBrightPoints(int x, int y, int color){
	cell[(y*10)+x].can_move_object = true;
	cell[(y*10)+x].color = color;
}

bool Stage::getBrightPoints(int x, int y){
	return cell[(y*10)+x].can_move_object;
}

void Stage::eraseBrightPoints(){
	for(int h = 0; h < height; h++){
		for(int w = 0; w < width; w++){
			cell[(h*10)+w].can_move_object = false;
		}
	}
}

int Stage::getID(int x, int y){
	if(x >= 0 && y >= 0 && x < width && y < height){
		return cell[(y*10)+x].id;
	} else {
		return -1;
	}
}