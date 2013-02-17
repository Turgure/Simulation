#include <DxLib.h>
#include "Object.h"

void BaseObject::showStatus(Status st){
	DrawFormatString(200,  0, GetColor(255,255,255), "id  %d", st.id);
	DrawFormatString(200, 16, GetColor(255,255,255), "hp  %d/%d", st.hp, st.maxhp);
	DrawFormatString(200, 32, GetColor(255,255,255), "mp  %d/%d", st.mp, st.maxmp);
	DrawFormatString(200, 48, GetColor(255,255,255), "str %d", st.str);
	DrawFormatString(200, 64, GetColor(255,255,255), "def %d", st.def);
	DrawFormatString(200, 80, GetColor(255,255,255), "agi %d", st.agi);
}