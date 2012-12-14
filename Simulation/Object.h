#pragma once
#include "Position.h"

//オブジェクトの基底クラス
class BaseObject{
protected:
public:
	BaseObject(){};
	virtual ~BaseObject(){};

protected:
	virtual void update(){};
	virtual void draw(){};

	int x;
	int y;
	int image;
	int id;
	char* name;
	int mapsize;
};

//プレイヤークラス
class Player : public BaseObject{
public:
	Player(int x, int y, int id);
	virtual void update() override;
	virtual void draw() override;
	Position pos;

	bool canAct();
	void showCommand();
	void act();

private:
	enum Command{SELECT, MOVE, ATTACK, END} command;
	bool can_act;
};


//エネミークラス
class Enemy : public BaseObject{
public:
	Enemy(int x, int y, int id);
	virtual void update() override;
	virtual void draw() override;
	Position pos;
};