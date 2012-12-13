#include "DxLib.h"
#include "GUI.h"

int mapsize;
int Keyboard::key[256];

void Keyboard::initialize(){
	for(int i = 0; i < 256; i++) key[i] = 0;
}

int Keyboard::update(){
	char tmpKey[256];
	GetHitKeyStateAll(tmpKey);
	for(int i = 0; i < 256; i++){
		if(tmpKey[i] != 0){//i”Ô‚ÌƒL[‚ª‰Ÿ‚³‚ê‚½‚ç
			key[i]++;
		} else {
			key[i] = 0;
		}
	}
	return 0;
}

int Keyboard::get(int keyID){
	return key[keyID];
}

Cursor::Cursor(int x, int y){
	this->x = x, this->y =  y;
	image = GetColor(0, 155, 0);
}

void Cursor::update(){
	if(Keyboard::get(KEY_INPUT_LEFT) == 1)	this->x -= mapsize;
	if(Keyboard::get(KEY_INPUT_RIGHT) == 1)	this->x += mapsize;
	if(Keyboard::get(KEY_INPUT_UP) == 1)	this->y -= mapsize;
	if(Keyboard::get(KEY_INPUT_DOWN) == 1)	this->y += mapsize;
}

void Cursor::draw(){
	DrawBox(x, y, x + mapsize, y + mapsize, image, true);
}	