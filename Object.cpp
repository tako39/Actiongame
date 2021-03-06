#include "Object.h"
#include "Define.h"
#include "Stage.h"
#include "Game.h"
#include "Map.h"

Object::Object() {
	isExist = true;
	ver_Speed = 0.0f;
	jump_Flag = false;
}

Object::~Object() {

}

//当たり判定
int Object::MapCollision(float Y, float X, float &moveY, float &moveX) {
	float Top_y, Bottom_y, Left_x, Right_x;  //プレイヤーの当たり判定の位置

	//移動先
	float nextY = Y + moveY;
	float nextX = X + moveX;

	int chip = Map::GetMapChip(nextY, nextX);

	//壁に当たっているかどうか
	if (chip == GROUND || chip == CLOUD || (20 <= chip && chip <= 45)) {

		//壁について
		Top_y = (float)((int)nextY / CHIP_SIZE)     * CHIP_SIZE;     // 上辺の Y 座標
		Bottom_y = (float)((int)nextY / CHIP_SIZE + 1) * CHIP_SIZE;  // 下辺の Y 座標
		Left_x = (float)((int)nextX / CHIP_SIZE)     * CHIP_SIZE;    // 左辺の X 座標
		Right_x = (float)((int)nextX / CHIP_SIZE + 1) * CHIP_SIZE;   // 右辺の X 座標

		//当たっていたら壁から離す

		//上辺に衝突
		if (moveY > 0.0f) {
			moveY = Top_y - Y - EPS;
			return UP;
		}
		//下辺に衝突
		if (moveY < 0.0f) {
			moveY = Bottom_y - Y + EPS;
			return DOWN;
		}

		//左辺に衝突
		if (moveX > 0.0f) {
			moveX = Left_x - X - EPS;
			return LEFT;
		}
		//右辺に衝突
		if (moveX < 0.0f) {
			moveX = Right_x - X + EPS;
			return RIGHT;
		}

	}

	return NONE; //当たっていない
}