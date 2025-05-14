#include "Player.h"
#include "KamataEngine.h"
#include "MyMath.h"

void Player::Initialize(KamataEngine::Model* model, KamataEngine::Camera* camera) {
	assert(model);

	model_ = model;
	worldTransform_.Initialize();
	camera_ = camera;
}

void Player::Update() {

	worldTransform_.matWorld_ = MakeAffineMatrix(worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);
	// 行列を定義バッファに転送
	worldTransform_.TransferMatrix();
}

void Player::Draw() { model_->Draw(worldTransform_, *camera_); }