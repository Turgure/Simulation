#include <DxLib.h>
#include "Event.h"
#include "GV.h"
#include "Stage.h"

int Event::dir[8][2] = {
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

void Event::range(int x, int y, int n, bool consider_resistance){
	if(n <= 0) return;

	int toX, toY;
	int rest[4];
	for(int i = 0; i < 4; ++i){
		toX = x + dir[i*2][0];
		toY = y + dir[i*2][1];
		rest[i] = consider_resistance ? n - Stage::getResistance(toX, toY) : n - 1;

		if(Stage::canMove(toX, toY) && rest[i] >= 0){
			Stage::setBrightPoint(toX, toY, color_move);
			//敵をすり抜けないようにする
			if(Stage::getObjectAt(toX, toY)) continue;
			range(toX, toY, rest[i], consider_resistance);
		}
	}
}

void Event::reachAt(int x, int y, int color, int n){
	for(int m = 0; m < n; ++m){
		if(Stage::canMove(x-n+m, y-m)){
			Stage::setBrightPoint(x-n+m, y-m, color);
		}
		if(Stage::canMove(x+m, y-n+m)){
			Stage::setBrightPoint(x+m, y-n+m, color);
		}
		if(Stage::canMove(x+n-m, y+m)){
			Stage::setBrightPoint(x+n-m, y+m, color);
		}
		if(Stage::canMove(x-m, y+n-m)){
			Stage::setBrightPoint(x-m, y+n-m, color);
		}
	}
}

void Event::reachTo(int x, int y, int color, int min_range, int max_range){
	for(int i = min_range; i <= max_range; ++i){
		reachAt(x, y, color, i);
	}
}

void Event::around8(int x, int y, int color){
	for(int i = 0; i < 8; ++i){
		if(Stage::canMove(x + dir[i][0], y + dir[i][1])){
			Stage::setBrightPoint(x + dir[i][0], y + dir[i][1], color);
		}
	}
}

void Event::aroundTo(int x, int y, int color, int n){
	if(n <= 0) return;

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < 8; ++j){
			around8(x + dir[j][0]*i, y + dir[j][1]*i, color);
			aroundTo(x + dir[j][0], y + dir[j][1], color, n-1);
		}
	}

	//for(int i = 0; i < n; ++i){
	//	for(int j = 0; j < 8; ++j){
	//		around8(x + dir[j][0]*i, y + dir[j][1]*i, color);
	//	}
	//}
}

void Event::rowFourTo(int x, int y, int color, int n){
	if(n <= 0) return;

	for(int i = 1; i <= n; ++i){
		for(int j = 0; j < 4; ++j){
			if(Stage::canMove(x + dir[j*2][0]*i, y + dir[j*2][1]*i)){
				Stage::setBrightPoint(x + dir[j*2][0]*i, y + dir[j*2][1]*i, color);
			}
		}
	}
}

void Event::rowFour(int x, int y, int color){
	rowFourTo(x, y, color, Stage::getWidth() >= Stage::getDepth() ? Stage::getWidth() : Stage::getDepth());
}
