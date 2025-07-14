#include "Enemy.h"
#include "MyMath.h"
#include <numbers>

void Enemy::Initialize(KamataEngine::Model* model, KamataEngine::Camera* camera, const KamataEngine::Vector3& position) {
	
	model_ = model;
	camera_ = camera;
	walkTimer_ = 0.0f;

	worldTransform_.Initialize();
	worldTransform_.translation_ = position;
	worldTransform_.rotation_.y = -std::numbers::pi_v<float> / 2.0f;

}

void Enemy::Update() {
	//移動
	 worldTransform_.translation_.x -= kWalkSpeed;

	 walkTimer_ += 1.0f / 60.0f;

	 worldTransform_.rotation_.x = std::sin(walkTimer_ * 2.0f * 3.14159265f); 
	 
	// 行列の更新
	worldTransform_.matWorld_ = MakeAffineMatrix(worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);
	// 行列を定義バッファに転送
	worldTransform_.TransferMatrix();
}

void Enemy::Draw() { model_->Draw(worldTransform_, *camera_); }