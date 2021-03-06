#include "Display.h"
#include "Player.h"
#include "EnemyMgr.h"

Display::Display() {
	hpGreeen = LoadGraph("image/hp_green.png");
	hpOrange = LoadGraph("image/hp_orange.png");
	hpRed = LoadGraph("image/hp_red.png");
}

Display::~Display() {

}

void Display::Update() {

}

void Display::Draw(const Player& player) {
	DrawHp(VGet(240.0f, 0.0f, 0.0f), player.GetHitPoint(), MAX_HP);
}

//HPの描画
void Display::DrawHp(VECTOR hpPos, int hitPoint, int maxHp) {
	int hp = hitPoint;	//現在のHP
	int hpGraphic;		//HPの画像

	if (hp > maxHp / 2) {		//半分より上は緑
		hpGraphic = hpGreeen;
	}
	else if (hp > maxHp / 4) {	//半分以下は橙
		hpGraphic = hpOrange;
	}
	else {						//4分の1以下は赤
		hpGraphic = hpRed;
	}

	SetFontSize(20);
	DrawFormatString((int)hpPos.x - 30, 0, GetColor(255, 0, 255), "HP:");
	
	int hpRate = (int)(((float)hitPoint / maxHp) * 100);	//最大HPにおける現在のHPの割合

	for (int i = 0; i < hpRate; i++) {						//割合分だけ描画
		DrawGraph((int)hpPos.x + 4 * i, (int)hpPos.y, hpGraphic, TRUE);
	}
}