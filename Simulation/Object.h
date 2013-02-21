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

	bool isMyTurn();

protected:
	virtual void update(){};
	virtual void draw(){};
	virtual void doAction(){};
	virtual void EndMyTurn(){};

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
	bool can_move;
	bool can_act;
	int ATBgauge;
	void showStatus(Status st);
};

class Enemy;
//プレイヤークラス
class Player : public BaseObject{
public:
	Player(int x, int y, int id, int hp, int mp, int str, int def, int agi);
	virtual void update() override;
	virtual void draw() override;
	virtual void doAction() override;
	virtual void EndMyTurn() override;

	void showCommand();
	void react();

	void attack(vector<Enemy>& enemies);

	Position pos(){ return varpos; }

private:
	enum State{SELECT, MOVE, ACTION, END} state;
	Status status;

	Position varpos;
};


//エネミークラス
class Enemy : public BaseObject{
public:
	Enemy(int x, int y, int id, int hp, int mp, int str, int def, int agi);
	virtual void update() override;
	virtual void draw() override;
	virtual void doAction() override;
	virtual void EndMyTurn() override;

	bool isCntOver();

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
	int cnt;

	Status status;

	Position varpos;
};