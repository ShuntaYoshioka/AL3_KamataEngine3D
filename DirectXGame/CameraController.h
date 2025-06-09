#pragma once
#include "KamataEngine.h"

class CameraController {
public:

	void Initialize();

	void Update();

	void Reset();


	private:
		//カメラ
	    KamataEngine::Camera camera;
};