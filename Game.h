#ifndef ___Class_Game
#define ___Class_Game

#include "BaseScene.h"

class Map;
class Player;
class EnemyMgr;
class BulletMgr;
class BombMgr;
class Display;
class Manual;
class BossStage;

//ゲーム画面クラス
class Game : public BaseScene {
private:
	int gameSound;	//ゲームのBGM

	Player * player;
	Map *map;
	EnemyMgr *enemyMgr;
	BulletMgr *bulletMgr;
	BombMgr *bombMgr;
	Display *display;
	Manual *manual;
	BossStage * bossStage;

	int enemyPhase;	//敵の生成段階
	bool mPush;		//mが押された状態か

public:
	Game(ISceneChanger* changer);
	~Game();

	void Update();
	void Draw();

	void ChangeEnemyPhase();	//敵の生成段階の変更
};

#endif