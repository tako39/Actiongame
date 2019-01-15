#ifndef ___BossStage
#define ___BossStage

#include "Task.h"
#include "DxLib.h"

class EnemyMgr;
class Player;
class BulletMgr;
class BombMgr;

class BossStage : public Task {
private:
	EnemyMgr *bossFriendMgr;

	int bossStageGraphic;
	int bossStageSound;
	int frameCount;

public:
	BossStage();
	~BossStage();

	void Update() {};
	void Update(Player& player, BulletMgr& bulletMgr, BombMgr& bombMgr, VECTOR bossPos);
	void Draw() {};
	void Draw(const Player& player);

	bool StageStart();		//最初の描画用
	bool FrameCheck() {		//最初の描画中であるか
		if (frameCount > 180) return false;
		return true;
	}
};

#endif