#pragma once

class Event{
public:
	static void point(int x, int y, int diffX, int diffY);
	
	//£
	//static void spot1(int x, int y, int n);	//n}XæÌOû1}X
	//static void spot2(int x, int y, int n);	//n}XæÌOã2}X
	static void spotReachTo(int x, int y, int n);	//(x, y)SÅn}XæÌ}X
	static void spotAround(int x, int y);	//(x, y)ÌüÍ9}X
	
	//ÍÍ
	static void range(int x, int y, int n);	//(x, y)SÅn}XÍÍ
	//ñ
	//static void lineOne(int x, int y);	//Oû1ñ
	//static void lineTwo(int x, int y);	//Sãû1ñ
	static void lineFour(int x, int y);	//Oã¶E4ñ
	//static void CrossFour(int x, int y);	//Îß4ñ

private:
	static int color;
};