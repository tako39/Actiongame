#include "DxLib.h"
#include "SceneMgr.h"
#include "Define.h"
#include "Keyboard.h"
#include "Frame.h"

//メイン関数
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	//ウィンドウモード変更と初期化と裏画面設定
	SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);

	SceneMgr sceneMgr;
	Frame frame;

	//画面更新 & メッセージ処理 & 画面消去
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		
		frame.Update();		//フレームの更新

		UpdateKey();		//キーの更新

		sceneMgr.Update();	//シーンの更新
		sceneMgr.Draw();	//シーンの描画


		frame.Wait();		//待機
	}

	DxLib_End();	// DXライブラリ終了処理
	return 0;
}