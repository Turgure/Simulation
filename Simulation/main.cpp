﻿#include <DxLib.h>
#include "Keyboard.h"
#include "BattleScene.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	// ウインドウモードに変更
	ChangeWindowMode(true);
	if(DxLib_Init() == -1 || SetDrawScreen(DX_SCREEN_BACK) != 0) return -1;	//初期化と裏画面処理

	Keyboard::initialize();
	
	SceneManager::run(new BattleScene);

	DxLib_End();
	return 0;
}