#include <DxLib.h>
#include "Cursor.h"
#include "Keyboard.h"
#include "Event.h"
#include "MapchipDefinition.h"

int Cursor::x;
int Cursor::y;

Cursor::Cursor(int x, int y){
	this->x = x, this->y =  y;
	image = GetColor(0, 155, 0);
}

void Cursor::update(){
	if(Keyboard::get(KEY_INPUT_LEFT) == 1)	this->x -= 1;
	if(Keyboard::get(KEY_INPUT_RIGHT) == 1)	this->x += 1;
	if(Keyboard::get(KEY_INPUT_UP) == 1)	this->y -= 1;
	if(Keyboard::get(KEY_INPUT_DOWN) == 1)	this->y += 1;

	//ステージ外にはみ出ないようにする
	if(x < 0) x = 0;
	if(y < 0) y = 0;
	if(x > 9) x = 9;
	if(y > 9) y = 9;
}

void Cursor::draw(){
	Event::DrawGraphOnMap(x, y, image);
}	