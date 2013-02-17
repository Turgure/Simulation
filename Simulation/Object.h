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

	typedef struct{
		int id;
		int image;
		char* name;
		int maxhp;
		int maxmp;
		int hp;
		int mp;
		int str;
		int def;
		int agi;
	}Status;
	void showStatus(Status st);
};

class Enemy;
//プレイヤークラス
class Player : public BaseObject{
public:
	Player(int x, int y, int id, int hp, int mp, int str, int def, int agi);
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
	Status status;

	Position varpos;

public:
	State getState() const {return state; }
};


//エネミークラス
class Enemy : public BaseObject{
public:
	Enemy(int x, int y, int id, int hp, int mp, int str, int def, int agi);
	virtual void update() override;
	virtual void draw() override;

	void setHP(int hp){ status.hp = hp; }
	int getHP() const { return status.hp; }
	void setMP(int mp){ status.mp = mp; }
	int getMP() const { return status.mp; }
	void setStr(int str){ status.str = str; }
	int getStr() const { return status.str; }
	void setDef(int def){ status.def = def; }
	int getDef() const { return status.def; }
	void setAgi(int agi){ status.agi = agi; }
	int getAgi() const { return status.agi; }

	Position pos(){ return varpos; }

private:
	Status status;

	Position varpos;
};