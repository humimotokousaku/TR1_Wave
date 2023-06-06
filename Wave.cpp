#include "Wave.h"
#include "Novice.h"

Wave::Wave() {

}
Wave::~Wave() {

}

void Wave::Initialize(float velX) {
	maxAmplitude_ = 30.0f;
	radius_ = 4.0f;
	time_ = 0;
	// 周期
	T_ = 400;
	// 波が進む速さ[m/s]
	velX_ = velX;
	// 波長(今回は使わない)
	//λ_ = T_ * velX_;
	// 振動数
	//hz_ = 1.0f / T_;
	for (int i = 0; i < kWavePoint; i++) {
		pos_[i].x = (i * kWavePointWhile);;
		pos_[i].y = kFirstWaterLevel;
		amplitude_[i] = 0;
	}
}

void Wave::Update(const char* keys, const char* preKeys) {
	// key入力
	if (keys[DIK_UP]) {
		maxAmplitude_ += 1;
	}
	if (keys[DIK_DOWN]) {
		maxAmplitude_ -= 1;
	}
	if (keys[DIK_V]) {
		velX_ += 1.0f / 60.0f;
	}
	if (keys[DIK_T]) {
		T_ += 1;
	}

	// 波の動き
	for (int i = 0; i < kWavePoint; i++) {
		amplitude_[i] = sinf(2 * static_cast<float>(M_PI) / T_ * (time_ * 3 - (pos_[i].x / velX_)));
		pos_[i].y = kFirstWaterLevel + maxAmplitude_ * amplitude_[i];
	}
	// 時間経過
	time_++;
}

void Wave::Draw(int texture, unsigned int color) {
	for (int i = 0; i < kWavePoint; i++) {
		Novice::DrawQuad(
			pos_[i].x - radius_, pos_[i].y - radius_,
			pos_[i].x + radius_, pos_[i].y - radius_,
			pos_[i].x - radius_, pos_[i].y + radius_,
			pos_[i].x + radius_, pos_[i].y + radius_,
			0, 0,
			32, 32,
			texture,
			color
		);
	}
}
