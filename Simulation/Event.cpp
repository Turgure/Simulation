#include <DxLib.h>
#include "Event.h"
#include "Object.h"

int Event::color = GetColor(102,255,255);

void Event::point(int x, int y, int diffX, int diffY){
	DrawBox(x + diffX*32, y + diffY*32, x + (diffX+1)*32, y + (diffY+1)*32, color, true);
}

void Event::spotReachTo(int x, int y, int n){
	for(int m = 0; m < n; m++){
		point(x, y, -n+m,   -m);
		point(x, y,    m, -n+m);
		point(x, y,  n-m,    m);
		point(x, y,   -m,  n-m);
	}
}

void Event::spotAround(int x, int y){
	spotReachTo(x, y, 1);
	point(x, y, -1, -1);
	point(x, y,  1, -1);
	point(x, y, -1,  1);
	point(x, y,  1,  1);
}

void Event::range(int x, int y, int n){
	for(; n > 0; n--){
		spotReachTo(x, y, n);
	}
}

void Event::lineFour(int x, int y){
	for(int i = 0; i < 9; i++) {
		if(x == 100 + i*32)
			for(int j = -1; j < 8; j++)
				point(x -i+j, y, -i+j+1, 0);
		if(y == 100 + i*32)
			for(int j = -1; j < 8; j++)
				point(x, y -i+j, 0, -i+j+1);
	}
}