#pragma once
#include <vector>
#include "BaseScene.h"
#include "Stage.h"
#include "Cursor.h"
#include "ObjectManager.h"

using namespace std;

class BattleScene : public BaseScene{
public:
	BattleScene();
	virtual void initialize() override;
	virtual void update() override;
	virtual void draw() override;

private:
	int id, hp, mp, str, def, agi;
	int turn;
	bool isMoving;
	int cnt;

	Stage stage;
	Cursor cursor;
	vector<Player> players;
	vector<Enemy> enemies;
};