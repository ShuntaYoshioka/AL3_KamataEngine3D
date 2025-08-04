#pragma once
#include <KamataEngine.h>
class TitleScene {
public:
	void Initialize();
	void Update();
	void Draw();

	KamataEngine::Model* model_;
	KamataEngine::Model* modelPlayer_;

	KamataEngine::Camera camera_;

	KamataEngine::WorldTransform worldTransform_;

	KamataEngine::WorldTransform worldTransformPlayer_;

	bool isFinished() const { return finished_; }

private:
	bool finished_ = false;

};
