#pragma once
#include "Common.h"
#include "Wave.h"

class Player
{
public: // メンバ関数
	Player();
	~Player();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update(Wave wave, const char* keys, const char* preKeys);

	/// <summary>
	/// 描画
	/// </summary>
	void Draw(int texture);

private: // メンバ変数
	Vector2 pos_;
	float radius_;
	float maxAmplitude_;
	float amplitude_;
};

