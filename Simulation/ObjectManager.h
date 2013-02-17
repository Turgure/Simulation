#pragma once
#include <vector>
#include "Object.h"
using namespace std;

class ObjectManager{
public:
	static void create(vector<Player> &players);
	static void create(vector<Enemy> &enemies);

private:
	static int id;
	static int hp;
	static int mp;
	static int str;
	static int def;
	static int agi;
	
	static FILE* fp;
	static int ret;
};