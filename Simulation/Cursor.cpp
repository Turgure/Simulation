#include <DxLib.h>
#include "Cursor.h"
#include "Keyboard.h"
#include "Event.h"
#include "Stage.h"
#include "MapchipDefinition.h"

Position Cursor::varpos(0,0);

Cursor::Cursor(int x, int y){
	image = GetColor(0, 155, 0);
}

void Cursor::update(){
	if(Keyboard::get(KEY_INPUT_LEFT) == 1)	varpos.MoveByMap(-1,  0);
	if(Keyboard::get(KEY_INPUT_RIGHT) == 1)	varpos.MoveByMap( 1,  0);
	if(Keyboard::get(KEY_INPUT_UP) == 1)	varpos.MoveByMap( 0, -1);
	if(Keyboard::get(KEY_INPUT_DOWN) == 1)	varpos.MoveByMap( 0,  1);

	//ステージ外にはみ出ないようにする
	if(varpos.getXByMap() < 0) varpos.setXByMap(0);
	if(varpos.getYByMap() < 0) varpos.setYByMap(0);
	if(varpos.getXByMap() > Stage::getWidth()-1) varpos.setXByMap(Stage::getWidth()-1);
	if(varpos.getYByMap() > Stage::getHeight()-1) varpos.setYByMap(Stage::getHeight()-1);
}

void Cursor::draw(){
	DrawBox(varpos.getXByPx() +5, varpos.getYByPx() +5, varpos.getXByPx()+mapsize -5, varpos.getYByPx()+mapsize -5, image, false);
}