#include <DxLib.h>
#include "ObjectStatus.h"

void ObjectStatus::showStatus(int x, int y) const{
		DrawFormatString(x, y+ 0, GetColor(255,255,255), "id  %d", id);
		DrawFormatString(x, y+16, GetColor(255,255,255), "hp  %d/%d", hp, maxhp);
		DrawFormatString(x, y+32, GetColor(255,255,255), "mp  %d/%d", mp, maxmp);
		DrawFormatString(x, y+48, GetColor(255,255,255), "str %d", str);
		DrawFormatString(x, y+64, GetColor(255,255,255), "def %d", def);
		DrawFormatString(x, y+80, GetColor(255,255,255), "agi %d", agi);
		DrawFormatString(x, y+94, GetColor(255,255,255), "mob %d", mobility);
	}