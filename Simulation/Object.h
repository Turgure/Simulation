#pragma once
#include <vector>
#include "Position.h"
#include "Event.h"

using namespace std;

//オブジェクトの基底クラス
class BaseObject{
public:
	BaseObject(){};
	virtual ~BaseObject(){};

protected:
	virtual void update(){};
	virtual void draw(){};

	int image;
	int id;
	char* name;
	int hp;
};

class Enemy;
//プレイヤークラス
class Player : public BaseObject{
public:
	Player(int x, int y, int id);
	virtual void update() override;
	virtual void draw() override;
	
	void attack(vector<Enemy>& enemies);

	void showCommand();
	void react();

	Position pos(){ return varpos; }

private:
	bool can_act;
	bool can_move;
	bool can_attack;
	enum State{SELECT, MOVE, ATTACK, END} state;

	Position varpos;

public:
	State getState() const {return state; }
};


//エネミークラス
class Enemy : public BaseObject{
public:
	Enemy(int x, int y, int id);
	virtual void update() override;
	virtual void draw() override;

	void setHP(int hp);
	int getHP() const;

	Position pos(){ return varpos; }

private:
	Position varpos;
};