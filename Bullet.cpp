#include "Bullet.h"
#include "DxLib.h"
#include "Player.h"
#include "Define.h"
#include "SceneMgr.h"
#include <math.h>

Bullet::Bullet(const Player& player) {
	bulletGraphic = LoadGraph("image/bullet.png");

	//向きを取得して発射位置を決める
	direct = player.GetDirect();
	if (direct == DIR_RIGHT) {
		pos = VGet(player.GetPos().x + CHIP_SIZE,
				   player.GetPos().y + CHIP_SIZE / 2 - BULLET_HEIGHT / 2,
				   0.0f);
	}
	else {
		pos = VGet(player.GetPos().x - BULLET_WIDTH,
				   player.GetPos().y + CHIP_SIZE / 2 - BULLET_HEIGHT / 2,
				   0.0f);
	}
	init = true;		//生成時である
	totalMove = 0.0f;	//総飛距離
}

Bullet::~Bullet() {

}

void Bullet::Update(const Player& player) {
	move = VGet(0.0f, 0.0f, 0.0f);
	if (!init) {						//生成時は移動しない
		move.x += bulletSpeed * direct;
	}
	else {
		init = false;
	}
	HitWall();							//壁に当たった時の処理
	totalMove += fabsf(move.x);			//移動距離を足す
	if (totalMove > CHIP_SIZE * 8) {	//総移動距離が8マス分になったら消える
		isExist = false;
	}
}

void Bullet::Draw(const Player& player) {
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

	DrawGraph((int)screenPos.x, (int)screenPos.y, bulletGraphic, FALSE);
}

//壁に当たった時の処理
void Bullet::HitWall() {
	float dummy = 0.0f;
	bool tauch = false;  //壁に触れたか

	//左上
	if (MapCollision(pos.y, pos.x, dummy, move.x) > 0) {
		tauch = true;
	}
	//右上
	if (MapCollision(pos.y, pos.x + BULLET_WIDTH, dummy, move.x) > 0) {
		tauch = true;
	}
	//左下
	if (MapCollision(pos.y + BULLET_HEIGHT, pos.x, dummy, move.x) > 0) {
		tauch = true;
	}
	//右下
	if (MapCollision(pos.y + BULLET_HEIGHT, pos.x + BULLET_WIDTH, dummy, move.x) > 0) {
		tauch = true;
	}

	pos.x += move.x;

	if (tauch) {
		isExist = false;	//壁に当たったら消す
	}
}