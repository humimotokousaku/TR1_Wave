#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "Wave.h"
#include "Player.h"

const char kWindowTitle[] = "LE2B_22_フミモト_コウサク";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// 画像読み込み
	int whiteRect = Novice::LoadTexture("white1x1.png");

	// 宣言
	// 波が左から右に動く
	Wave* rightMoveSin = new Wave();
	rightMoveSin->Initialize(2.5f);

	// 波が右から左に動く
	Wave* leftMoveSin = new Wave();
	leftMoveSin->Initialize(-2.5f);

	// player
	Player* player = new Player();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		rightMoveSin->Update(keys, preKeys);

		player->Update(*rightMoveSin, keys, preKeys);

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		rightMoveSin->Draw(whiteRect,BLUE);
		// player
		player->Draw(whiteRect);

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}
	delete player;
	delete leftMoveSin;
	delete rightMoveSin;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
