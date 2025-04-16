#include "GameScene.h"

using namespace KamataEngine;

void GameScene::Initialize() { 
	//ファイル名を指定してテクスチャを読み込む
	textureHandle_ = TextureManager::Load("./Resources./uvChecker.png"); 

	//3Dモデルの生成
	model_ = Model::Create();

	//ワールドトランスフォームの初期化
	worldTransform_.Initialize();

	//カメラの初期化
	camera_.Initialize();
}

void GameScene::Update() {
}

void GameScene::Draw() {

	//DirectCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	//3Dモデル描画前処理
	Model::PreDraw(dxCommon->GetCommandList());

	//3Dモデル描画
	model_->Draw(worldTransform_, camera_, textureHandle_);

	//3Dモデル描画処理後
	Model::PostDraw();
}

GameScene::~GameScene() { delete model_; }
