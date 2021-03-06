#ifndef ___Class_EnemyMgr
#define ___Class_EnemyMgr

#include "Define.h"
#include "DxLib.h"
#include "Task.h"
#include "Player.h"
#include "Enemy.h"

class Enemy;
class BulletMgr;
class BombMgr;

//敵を管理するクラス
class EnemyMgr : public Task {
private:
	Enemy *enemy[MAX_ENEMY];	//敵
	VECTOR enemyPos[MAX_ENEMY];	//敵の位置

public:
	EnemyMgr();
	EnemyMgr(int type, int enemyNum);	//typeの敵をnum匹生成する
	~EnemyMgr();

	void Update() {};
	void Update(const Player& player, BulletMgr& bulletMgr, BombMgr& bombMgr);
	void Draw() {};
	void Draw(const Player& player);

	void SetPosAll(VECTOR sPos);	//全ての敵をsPosに設置する

	void AddEnemy(int type, int addNum, VECTOR sPos);	//sPosにtypeの敵をaddNum匹増やす

	bool IsExist(int num) const {	//存在するかどうか
		if (enemy[num] != NULL) return true;
		else return false;
	}
	VECTOR GetEnemyPos(int num) const {	//enemy[num]の位置を取得
		return enemy[num]->GetPos();
	}
	int GetEnemyType(int num) const {	//enemy[num]の種類を取得
		return enemy[num]->GetType();
	}
	int GetEnemyHp(int num) const {		//enemy[num]のHPを取得
		return enemy[num]->GetHitPoint();
	}

	bool IsNoEnemy() {	//敵が全て倒されたか
		for (int num = 0; num < MAX_ENEMY; num++) {
			if (enemy[num] != NULL) {
				return false;
			}
		}
		return true;
	}
};

#endif