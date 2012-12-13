#include <DxLib.h>
#include "Keyboard.h"
#include "GameManager.h"

//----------------------------------------
//ループで必ず行う処理
//----------------------------------------
int ProcessLoop(){
	if(ProcessMessage() != 0)  return -1;	//プロセス処理がエラーなら-1を返す
	if(ClearDrawScreen() != 0) return -1;	//画面クリア処理がエラーなら-1を返す
	if(Keyboard::update() != 0) return -1;	//キーのアップデート処理がエラーなら-1を返す
	return 0;
}

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	// ウインドウモードに変更
	ChangeWindowMode(true);
	if(DxLib_Init() == -1 || SetDrawScreen(DX_SCREEN_BACK) != 0) return -1;	//初期化と裏画面処理


	Keyboard::initialize();
	GameManager manager;
	manager.create();
	
	while(!ProcessLoop() && !Keyboard::get(KEY_INPUT_ESCAPE)){
		manager.update();
		manager.draw();
		
		ScreenFlip();	//裏画面を表画面に反映
	}

	WaitKey();
	DxLib_End();
	return 0;
}