#pragma once
#include <string>

class ObjectStatus{
public:
	void showStatus(int x, int y) const;

	void setHP(int hp){ this->hp = hp; }
	int getHP() const { return hp; }
	int getMaxHP() const { return maxhp; }
	void setMP(int mp){ this->mp = mp; }
	int getMP() const { return mp; }
	int getMaxMP() const { return maxmp; }
	void setStr(int str){ this->str = str; }
	int getStr() const { return str; }
	void setDef(int def){ this->def = def; }
	int getDef() const { return def; }
	void setAgi(int agi){ this->agi = agi; }
	int getAgi() const { return agi; }
	void setMob(int mob){ this->mobility = mob; }
	int getMob() const { return mobility; }

protected:
	int id;
	int image;
	std::string name;
	int maxhp;
	int maxmp;
	int hp;
	int mp;
	int str;
	int def;
	int agi;
	int mobility;
};