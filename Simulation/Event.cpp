#include <DxLib.h>
#include "Event.h"
#include "Object.h"

int Event::color = GetColor(102,255,255);

void Event::range(int x, int y, int diffX, int diffY){
	DrawBox(x + diffX*32, y + diffY*32, x + (diffX+1)*32, y + (diffY+1)*32, color, true);
}

void Event::nearFour(int x, int y){
	range(x, y,  1,  0);
	range(x, y, -1,  0);
	range(x, y,  0,  1);
	range(x, y,  0, -1);
}

void Event::nearEight(int x, int y){
	nearFour(x, y);
	range(x, y, -1, -1);
	range(x, y,  1, -1);
	range(x, y, -1, -1);
	range(x, y,  1,  1);
}

void Event::lineFour(int x, int y){
	for(int i = 0; i < 9; i++) {
		if(x == 100 + i*32)
			for(int j = -1; j < 8; j++)
				range(x -i+j, y, -i+j+1, 0);
		if(y == 100 + i*32)
			for(int j = -1; j < 8; j++)
				range(x, y -i+j, 0, -i+j+1);
	}
}