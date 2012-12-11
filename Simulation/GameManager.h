#pragma once

#include <vector>
#include "Cursor.h"
#include "Player.h"
#include "Enemy.h"
#include "StageScene.h"

using namespace std;

class GameManager{
public:
	GameManager();
	void create();
	void update();
	void draw();

private:
	StageScene stageScene;
	Cursor cursor;

	vector<Player> players;
	vector<Enemy> enemies;
};