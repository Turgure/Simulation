#pragma once

class Event{
public:
	static void point(int x, int y, int diffX, int diffY);
	
	//距離
	//static void spot1(int x, int y, int n);	//nマス先の前方1マス
	//static void spot2(int x, int y, int n);	//nマス先の前後2マス
	static void spotReachTo(int x, int y, int n);	//(x, y)中心でnマス先のマス
	static void spotAround(int x, int y);	//(x, y)の周囲9マス
	
	//範囲
	static void range(int x, int y, int n);	//(x, y)中心でnマス範囲
	//列
	//static void lineOne(int x, int y);	//前方1列
	//static void lineTwo(int x, int y);	//全後方1列
	static void lineFour(int x, int y);	//前後左右4列
	//static void CrossFour(int x, int y);	//斜め4列

private:
	static int color;
};