﻿#include <DxLib.h>
#include "Event.h"
#include "Stage.h"
#include "MapchipDefinition.h"

int Event::dist[8][2] = {
	{ 0, -1},	//up
	{ 1, -1},	//rigthup
	{ 1,  0},	//right
	{ 1,  1},	//rightbottom
	{ 0,  1},	//bottom
	{-1,  1},	//leftbottom
	{-1,  0},	//left
	{-1, -1}	//leftup
};
int Event::color_move = GetColor(102,255,255);
int Event::color_attack = GetColor(255,102,255);
int Event::color_support = GetColor(102,255,102);

void Event::DrawGraphOnMap(int x, int y, int image){
	//DrawGraph(leftupPositionX + x*mapsize, leftupPositionY + y*mapsize, image, true);
	DrawBox(Stage::getLeftupPositionX() + x*mapsize +5, Stage::getLeftupPositionY() + y*mapsize +5,
		Stage::getLeftupPositionX() + (x+1)*mapsize -5, Stage::getLeftupPositionY() + (y+1)*mapsize -5, image, true);
}

void Event::range(int x, int y, int color, int n, bool consider_resistance){
	if(n <= 0) return;

	int rest[4];
	for(int i = 0; i < 4; ++i){
		rest[i] = consider_resistance ? n - Stage::getResistance(x + dist[i*2][0], y + dist[i*2][1]) : n - 1;

		if(Stage::canMove(x + dist[i*2][0], y + dist[i*2][1]) && rest[i] >= 0){
			Stage::setBrightPoints(x + dist[i*2][0], y + dist[i*2][1], color);
			range(x + dist[i*2][0], y + dist[i*2][1], color, rest[i], consider_resistance);
		}
	}
}

void Event::reachTo(int x, int y, int color, int n){
	for(int m = 0; m < n; m++){
		if(Stage::canMove(x-n+m, y-m)){
			Stage::setBrightPoints(x-n+m, y-m, color);
		}
		if(Stage::canMove(x+m, y-n+m)){
			Stage::setBrightPoints(x+m, y-n+m, color);
		}
		if(Stage::canMove(x+n-m, y+m)){
			Stage::setBrightPoints(x+n-m, y+m, color);
		}
		if(Stage::canMove(x-m, y+n-m)){
			Stage::setBrightPoints(x-m, y+n-m, color);
		}
	}
}

void Event::reachTo(int x, int y, int color, int min_range, int max_range){
	for(int i = min_range; i <= max_range; i++){
		reachTo(x, y, color, i);
	}
}

void Event::around8(int x, int y, int color){
	for(int i = 0; i < 8; ++i){
		if(Stage::canMove(x + dist[i][0], y + dist[i][1])){
			Stage::setBrightPoints(x + dist[i][0], y + dist[i][1], color);
		}
	}
}

void Event::aroundTo(int x, int y, int color, int n){
	if(n <= 0) return;

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < 8; ++j){
			around8(x + dist[j][0]*i, y + dist[j][1]*i, color);
			aroundTo(x + dist[j][0], y + dist[j][1], color, n-1);
		}
	}

	//for(int i = 0; i < n; ++i){
	//	for(int j = 0; j < 8; ++j){
	//		around8(x + dist[j][0]*i, y + dist[j][1]*i, color);
	//	}
	//}
}

void Event::rowFourTo(int x, int y, int color, int n){
	if(n <= 0) return;

	for(int i = 1; i <= n; ++i){
		for(int j = 0; j < 4; ++j){
			if(Stage::canMove(x + dist[j*2][0]*i, y + dist[j*2][1]*i)){
				Stage::setBrightPoints(x + dist[j*2][0]*i, y + dist[j*2][1]*i, color);
			}
		}
	}
}

void Event::rowFour(int x, int y, int color){
	rowFourTo(x, y, color, Stage::getWidth() >= Stage::getHeight() ? Stage::getWidth() : Stage::getHeight());
}
