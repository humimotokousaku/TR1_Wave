#include "Player.h"
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

Player::Player(){
	pos_.x = 0;
	pos_.y = kFirstWaterLevel;
	radius_ = 16.0f;
	maxAmplitude_ = 30;
	amplitude_ = 0;
}
Player::~Player(){

}

void Player::Initialize() {

}

void Player::Update(Wave wave, const char* keys, const char* preKeys) {
	// key入力
	if (keys[DIK_W]) {
		pos_.y -= 3;
	}
	if (keys[DIK_A]) {
		pos_.x -= 3;
	}
	if (keys[DIK_S]) {
		pos_.y += 3;
	}
	if (keys[DIK_D]) {
		pos_.x += 3;
	}

	// 水粒子の波に合わせて動く
	amplitude_ = sinf(2 * static_cast<float>(M_PI) / wave.GetT() * (wave.GetTime() * 3 - (pos_.x / wave.GetVelX())));
	pos_.y = kFirstWaterLevel + wave.GetMaxAmplitude() * amplitude_;
}

void Player::Draw(int texture) {
	Novice::DrawQuad(
		pos_.x - radius_, pos_.y - radius_,
		pos_.x + radius_, pos_.y - radius_,
		pos_.x - radius_, pos_.y + radius_,
		pos_.x + radius_, pos_.y + radius_,
		0, 0,
		32, 32,
		texture,
		BLACK
	);
}