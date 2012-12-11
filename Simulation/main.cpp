#include <DxLib.h>

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	int Cr;

	// ウインドウモードに変更
	ChangeWindowMode(true);

	if(DxLib_Init() == -1)	// ＤＸライブラリ初期化処理
	{
		return -1;	// エラーが起きたら直ちに終了
	}

	// 白色の値を取得
	Cr = GetColor(255, 255, 255);

	// 文字列の描画
	DrawString(250, 240 - 16, "Hello C World!", Cr);

	WaitKey();		// キーの入力待ち(『WaitKey』を使用)

	DxLib_End();		// ＤＸライブラリ使用の終了処理

	return 0;		// ソフトの終了
}