#include "EnemyMgr.h"
#include "Enemy_Zako.h"
#include "Enemy_Tall.h"
#include "Enemy_Big.h"
#include "Enemy_Boss.h"
#include "Game.h"
#include "BombMgr.h"
#include <typeinfo>

EnemyMgr::EnemyMgr(int type, int num) : enemyNum(num) {
	if (type == ENEMY_ZAKO) {
		for (int num = 0; num < enemyNum; num++) {
			enemy[num] = new Zako();
		}
	}
	else if (type == ENEMY_TALL) {
		for (int num = 0; num < enemyNum; num++) {
			enemy[num] = new Tall();
		}
	}
	else if (type == ENEMY_BIG) {
		for (int num = 0; num < enemyNum; num++) {
			enemy[num] = new Big();
		}
	}
	else if (type == ENEMY_BOSS) {
		for (int num = 0; num < enemyNum; num++) {
			enemy[num] = new Boss();
		}
	}
}

EnemyMgr::~EnemyMgr() {
	for (int num = 0; num < enemyNum; num++) {
		delete enemy[num];
	}
}

void EnemyMgr::Update(const Player& player, BulletMgr& bulletMgr, BombMgr& bombMgr) {
	for (int num = 0; num < enemyNum; num++) {
		if (enemy[num] != NULL) {
			enemy[num]->Update();		//更新
			enemy[num]->Update(player);	//更新
			enemy[num]->Collision(player, bulletMgr, bombMgr);	//当たり判定
			if (enemy[num]->GetExist() == false) {	//倒されたとき
				if (enemy[num]->GetType() == ENEMY_ZAKO) {
					delete enemy[num];
					enemy[num] = NULL;
				}
				else if (enemy[num]->GetType() == ENEMY_TALL) {
					VECTOR tallPos = enemy[num]->GetPos();
					delete enemy[num];
					enemy[num] = new Zako(tallPos);
				}
				else if (enemy[num]->GetType() == ENEMY_BIG) {
					VECTOR bigPos = enemy[num]->GetPos();
					delete enemy[num];
					enemy[num] = new Tall(bigPos);
				}
			}
		}
	}
	bombMgr.DeleteBombAll();	//爆発した爆弾の処理
}

void EnemyMgr::Draw(const Player& player) {
	for (int num = 0; num < enemyNum; num++) {
		if (enemy[num] != NULL) {
			enemy[num]->Draw();  //描画
			enemy[num]->Draw(player);
		}
	}
}