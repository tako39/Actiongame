#include "EnemyMgr.h"
#include "Game.h"
#include "Enemy_Zako.h"
#include "BombMgr.h"

EnemyMgr::EnemyMgr() {
	for (int num = 0; num < ENEMY_NUM; num++) {
		enemy[num] = new Zako();
	}
}

EnemyMgr::~EnemyMgr() {
	for (int num = 0; num < ENEMY_NUM; num++) {
		delete enemy[num];
	}
}

void EnemyMgr::Update(const Player& player, BulletMgr& bulletMgr, BombMgr& bombMgr) {
	for (int num = 0; num < ENEMY_NUM; num++) {
		if (enemy[num] != NULL) {
			enemy[num]->Update();		//更新
			enemy[num]->Update(player);	//更新
			enemy[num]->Collision(player, bulletMgr, bombMgr);	//当たり判定
			if (enemy[num]->GetExist() == false) {	//倒されたとき
				delete enemy[num];
				enemy[num] = NULL;
			}
		}
	}
	bombMgr.DeleteBombAll();	//爆発した爆弾の処理
}

void EnemyMgr::Draw(const Player& player) {
	for (int num = 0; num < ENEMY_NUM; num++) {
		if (enemy[num] != NULL) {
			enemy[num]->Draw();  //描画
			enemy[num]->Draw(player);
		}
	}
}