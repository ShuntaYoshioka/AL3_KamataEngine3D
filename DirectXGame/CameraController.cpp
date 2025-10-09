#include "CameraController.h"
#include "Player.h"

using namespace KamataEngine;

using namespace MathUtility;

void CameraController::Initialize() { 
	camera_.Initialize(); 

}

void CameraController::Update() {
	const WorldTransform& targetWorldTransform = target_->GetWorldTransform();
	
	const Vector3& targetVelocity = target_->GetVelocity();

	targetPosition_ = targetWorldTransform.translation_ + targetoffest_ + targetVelocity * kVelocityBias;

	camera_.translation_.x = Lerp(camera_.translation_.x,targetPosition_.x,kInterpolationRate);

	
	camera_.translation_.x = max(camera_.translation_.x, camera_.translation_.x + targetMargin.left);
	camera_.translation_.x = min(camera_.translation_.x, camera_.translation_.x + targetMargin.right);
	camera_.translation_.y = max(camera_.translation_.y, camera_.translation_.y + targetMargin.bottom);
	camera_.translation_.y = min(camera_.translation_.y, camera_.translation_.y + targetMargin.top);

	camera_.translation_.x = max(camera_.translation_.x, movableArea_.left);

	camera_.translation_.x = min(camera_.translation_.x, movableArea_.right);

	camera_.translation_.y = max(camera_.translation_.y, movableArea_.bottom);

	camera_.translation_.y = min(camera_.translation_.y, movableArea_.top);


	camera_.UpdateMatrix();
}

void CameraController::Reset() {
	if (!target_)
		return;

	const WorldTransform& targetWorldTransform = target_->GetWorldTransform();

	// プレイヤー位置 + オフセットで初期位置
	camera_.translation_ = targetWorldTransform.translation_ + targetoffest_;
	targetPosition_ = camera_.translation_; 

	camera_.UpdateMatrix();
}
