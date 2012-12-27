#pragma once
#include "Position.h"
#include "Event.h"

//�I�u�W�F�N�g�̊��N���X
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
};

//�v���C���[�N���X
class Player : public BaseObject{
public:
	Player(int x, int y, int id);
	virtual void update() override;
	virtual void draw() override;
	
	void showCommand();
	void react();

	Position pos(){ return varpos; }

private:
	bool can_act;
	enum State{SELECT, MOVE, ATTACK, END} state;

	Position varpos;
};


//�G�l�~�[�N���X
class Enemy : public BaseObject{
public:
	Enemy(int x, int y, int id);
	virtual void update() override;
	virtual void draw() override;

	Position pos(){ return varpos; }

private:
	Position varpos;
};