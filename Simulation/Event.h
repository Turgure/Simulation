#pragma once

class Event{
public:
	static void range(int x, int y, int diffX, int diffY);
	//static void nearFront(int x, int y);	//前方1マス
	//static void nearTwo(int x, int y);	//前後2マス
	static void nearFour(int x, int y);	//周囲4マス
	static void nearEight(int x, int y);	//周囲8マス
	//static void lineOne(int x, int y);	//前方1列
	//static void lineTwo(int x, int y);	//全後方1列
	static void lineFour(int x, int y);	//前後左右4列

private:
	static int color;
};