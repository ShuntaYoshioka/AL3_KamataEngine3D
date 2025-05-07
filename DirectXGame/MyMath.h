#pragma once
#include "KamataEngine.h"
//アフィン変換

KamataEngine::Matrix4x4 MakeAffineMatrix(KamataEngine::Vector3& scale, 
	KamataEngine::Vector3& rotation, KamataEngine::Vector3& translation);