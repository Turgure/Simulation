#pragma once

#include <vector>
#include "Cursor.h"
#include "Player.h"
#include "Enemy.h"
#include "Map.h"

using namespace std;

class GameManager{
public:
	GameManager();
	void create();
	void update();
	void draw();

private:
	Map map;
	Cursor cursor;

	vector<Player> players;
	vector<Enemy> enemies;
};