#include "GameManager.h"
#include "Novice.h" // preKeysの定義を含むヘッダファイルをインクルード

GameManager::GameManager() {
	sceneArr_[TITLE] = std::make_unique<TitleScene>();
	sceneArr_[STAGE] = std::make_unique<StageScene>();
	sceneArr_[CLEAR] = std::make_unique<ClearScene>();
	currentSceneNo_ = TITLE;
}

GameManager::~GameManager() {}

int GameManager::run() { 
	while (Novice::ProcessMessage() == 0) {
		
		char keys[256] = {0};
		char preKeys[256] = {0};
		Novice::BeginFrame();

		
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
		prevSceneNo_ = currentSceneNo_;
		currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();

		if (prevSceneNo_ != currentSceneNo_) {
			sceneArr_[currentSceneNo_]->Initialize();
		}
		sceneArr_[currentSceneNo_]->Update();
		sceneArr_[currentSceneNo_]->Draw();
		Novice::EndFrame();

		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}
	
	return 0; 
}
