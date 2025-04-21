#include "Player.h"
#include "KamataEngine.h"

void Player::Initialize(KamataEngine::Model* model, uint32_t textureHandle, KamataEngine::Camera* camera) {
	assert(model); 

	model_ = model;
	textHandle_ = textureHandle;
	worldTransform_.Initialize();
	camera_ = camera;

}

void Player::Update() {

	//行列を定義バッファに転送
	worldTransform_.TransferMatrix();
}

void Player::Draw() { model_->Draw(worldTransform_, *camera_, textHandle_); }