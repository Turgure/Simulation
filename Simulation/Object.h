#pragma once

//オブジェクトの基底クラス
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

//プレイヤークラス
class Player : public BaseObject{
public:
	Player(int x, int y, int id);
	virtual void update() override;
	virtual void draw() override;

	void showCommand();

private:
	enum Command{MOVE, ATTACK, END} command;
};


//エネミークラス
class Enemy : public BaseObject{
public:
	Enemy(int x, int y, int id);
	virtual void update() override;
	virtual void draw() override;
};