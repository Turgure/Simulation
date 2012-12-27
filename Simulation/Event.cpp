#include <DxLib.h>
#include "Event.h"
#include "Stage.h"
#include "MapChipDefinition.h"

int Event::color = GetColor(102,255,255);

void Event::DrawGraphOnMap(int x, int y, int image){
	//DrawGraph(100 + x*mapsize, 100 + y*mapsize, image, true);
	DrawBox(100 + x*mapsize, 100 + y*mapsize, 100 + (x+1)*mapsize, 100 + (y+1)*mapsize, image, true);
}

void Event::point(int x, int y){
	DrawGraphOnMap(x, y, color);
}

void Event::spotReachTo(int x, int y, int n){
	for(int m = 0; m < n; m++){
		if( Stage::getID(x-n+m, y-m) != -1 ){
			Stage::setBrightPoints(x-n+m, y-m, color);
		}
		if( Stage::getID(x+m, y-n+m) != -1 ){
			Stage::setBrightPoints(x+m, y-n+m, color);
		}
		if( Stage::getID(x+n-m, y+m) != -1 ){
			Stage::setBrightPoints(x+n-m, y+m, color);
		}
		if( Stage::getID(x-m, y+n-m) != -1 ){
			Stage::setBrightPoints(x-m, y+n-m, color);
		}
	}
}

void Event::spotReachTo(int x, int y, int min_range, int max_range){
	for(int i = min_range; i <= max_range; i++){
		spotReachTo(x, y, i);
	}
}

void Event::spotAround(int x, int y){
	point(x - mapsize, y - mapsize);
	point(x + mapsize, y - mapsize);
	point(x - mapsize, y + mapsize);
	point(x + mapsize, y + mapsize);
}

void Event::range(int x, int y, int n){
	if(n <= 0) return;
	
	if( Stage::getID(x-1, y) != -1 ){
		Stage::setBrightPoints(x-1, y, color);
		range(x-1, y, n-1);
	}
	if( Stage::getID(x+1, y) != -1 ){
		Stage::setBrightPoints(x+1, y, color);
		range(x+1, y, n-1);
	}
	if( Stage::getID(x, y-1) != -1 ){
		Stage::setBrightPoints(x, y-1, color);
		range(x, y-1, n-1);
	}
	if( Stage::getID(x, y+1) != -1 ){
		Stage::setBrightPoints(x, y+1, color);
		range(x, y+1, n-1);
	}
}

//void Event::lineFour(int x, int y){
//	for(int i = 0; i < 9; i++) {
//		if(x == 100 + i*32)
//			for(int j = -1; j < 8; j++)
//				point(x -i+j, y, -i+j+1, 0);
//		if(y == 100 + i*32)
//			for(int j = -1; j < 8; j++)
//				point(x, y -i+j, 0, -i+j+1);
//	}
//}
//
//
//void Event::lineFourInField(int x, int y, int n){
//	
//	//���ɂ͂ݏo���Ȃ�
//	for(int sleftline = n; sleftline > 0; sleftline--){
//		int judge = (x-100)/32 - sleftline;
//		if( judge >= 0){		//������0��ڈȏ�
//			point(100, y, judge, 0);
//			//	break;
//		}
//	}
//
//
//
//	//��ɂ͂ݏo���Ȃ�
//	for(int supline = n; supline > 0; supline--){
//		int judge = (y-100)/32 - supline;
//		if( judge >= 0){		//�ォ��0��ڈȏ�
//			point(x, 100, 0, judge);
//			//	break;
//		}
//	}
//	
//	//�E�ɂ͂ݏo���Ȃ�
//	for(int srightline = 1; srightline <= n; srightline++){
//		int judge = (x-100)/32 + srightline;
//		if( judge <= 8){		//	������8��ڈȉ�
//			point(100, y, judge, 0);
//			//	break;
//		}
//	}
//
//	//���ɂ͂ݏo���Ȃ�
//	for(int sunderline = 1; sunderline <= n; sunderline++){
//		int judge = (y-100)/32 + sunderline;
//		if( judge <= 8){		//	������8��ڈȉ�
//			point(x, 100, 0, judge);
//			//	break;
//		}
//	}
//}