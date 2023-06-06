#include "Player.h"
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "ImGuiManager.h"

Player::Player(){
	pos_.x = 0;
	pos_.y = kFirstWaterLevel;
	radius_ = 16.0f;
	maxAmplitude_ = 30;
	amplitude_ = 0;
	isDraw_ = false;
}
Player::~Player(){

}

void Player::Initialize() {

}

void Player::Update(Wave wave, const char* keys, const char* preKeys) {
	// key入力

	// playerの表示の有無
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		if (!isDraw_) {
			isDraw_ = true;
		}
		else {
			isDraw_ = false;
		}
	}
	if (isDraw_) {
		if (keys[DIK_A]) {
			pos_.x -= 3;
		}
		if (keys[DIK_D]) {
			pos_.x += 3;
		}

		maxAmplitude_ = wave.GetMaxAmplitude();
		// 水粒子の波に合わせて動く
		amplitude_ = maxAmplitude_ * sinf(2 * static_cast<float>(M_PI) / wave.GetT() * (wave.GetTime() * 3 - (pos_.x / wave.GetVelX())));
		pos_.y = kFirstWaterLevel + amplitude_;
	}

	// 数値の調整と表示
	ImGui::Begin("Player");
	ImGui::Text("Keys Info  A,D:Move  SPACE:isDraw");
	ImGui::Text("isDraw:%d", isDraw_);
	ImGui::Text("nowAmplitude:%f", amplitude_);
	ImGui::Text("maxAmplitude:%f", maxAmplitude_);
	ImGui::Text("pos.y:%f", pos_.y);
	ImGui::SliderFloat("pos.x", inputFloat, 0.0f, kWindowWidth);
	ImGui::End();
}

void Player::Draw(int texture) {
	if (isDraw_) {
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
}