#ifndef ___Define
#define ___Define
//定義するクラス

//スクリーン
const int SCREEN_WIDTH = 640;	// 画面の横幅
const int SCREEN_HEIGHT = 480;	// 画面の縦幅
const int CHIP_SIZE = 32;		// 一つのチップのサイズ

const int SCREEN_HALF_W = 320;	//横幅の半分
const int SCREEN_HALF_H = 240;	//縦幅の半分


//ステージ
const int STAGE_NUM = 3;	//ステージ数
const int STAGE_WIDTH[STAGE_NUM] = { 20, 40, 33 };	//ステージの横のチップ数
const int STAGE_HEIGHT[STAGE_NUM] = { 15, 20, 20 };	//ステージの縦のチップ数


//マップ
const int BACK = 0;		//水色背景
const int GROUND = 1;	//茶色地面
const int CLOUD = 2;	//白地面

//アルファベット
const int A = 20;
const int B = 21;
const int C = 22;
const int D = 23;
const int E = 24;
const int F = 25;
const int G = 26;
const int H = 27;
const int I = 28;
const int J = 29;
const int K = 30;
const int L = 31;
const int M = 32;
const int N = 33;
const int O = 34;
const int P = 35;
const int Q = 36;
const int R = 37;
const int S = 38;
const int T = 39;
const int U = 40;
const int V = 41;
const int W = 42;
const int X = 43;
const int Y = 44;
const int Z = 45;

//プレイヤー
const int MAX_HP = 100;	//最大ＨＰ

const int DIR_RIGHT = 1;	//右向き
const int DIR_LEFT = -1;	//左向き

const float Gravity = 0.5f;		//重力
const float Speed = 5.0f;		//横移動速度
const float AirSpeed = 3.0f;	//空中での横移動速度
const float JumpPower = 12.0f;	//ジャンプ力

const int PUNCH_WIDTH = CHIP_SIZE;	//パンチの横幅
const int PUNCH_HEIGHT = CHIP_SIZE;	//パンチの縦幅

//弾
const int BULLET_WIDTH = 16;	//弾の横幅
const int BULLET_HEIGHT = 8;	//弾の縦幅
const int BULLET_NUM = 5;		//弾の数
const float bulletSpeed = 8.0f;	//弾の速度

//爆弾
const int BOMB_WIDTH = CHIP_SIZE;	//爆弾の横幅
const int BOMB_HEIGHT = CHIP_SIZE;	//爆弾の縦幅
const int BOMB_RANGE = CHIP_SIZE * 2;	//爆弾の範囲
const int BOMB_NUM = 3;		//爆弾の数

//攻撃力
const int DAMAGE_PUNCH  = 20;	//パンチのダメージ
const int DAMAGE_BULLET = 10;	//弾のダメージ
const int DAMAGE_BOMB   = 30;	//爆弾のダメージ

//敵
const int MAX_ENEMY = 100;	//最大の敵の数
const int ENEMY_TYPE = 4;	//敵の種類

const int ENEMY_ZAKO = 0;	//Zakoクラスの敵
const int ENEMY_TALL = 1;	//Tallクラスの敵
const int ENEMY_BIG = 2;	//Big クラスの敵
const int ENEMY_BOSS = 3;	//Bossクラスの敵

const int HP_ZAKO = 20;	//ZAKOのHP
const int HP_TALL = 40;	//TALLのHP
const int HP_BIG = 60;	//BIGのHP
const int HP_BOSS = 500;	//BOSSのHP

//方向
const int NONE = -1;	//なし

const int UP = 0;	//上
const int DOWN = 1;	//下
const int LEFT = 2;	//左
const int RIGHT = 3;	//右


//キーボード
const int KEY_NUM = 256;	//入力

//その他
const int fps = 60;			//一秒間の描画数
const float PI = 3.14f;		//円周率
const float EPS = 1.0f;		//誤差

#endif