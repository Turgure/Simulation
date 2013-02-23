#include <DxLib.h>
#include "Event.h"
#include "Stage.h"
#include "MapchipDefinition.h"

int Event::dist[8][2] = {
	{-1,  0},	//left
	{ 1,  0},	//right
	{ 0, -1},	//up
	{ 0,  1},	//bottom
	{-1, -1},	//leftup
	{ 1, -1},	//rigthup
	{-1,  1},	//leftbottom
	{ 1,  1}	//rightbottom
};
int Event::color_move = GetColor(102,255,255);
int Event::color_attack = GetColor(255,102,255);
int Event::color_support = GetColor(102,255,102);

void Event::DrawGraphOnMap(int x, int y, int image){
	//DrawGraph(leftupPositionX + x*mapsize, leftupPositionY + y*mapsize, image, true);
	DrawBox(Stage::getLeftupPositionX() + x*mapsize +5, Stage::getLeftupPositionY() + y*mapsize +5,
		Stage::getLeftupPositionX() + (x+1)*mapsize -5, Stage::getLeftupPositionY() + (y+1)*mapsize -5, image, true);
}

void Event::spotReachTo(int x, int y, int color, int n){
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

void Event::spotReachTo(int x, int y, int color, int min_range, int max_range){
	for(int i = min_range; i <= max_range; i++){
		spotReachTo(x, y, color, i);
	}
}

void Event::spotAround(int x, int y, int color){
	spotReachTo(x, y, color, 1);
	for(int i = 0; i < 4; ++i){
		if(Stage::canMove(x + dist[i+4][0], y + dist[i+4][1])){
			Stage::setBrightPoints(x + dist[i+4][0], y + dist[i+4][1], color);
		}
	}
}

void Event::range(int x, int y, int color, int n, bool consider_resistance){
	if(n <= 0) return;
	
	int rest[4];
	for(int i = 0; i < 4; ++i){
		rest[i] = n - Stage::getResistance(x + dist[i][0], y + dist[i][1]);

		if(Stage::canMove(x + dist[i][0], y + dist[i][1]) && rest[i] >= 0){
			Stage::setBrightPoints(x + dist[i][0], y + dist[i][1], color);
			range(x + dist[i][0], y + dist[i][1], color, rest[i], consider_resistance);
		}
	}
}

//void Event::lineFour(int x, int y){
//	for(int i = 0; i < 9; i++) {
//		if(x == 100 + i*32)
//			for(int j = -1; j < 8; j++)
//				Stage::setBrightPoints(x -i+j, y, -i+j+1, 0);
//		if(y == 100 + i*32)
//			for(int j = -1; j < 8; j++)
//				Stage::setBrightPoints(x, y -i+j, 0, -i+j+1);
//	}
//}
//
//
//void Event::lineFourInField(int x, int y, int n){
//	
//	//左にはみ出さない
//	for(int sleftline = n; sleftline > 0; sleftline--){
//		int judge = (x-100)/32 - sleftline;
//		if( judge >= 0){		//左から0列目以上
//			Stage::setBrightPoints(100, y, judge, 0);
//			//	break;
//		}
//	}
//
//
//
//	//上にはみ出さない
//	for(int supline = n; supline > 0; supline--){
//		int judge = (y-100)/32 - supline;
//		if( judge >= 0){		//上から0列目以上
//			Stage::setBrightPoints(x, 100, 0, judge);
//			//	break;
//		}
//	}
//	
//	//右にはみ出さない
//	for(int srightline = 1; srightline <= n; srightline++){
//		int judge = (x-100)/32 + srightline;
//		if( judge <= 8){		//	左から8列目以下
//			Stage::setBrightPoints(100, y, judge, 0);
//			//	break;
//		}
//	}
//
//	//下にはみ出さない
//	for(int sunderline = 1; sunderline <= n; sunderline++){
//		int judge = (y-100)/32 + sunderline;
//		if( judge <= 8){		//	下から8列目以下
//			Stage::setBrightPoints(x, 100, 0, judge);
//			//	break;
//		}
//	}
//}