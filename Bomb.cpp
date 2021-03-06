#include "Bomb.h"
#include "Player.h"
#include "SceneMgr.h"
#include "Keyboard.h"

Bomb::Bomb(const Player& player) {
	setTime = GetNowCount();
	bombSound = LoadSoundMem("sound/bomb.mp3");
	bombGraphic_Count3 = LoadGraph("image/bomb_count3.png");
	bombGraphic_Count2 = LoadGraph("image/bomb_count2.png");
	bombGraphic_Count1 = LoadGraph("image/bomb_count1.png");
	bombGraphic_Red = LoadGraph("image/bomb_red.png");
	explosionGraphic = LoadGraph("image/explosion.png");
	pos = player.GetPos();
}

Bomb::~Bomb() {

}

void Bomb::Update() {
	if (GetNowCount() - setTime > 3000) {			//設置してから3秒経ったとき爆発
		PlaySoundMem(bombSound, DX_PLAYTYPE_BACK);	//爆弾の爆発音を鳴らす
		isExist = false;
	}
	
	ver_Speed += Gravity;	//重力を加える
	move.y = ver_Speed;

	Move(move.y, move.x);	//移動
}

void Bomb::Draw(const Player& player) {
	//スクロール処理
	if (player.GetPos().x < SCREEN_HALF_W) {
		screenPos.x = pos.x;
	}
	else if (player.GetPos().x < STAGE_WIDTH[SceneMgr::nowStage] * CHIP_SIZE - SCREEN_HALF_W) {
		screenPos.x = SCREEN_HALF_W + pos.x - player.GetPos().x;
	}
	else {
		screenPos.x = pos.x - (STAGE_WIDTH[SceneMgr::nowStage] * CHIP_SIZE - SCREEN_WIDTH);
	}

	if (player.GetPos().y < SCREEN_HALF_H) {
		screenPos.y = pos.y;
	}
	else if (player.GetPos().y < STAGE_HEIGHT[SceneMgr::nowStage] * CHIP_SIZE - SCREEN_HALF_H) {
		screenPos.y = SCREEN_HALF_H + pos.y - player.GetPos().y;
	}
	else {
		screenPos.y = pos.y - (STAGE_HEIGHT[SceneMgr::nowStage] * CHIP_SIZE - SCREEN_HEIGHT);
	}

	//カウントによって画像を変える
	if (GetNowCount() - setTime > 2800) {
		//爆発時に爆発のエフェクトを描画
		DrawGraph((int)screenPos.x - CHIP_SIZE * 2, (int)screenPos.y - CHIP_SIZE * 2, explosionGraphic, TRUE);
	}
	else if (GetNowCount() - setTime > 1500) {
		//爆発が近いときは点滅させる
		if (GetNowCount() % 3 == 0) {
			DrawGraph((int)screenPos.x, (int)screenPos.y, bombGraphic_Red, FALSE);
		}
		else {
			DrawGraph((int)screenPos.x, (int)screenPos.y, bombGraphic_Count1, FALSE);
		}
	}
	else if (GetNowCount() - setTime > 1000) {
		DrawGraph((int)screenPos.x, (int)screenPos.y, bombGraphic_Count2, FALSE);
	}
	else {
		DrawGraph((int)screenPos.x, (int)screenPos.y, bombGraphic_Count3, FALSE);
	}
}

//移動
void Bomb::Move(float moveY, float moveX) {
	float dummy = 0.0f;		//ダミー

	//上下成分の移動
	{
		//左下
		if (MapCollision(pos.y + CHIP_SIZE - EPS, pos.x + EPS, moveY, dummy) == UP) {
			ver_Speed = 0.0f;
		}
		//右下
		if (MapCollision(pos.y + CHIP_SIZE - EPS, pos.x + CHIP_SIZE - EPS, moveY, dummy) == UP) {
			ver_Speed = 0.0f;
		}

		pos.y += moveY;
	}
}