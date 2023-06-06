#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

#include "Common.h"

class Wave
{
public:  // メンバ関数
	Wave();
	~Wave();

	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="velX">波の進む速さ</param>
	void Initialize(float velX);

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update(const char* keys, const char* preKeys);

	/// <summary>
	/// 描画
	/// </summary>
	void Draw(int texture, unsigned int color);

	// Getter
	float GetT() { return T_; }
	float GetTime() { return time_; }
	float GetVelX() { return velX_; }
	float GetMaxAmplitude() { return maxAmplitude_; }

	// Setter
	void SetVelX(float velX) { this->velX_ = velX; }

public:  //メンバ変数
	Vector2 pos_[kWavePoint];		// 座標
	float amplitude_[kWavePoint];	// 振幅
	float maxAmplitude_;			// 振幅の最大値と最小値
    float radius_;					// 半径

	float time_;					// 今の時間(frame単位)
	float T_;						// 周期
	float velX_;					// 波が進む速さ[m/s]	
	//float λ_;					    // 波長(今回は使わない)
	//float hz_;						// 振動数	
};

