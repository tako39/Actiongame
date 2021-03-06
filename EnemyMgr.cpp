#include "EnemyMgr.h"
#include "Enemy_Zako.h"
#include "Enemy_Tall.h"
#include "Enemy_Big.h"
#include "Enemy_Boss.h"
#include "Game.h"
#include "BombMgr.h"
#include "Display.h"

EnemyMgr::EnemyMgr() {
	for (int num = 0; num < MAX_ENEMY; num++) {
		enemy[num] = NULL;
	}
}

//typeの敵をenemyNum匹生成
EnemyMgr::EnemyMgr(int type, int enemyNum) {
	for (int num = 0; num < MAX_ENEMY; num++) {
		enemy[num] = NULL;
	}

	for (int num = 0; num < enemyNum; num++) {
		if (type == ENEMY_ZAKO) {
			enemy[num] = new Zako();
		}
		else if (type == ENEMY_TALL) {
			enemy[num] = new Tall();
		}
		else if (type == ENEMY_BIG) {
			enemy[num] = new Big();
		}
		else if (type == ENEMY_BOSS) {
			enemy[num] = new Boss();
		}
	}
}

//全ての敵の位置をsPosにする
void EnemyMgr::SetPosAll(VECTOR sPos) {
	for (int num = 0; num < MAX_ENEMY; num++) {
		if (enemy[num] != NULL) {
			enemy[num]->SetPos(sPos);
		}
	}
}

//sPosにtypeの敵をaddNum匹増やす
void EnemyMgr::AddEnemy(int type, int addNum, VECTOR sPos) {
	int enemyCount = 0;
	for (int num = 0; num < MAX_ENEMY; num++) {
		if (enemy[num] != NULL) continue;

		if (type == ENEMY_ZAKO) {
			enemy[num] = new Zako();
		}
		else if (type == ENEMY_TALL) {
			enemy[num] = new Tall();
		}
		else if (type == ENEMY_BIG) {
			enemy[num] = new Big();
		}
		else if (type == ENEMY_BOSS) {
			enemy[num] = new Boss();
		}
		enemy[num]->SetPos(sPos);

		enemyCount++;
		if (enemyCount >= addNum) break;
	}
}

EnemyMgr::~EnemyMgr() {
	for (int num = 0; num < MAX_ENEMY; num++) {
		delete enemy[num];
	}
}

void EnemyMgr::Update(const Player& player, BulletMgr& bulletMgr, BombMgr& bombMgr) {
	for (int num = 0; num < MAX_ENEMY; num++) {
		if (enemy[num] != NULL) {
			int type = enemy[num]->GetType();

			enemy[num]->Update();					//更新
			enemy[num]->Update(player);				//更新
			enemy[num]->Collision(player, bulletMgr, bombMgr);	//当たり判定

			if (enemy[num]->GetHitPoint() <= 0) {	//HPが0以下のとき
				enemy[num]->SetExist(false);

				if (type == ENEMY_ZAKO) {			//消える
					enemy[num] = NULL;
				}
				else if (type == ENEMY_TALL) {		//Zakoを生成
					VECTOR tallPos = enemy[num]->GetPos();
					enemy[num] = new Zako();
					enemy[num]->SetPos(tallPos);
				}
				else if (type == ENEMY_BIG) {		//Tallを生成
					VECTOR bigPos = enemy[num]->GetPos();
					enemy[num] = new Tall();
					enemy[num]->SetPos(bigPos);
				}
				else if (type == ENEMY_BOSS) {		//消える
					enemy[num] = NULL;
				}
			}
		}
	}
}

void EnemyMgr::Draw(const Player& player) {
	for (int num = 0; num < MAX_ENEMY; num++) {
		if (enemy[num] != NULL) {
			enemy[num]->Draw();			//描画
			enemy[num]->Draw(player);	//描画
		}
	}
}