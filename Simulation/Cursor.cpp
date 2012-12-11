#include <DxLib.h>
#include "Cursor.h"
#include "Keyboard.h"

Cursor::Cursor(int x, int y){
	this->x = x, this->y =  y;
	image = GetColor(0, 155, 0);
	maptip = 32;
}

void Cursor::update(){
	if(Keyboard::get(KEY_INPUT_LEFT) == 1)	this->x -= maptip;
	if(Keyboard::get(KEY_INPUT_RIGHT) == 1)	this->x += maptip;
	if(Keyboard::get(KEY_INPUT_UP) == 1)	this->y -= maptip;
	if(Keyboard::get(KEY_INPUT_DOWN) == 1)	this->y += maptip;
}

void Cursor::draw(){
	DrawBox(x, y, x + maptip, y + maptip, image, true);
}	