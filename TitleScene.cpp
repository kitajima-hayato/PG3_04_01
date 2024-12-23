#include "TitleScene.h"
#include <Novice.cpp>

TitleScene::TitleScene() {}

TitleScene::~TitleScene() {}

void TitleScene::Initialize() {}

void TitleScene::Update() {
	if (keys[DIK_SPACE] == 0 && preKeys[DIK_SPACE] != 0) {
		sceneNo = STAGE;
	}
}

void TitleScene::Draw() { Novice::DrawBox(0, 0, 1280, 720, 0, GREEN, kFillModeSolid); }
