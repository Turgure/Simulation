#pragma once

class Event{
public:
	static void range(int x, int y, int diffX, int diffY);
	//static void nearFront(int x, int y);	//�O��1�}�X
	//static void nearTwo(int x, int y);	//�O��2�}�X
	static void nearFour(int x, int y);	//����4�}�X
	static void nearEight(int x, int y);	//����8�}�X
	//static void lineOne(int x, int y);	//�O��1��
	//static void lineTwo(int x, int y);	//�S���1��
	static void lineFour(int x, int y);	//�O�㍶�E4��

private:
	static int color;
};