#pragma once

class Event{
public:
	//マップのセルを単位とした描画
	static void DrawGraphOnMap(int x, int y, int image);

	//1マス
	static void point(int x, int y);
	
	//距離
	//static void spot1(int x, int y, int n);	//nマス先の前方1マス
	//static void spot2(int x, int y, int n);	//nマス先の前後2マス

	//(x, y)中心でnマス先のマス
	static void spotReachTo(int x, int y, int n);
	//(x, y)中心でmin_rangeからmax_rangeまでのマス
	static void spotReachTo(int x, int y, int min_range, int max_range);
	//(x, y)の周囲9マス
	static void spotAround(int x, int y);
	
	//範囲

	//(x, y)中心でnマス範囲
	static void range(int x, int y, int n);
	//(x, y)中心でnマス範囲(はみ出さない)
	static void rangeInField(int x, int y, int n);
	//列
	//static void lineOne(int x, int y);	//前方1列
	//static void lineTwo(int x, int y);	//全後方1列
	
	//前後左右4列
	static void lineFour(int x, int y);
	//前後左右四列表示(はみ出さない)
	static void lineFourInField(int x, int y, int n);
	//static void CrossFour(int x, int y);	//斜め4列

private:
	static int color;
};