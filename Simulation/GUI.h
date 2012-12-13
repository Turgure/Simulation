#pragma once

//�L�[�{�[�h����
class Keyboard{
public:
	Keyboard();
	static void initialize();
	static int update();
	static int get(int keyID);
private:
	static int key[256];
};

//�J�[�\������
class Cursor{
public:
	Cursor(int x, int y);
	void update();
	void draw();

private:
	int x;
	int y;
	int image;
};