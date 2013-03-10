#pragma once
#include <vector>
#include <string>
#include "GV.h"
#include "Position.h"
#include "ObjectStatus.h"
using namespace std;

//オブジェクトの基底クラス
class BaseObject{
public:
	BaseObject(){};
	virtual ~BaseObject(){};

	virtual void stepATBgauge(){};
	bool isMyTurn();


protected:
	virtual void update(){};
	virtual void draw(){};
	virtual void action(){};
	virtual void endMyTurn(){};
	
	enum State{SELECT, MOVE, ACTION, END, WAIT} state;
	int ATBgauge;
	bool can_move;
	bool can_act;

public:
	//0=>SELECT, 1=>MOVE, ACTION=>2, 3=>END, 4=>WAIT
	State getState() const { return state; }
};

class Player;
class Enemy;
//オブジェクト管理クラス
//生成等を行う
class ObjectManager{
public:
	static void create(vector<Player> &players, string filename, int x, int y);
	static void create(vector<Enemy> &enemies, string filename);
};

//プレイヤークラス
class Player : public BaseObject, public ObjectStatus{
public:
	Player(int x, int y, int id, int hp, int mp, int str, int def, int agi, int mobility);
	virtual void update() override;
	virtual void draw() override;
	virtual void action() override;
	virtual void endMyTurn() override;
	virtual void stepATBgauge() override;

	void showCommand();

	void attack(vector<Enemy>& enemies);
	
	Position pos(){ return mypos; }

private:
	Position mypos;
};


//エネミークラス
class Enemy : public BaseObject, public ObjectStatus{
public:
	Enemy(int x, int y, int id, int hp, int mp, int str, int def, int agi, int mobility);
	virtual void update() override;
	virtual void draw() override;
	virtual void action() override;
	virtual void endMyTurn() override;
	virtual void stepATBgauge() override;
	
	bool isCountOver(int time);
	void calcMove(vector<Player>& players);
	void calcAttack(vector<Player>& players);
	void attack(vector<Player>& players);

	Position pos(){ return mypos; }

private:
	int wait_time;
	int attack_range;
	bool moved;
	bool attacked;
	
	Position mypos;
	Position move_pos;
	Position act_pos;
};
