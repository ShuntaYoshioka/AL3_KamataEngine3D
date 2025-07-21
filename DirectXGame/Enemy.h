#pragma once
#include "KamataEngine.h"
#include "MyMath.h"

class Player;

class Enemy {
public:
	/// 初期化
	void Initialize(KamataEngine::Model* model, KamataEngine::Camera* camera, const KamataEngine::Vector3& position);
	void Update();
	void Draw();

	// 歩行スピード
	static inline const float kWalkSpeed = 0.05f;

	float walkTimer_ = 0.0f;

	KamataEngine::Vector3 velocity_ = {};
	// AABBを取得
	AABB GetAABB();
	KamataEngine::Vector3 GetWorldPosition();

	//衝突応答
	void OnCollision(const Player* player);

private:
	KamataEngine::WorldTransform worldTransform_; // ワールドトランスふぉーむ
	KamataEngine::Model* model_ = nullptr;        // モデル
	KamataEngine::Camera* camera_ = nullptr;      // カメラ
	;
};
