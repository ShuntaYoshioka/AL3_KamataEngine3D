#pragma once
#include "KamataEngine.h"

class Player {
	enum class LRDirection {
		kRight,
		kLeft,
	};

	LRDirection lrDirection_ = LRDirection::kRight;

public:
	/// 初期化
	void Initialize(KamataEngine::Model* model, KamataEngine::Camera* camera, const KamataEngine::Vector3& position);
	/// 更新
	void Update();
	/// 描画
	void Draw();

	
	float turnFirstRotationY_ = 0.0f;

	float turnTimer_ = 0.0f;

	bool onGround_ = true;

	static inline const float kTimeTurn = 0.3f; 

	static inline const float kAcceleration = 0.05f;

	static inline const float kAttenuation= 0.3f;

	static inline const float kLimitRunSpeed = 2.0f;

	static inline const float kGravityAcceleration = 0.4f;

		static inline const float kLimitFallSpeed = 2.0f;

		static inline const float kJumpAcceleration = 3.0f;

	KamataEngine::Vector3 velocity_ = {};

	KamataEngine::Camera* camera_ = nullptr;

	const KamataEngine::WorldTransform& GetWorldTransform() const { return worldTransform_; };

	const KamataEngine::Vector3& GetVelocity() const { return velocity_; }

private:
	// ワールド変換データ
	KamataEngine::WorldTransform worldTransform_;

	// モデル
	KamataEngine::Model* model_ = nullptr;
};

