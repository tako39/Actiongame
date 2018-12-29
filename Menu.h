#ifndef ___Class_Menu
#define ___Class_Menu

#include "BaseScene.h"

class Player;
class Map;
class BulletMgr;
class BombMgr;

//メニュー画面クラス
class Menu : public BaseScene {
private:
	Player *player;
	Map *map;
	BulletMgr *bulletMgr;
	BombMgr *bombMgr;

public:
	Menu(ISceneChanger* changer);
	~Menu();

	void Update()     override;  //更新処理をオーバーライド。
	void Draw()       override;  //描画処理をオーバーライド。
};

#endif