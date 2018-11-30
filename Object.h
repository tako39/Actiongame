#ifndef ___Class_Object
#define ___Class_Object

#include "Task.h"
#include "DxLib.h"

class Object : public Task {
protected:
	int graphic_R;  //右向き画像
	int graphic_L;  //左向き画像

	float ver_Speed;  //垂直方向の移動量
	bool jump_Flag;   //trueならジャンプ中

	VECTOR pos;   //位置
	VECTOR move;  //移動

	int direct;   //方向

public:
	VECTOR GetPos() const { return pos; }  //位置の取得

	int GetMap(int y, int x) const;  //map[y][x]の値の取得
	int GetMapChip(float y, float x) const;  //位置(x, y)に該当するマップチップの値の取得

	void Move(float moveY, float moveX); //移動
	int MapCollision(float Y, float X, float &moveY, float &moveX); //当たり判定
};

#endif