#include "ClearScene.h"
#include <Novice.cpp>

ClearScene::ClearScene() {}

ClearScene::~ClearScene() {}

void ClearScene::Initialize() {}

void ClearScene::Update() {
	if (keys[DIK_SPACE] == 0 && preKeys[DIK_SPACE] != 0) {
		sceneNo = TITLE;
	}
}

void ClearScene::Draw() {
	Novice::DrawBox(0, 0, 1280, 720, 0, BLUE, kFillModeSolid);

}
