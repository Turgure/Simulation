#pragma once

class Event{
public:
	//マップのセルを単位とする
	//キャラの描画に使用
	static void DrawGraphOnMap(int x, int y, int image);

	static int GetColorMove(){ return color_move; }
	static int GetColorAttack(){ return color_attack; }
	static int GetColorSupport(){ return color_support; }
	
	//以下移動・行動範囲のフラグ処理関数

	//static void spot1(int x, int y, int n);	//nマス先の前方1マス
	//static void spot2(int x, int y, int n);	//nマス先の前後2マス

	//行動用
	//(x, y)中心でnマス先のマス
	static void spotReachTo(int x, int y, int color, int n);
	//行動用
	//(x, y)中心でmin_rangeからmax_rangeまでのマス
	static void spotReachTo(int x, int y, int color, int min_range, int max_range);
	//行動用
	//(x, y)の周囲8マス
	static void spotAround(int x, int y, int color);
	//移動・行動用
	//(x, y)中心でnマス範囲
	static void range(int x, int y, int color, int n, bool consider_resistance);

	//列
	//static void lineOne(int x, int y);	//前方1列
	//static void lineTwo(int x, int y);	//全後方1列
	
	//前後左右4列
	static void lineFour(int x, int y);
	//前後左右四列表示(はみ出さない)
	static void lineFourInField(int x, int y, int n);
	//static void CrossFour(int x, int y);	//斜め4列

private:
	static int dist[8][2];
	static int color_move;
	static int color_attack;
	static int color_support;
};