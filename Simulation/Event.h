#pragma once

class Event{
public:
	//�}�b�v�̃Z����P�ʂƂ����`��
	static void DrawGraphOnMap(int x, int y, int image);

	//1�}�X
	static void point(int x, int y);
	
	//����
	//static void spot1(int x, int y, int n);	//n�}�X��̑O��1�}�X
	//static void spot2(int x, int y, int n);	//n�}�X��̑O��2�}�X

	//(x, y)���S��n�}�X��̃}�X
	static void spotReachTo(int x, int y, int n);
	//(x, y)���S��min_range����max_range�܂ł̃}�X
	static void spotReachTo(int x, int y, int min_range, int max_range);
	//(x, y)�̎���9�}�X
	static void spotAround(int x, int y);
	
	//�͈�

	//(x, y)���S��n�}�X�͈�
	static void range(int x, int y, int n);
	//(x, y)���S��n�}�X�͈�(�͂ݏo���Ȃ�)
	static void rangeInField(int x, int y, int n);
	//��
	//static void lineOne(int x, int y);	//�O��1��
	//static void lineTwo(int x, int y);	//�S���1��
	
	//�O�㍶�E4��
	static void lineFour(int x, int y);
	//�O�㍶�E�l��\��(�͂ݏo���Ȃ�)
	static void lineFourInField(int x, int y, int n);
	//static void CrossFour(int x, int y);	//�΂�4��

private:
	static int color;
};