#pragma once
#include "Position.h"
#include "Event.h"

//�I�u�W�F�N�g�̊��N���X
class BaseObject{
protected:
public:
	BaseObject(){};
	virtual ~BaseObject(){};

protected:
	virtual void update(){};
	virtual void draw(){};

	int image;
	int id;
	char* name;
	int mapsize;
};

//�v���C���[�N���X
class Player : public BaseObject{
public:
	Player(int x, int y, int id);
	virtual void update() override;
	virtual void draw() override;
	
	void showCommand();
	void act();

	Position pos(){ return varpos; }

private:
	bool can_act;
	enum Command{SELECT, MOVE, ATTACK, END} command;

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