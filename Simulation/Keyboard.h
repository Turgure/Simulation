#pragma once

class Keyboard{
public:
	Keyboard();
	static void initialize();
	static int update();
	static int get(int keyID);
private:
	static int key[256];
};