#ifndef ___Class_BulletMgr
#define ___Class_BulletMgr

#include "Task.h"
#include "Define.h"
#include "DxLib.h"
#include "Bullet.h"

class Bullet;
class Player;

//弾を管理するクラス
class BulletMgr : public Task {
private:
	int bulletSound;			//弾を発射したときの音

	Bullet *bullet[BULLET_NUM];	//弾
	int deleteTime[BULLET_NUM];	//弾を消費した時間

public:
	BulletMgr();
	~BulletMgr();

	void Update() {};
	void Update(const Player& player);
	void Draw() {};
	void Draw(const Player& player);

	bool IsExist(int num) const {			//存在するかどうか
		if (bullet[num] != NULL) return true;
		else return false;
	}
	VECTOR GetBulletPos(int num) const {	//bullet[num]の位置を取得
		return bullet[num]->GetPos();
	}

	void DeleteBullet(int num) {			//bullet[num]を削除
		delete bullet[num];
		bullet[num] = NULL;
		deleteTime[num] = GetNowCount();
	}

	void Shot(const Player& player);		//弾を有効にする
};

#endif