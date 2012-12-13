#pragma once
#include <vector>
#include "BaseScene.h"
#include "Map.h"
#include "Cursor.h"
#include "Object.h"

using namespace std;

class BattleScene : public BaseScene{
public:
	BattleScene();
	virtual void initialize() override;
	virtual void update() override;
	virtual void draw() override;

private:
	int turn;

	Map map;
	Cursor cursor;
	vector<Player> players;
	vector<Enemy> enemies;
};