#include <DxLib.h>
#include "Cursor.h"
#include "GV.h"
#include "Keyboard.h"
#include "Event.h"
#include "Stage.h"

Position Cursor::mypos(0,0);

Cursor::Cursor(int x, int y){
	mypos.set(x, y);
	image = GetColor(0, 255, 0);
}

void Cursor::update(){
	if(Keyboard::get(KEY_INPUT_LEFT) == 1 || Keyboard::get(KEY_INPUT_LEFT) > 30)
		mypos.Move(-1,  0);
	if(Keyboard::get(KEY_INPUT_RIGHT) == 1 || Keyboard::get(KEY_INPUT_RIGHT) > 30)
		mypos.Move( 1,  0);
	if(Keyboard::get(KEY_INPUT_UP) == 1 || Keyboard::get(KEY_INPUT_UP) > 30)
		mypos.Move( 0, -1);
	if(Keyboard::get(KEY_INPUT_DOWN) == 1 || Keyboard::get(KEY_INPUT_DOWN) > 30)
		mypos.Move( 0,  1);

	//ステージ外にはみ出ないようにする
	if(mypos.getX() < 0) mypos.setX(0);
	if(mypos.getY() < 0) mypos.setY(0);
	if(mypos.getX() > Stage::getWidth()-1) mypos.setX(Stage::getWidth()-1);
	if(mypos.getY() > Stage::getDepth()-1) mypos.setY(Stage::getDepth()-1);
}

void Cursor::draw(){
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	DrawBox(mypos.getXByPx(), mypos.getYByPx(),
		mypos.getXByPx() + chipsize, mypos.getYByPx() + chipsize, image, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void Cursor::set(int x, int y){
	mypos.set(x, y);
}