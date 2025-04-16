#include "GameScene.h"

using namespace KamataEngine;

void GameScene::Initialize() {
	// ファイル名を指定してテクスチャを読み込む
	textureHandle_ = TextureManager::Load("./Resources./uvChecker.png");

	// 3Dモデルの生成
	model_ = Model::Create();

	// 自キャラ生成
	player_ = new Player();

	// ワールドトランスフォームの初期化
	worldTransform_.Initialize();

	// カメラの初期化
	camera_.Initialize();

	// 自キャラの初期化
	player_->Initialize();
}

void GameScene::Update() {
	// 自キャラの更新
	player_->Update();
}

void GameScene::Draw() {
	// 自キャラの描画
	player_->Draw();
}

GameScene::~GameScene() { delete model_; }