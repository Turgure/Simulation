#pragma once

//�I�u�W�F�N�g�̊��N���X
class BaseObject{
protected:
public:
	BaseObject(){};
	virtual ~BaseObject(){};
	int getX() const { return x; }
	int getY() const { return y; }

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

//�v���C���[�N���X
class Player : public BaseObject{
public:
	Player(int x, int y, int id);
	virtual void update() override;
	virtual void draw() override;

	void showCommand();

private:
	enum Command{MOVE, ATTACK, END} command;
};


//�G�l�~�[�N���X
class Enemy : public BaseObject{
public:
	Enemy(int x, int y, int id);
	virtual void update() override;
	virtual void draw() override;
};