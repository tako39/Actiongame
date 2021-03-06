#ifndef ___Class_BombMgr
#define ___Class_BombMgr

#include "Task.h"
#include "Define.h"
#include "DxLib.h"
#include "Bomb.h"

class Bomb;
class Player;

//爆弾の管理クラス
class BombMgr : public Task {
private:
	int putSound;				//爆弾を置いたときの音

	Bomb *bomb[BOMB_NUM];		//爆弾
	int deleteTime[BOMB_NUM];	//爆弾が処理された時間
	bool explosion[BOMB_NUM];	//爆発しているか

public:
	BombMgr();
	~BombMgr();

	void Update();
	void Draw() {};
	void Draw(const Player& player);

	void BombSet(const Player& player);	//爆弾の設置

	bool IsExist(int num) const {		//存在するかどうか
		if (bomb[num] != NULL) return true;
		else return false;
	}
	VECTOR GetBombPos(int num) const {	//bomb[num]の位置を取得
		return bomb[num]->GetPos();
	}
	bool IsExplosion(int num) const {	//bomb[num]が爆発したか
		return explosion[num];
	}

	void DeleteBomb(int num) {			//爆弾の処理
		delete bomb[num];
		bomb[num] = NULL;
		deleteTime[num] = GetNowCount();
		explosion[num] = false;
	}

	void DeleteBombAll() {				//爆発した爆弾の処理
		for (int bombNum = 0; bombNum < BOMB_NUM; bombNum++) {
			if (IsExplosion(bombNum)) {	//爆発したなら削除
				DeleteBomb(bombNum);
			}
		}
	}
};

#endif