#pragma once
#include <vector>
#include <string>
#include "Position.h"
#include "GV.h"
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
	virtual void action(){};
	virtual void endMyTurn(){};

	typedef struct{
		int id;
		int image;
		string name;
		int maxhp;
		int maxmp;
		int hp;
		int mp;
		int str;
		int def;
		int agi;
		int mobility;
	}Status;
	void showStatus(Status st);
	
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
class Player : public BaseObject{
public:
	Player(int x, int y, int id, int hp, int mp, int str, int def, int agi, int mobility);
	virtual void update() override;
	virtual void draw() override;
	virtual void action() override;
	virtual void endMyTurn() override;

	void showCommand();

	void attack(vector<Enemy>& enemies);
	
	void setHP(int hp){ status.hp = hp; }
	int getHP() const { return status.hp; }
    int getMaxHP() const { return status.maxhp; }
	void setMP(int mp){ status.mp = mp; }
	int getMP() const { return status.mp; }
    int getMaxMP() const { return status.maxmp; }
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


//エネミークラス
class Enemy : public BaseObject{
public:
	Enemy(int x, int y, int id, int hp, int mp, int str, int def, int agi, int mobility);
	virtual void update() override;
	virtual void draw() override;
	virtual void action() override;
	virtual void endMyTurn() override;
	
	bool isCountOver(int time);
	void calcMove(vector<Player>& players);
	void calcAttack(vector<Player>& players);
	void attack(vector<Player>& players);

	void setHP(int hp){ status.hp = hp; }
	int getHP() const { return status.hp; }
    int getMaxHP() const { return status.maxhp; }
	void setMP(int mp){ status.mp = mp; }
	int getMP() const { return status.mp; }
    int getMaxMP() const { return status.maxmp; }
	void setStr(int str){ status.str = str; }
	int getStr() const { return status.str; }
	void setDef(int def){ status.def = def; }
	int getDef() const { return status.def; }
	void setAgi(int agi){ status.agi = agi; }
	int getAgi() const { return status.agi; }

	Position pos(){ return varpos; }

private:
	int wait_time;
	int attack_range;
	bool moved;
	bool attacked;
	Status status;
	
	Position varpos;
	Position move_pos;
	Position act_pos;
};
