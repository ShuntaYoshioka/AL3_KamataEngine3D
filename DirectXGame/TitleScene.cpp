#include "TitleScene.h"

using namespace KamataEngine;

void TitleScene::Initialize() {
	// 3Dモデル
	model_ = Model::CreateFromOBJ("titleFont");
	modelPlayer_ = Model::CreateFromOBJ("player");

	// カメラ初期化
	camera_.Initialize();

	worldTransform_.Initialize();
	worldTransformPlayer_.Initialize();
}

void TitleScene::Update() { 
	if (Input::GetInstance()->PushKey(DIK_SPACE)) {
		finished_ = true;
	}

}

void TitleScene::Draw() {

	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model::PreDraw(dxCommon->GetCommandList());

	model_->Draw(worldTransform_, camera_);

	modelPlayer_->Draw(worldTransformPlayer_, camera_);

Model::PostDraw();
}
