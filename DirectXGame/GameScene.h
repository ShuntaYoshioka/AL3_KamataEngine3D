#pragma once
#include "KamataEngine.h"
#include "Player.h"
#include "Skydome.h"
#include "Enemy.h"
#include <vector>
#include "MapChipField.h"
#include "CameraController.h"
#include "DeathParticles.h"
#include "TitleScene.h"

class GameScene {

	private:
	// テクスチャハンドル
	uint32_t textureHandle_ = 0;

	bool finished_ = false;


public:

	enum class Phase {
		kPlay,
		kDeath,
	};

	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();
  
	// デストラクタ
	~GameScene();

	// 3Dモデル
	KamataEngine::Model* modelBlock_;

	KamataEngine::Model* modelSkydome_ = nullptr;

	KamataEngine::Model* modelPlayer_ = nullptr;

	KamataEngine::Model* modelEnemy_ = nullptr;

	KamataEngine::Model* modelDeathParticle_ = nullptr;
	
	// ワールドトランスフォーム
	KamataEngine::WorldTransform worldTransform_;

	// カメラ
	KamataEngine::Camera camera_;

	//自キャラ
	Player* player_ = nullptr;

	//sky
	Skydome* skydome_ = nullptr;

	//敵
	std::list<Enemy*> enemies_;

	//パーティクル
	DeathParticles* deathParticles_ = nullptr;
	
	//カメラコントローラ
	CameraController* cameraController_ = nullptr;

	//マップチップフィールド
	MapChipField* mapChipField_;

	//デバッグカメラ有効
	bool isDebugCameraActive_ = false;

	//デバッグカメラ
	KamataEngine::DebugCamera* debugCamera_ = nullptr;

	std::vector<std::vector<KamataEngine::WorldTransform*>> worldTransformBlocks_;

	void GenerateBlocks();

	void CheckAllCollisions();

	void ChangePhase();

	//ゲームプレイから開始
	Phase phase_;

	bool isFinished() const { return finished_; }

};
