#ifndef ___Class_BaseScene
#define ___Class_BaseScene

#include "Task.h"
#include "ISceneChanger.h"

//シーンの基底クラス。
class BaseScene : public Task {

protected:
	int mImageHandle;  //画像ハンドル格納用変数
	ISceneChanger* mSceneChanger;  //クラス所有元にシーン切り替えを伝えるインターフェイス

public:
	BaseScene(ISceneChanger* changer);
	virtual ~BaseScene() {}
	virtual void Initialize() override {}  //初期化処理をオーバーライド。
	virtual void Finalize() override;      //終了処理をオーバーライド。
	virtual void Update() override {}      //更新処理をオーバーライド。
	virtual void Draw() override;          //描画処理をオーバーライド。

};

#endif