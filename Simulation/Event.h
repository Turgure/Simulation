#pragma once

class Event{
public:
	static void point(int x, int y, int diffX, int diffY);
	
	//����
	//static void spot1(int x, int y, int n);	//n�}�X��̑O��1�}�X
	//static void spot2(int x, int y, int n);	//n�}�X��̑O��2�}�X
	static void spotReachTo(int x, int y, int n);	//(x, y)���S��n�}�X��̃}�X
	static void spotAround(int x, int y);	//(x, y)�̎���9�}�X
	
	//�͈�
	static void range(int x, int y, int n);	//(x, y)���S��n�}�X�͈�
	//��
	//static void lineOne(int x, int y);	//�O��1��
	//static void lineTwo(int x, int y);	//�S���1��
	static void lineFour(int x, int y);	//�O�㍶�E4��
	//static void CrossFour(int x, int y);	//�΂�4��

private:
	static int color;
};