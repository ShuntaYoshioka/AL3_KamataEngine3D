#pragma once
#include "KamataEngine.h"
class GameScene {
public:
	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

	//デストラクタ
	~GameScene();

	//3Dモデル
	KamataEngine::Model* model_ = nullptr;

	//ワールドトランスフォーム
	KamataEngine::WorldTransform worldTransform_;

	//カメラ
	KamataEngine::Camera camera_;

private:
	// テクスチャハンドル
	uint32_t textureHandle_ = 0;
};
