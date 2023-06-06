#pragma once
#include "Vector2.h"

// 画面幅
const int kWindowWidth = 1280;  // 横幅
const int kWindowHeight = 720;	// 縦幅

const int kWavePoint = 100;							// 水の粒子の数
const float kWavePointWhile = 12.8f;				// 水粒子間の距離
const float kFirstWaterLevel = kWindowHeight / 2;	// 波の揺れてないときの水粒子の位置