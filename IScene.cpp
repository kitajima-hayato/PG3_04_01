#include "IScene.h"

int IScene::sceneNo = TITLE;


IScene::~IScene() {}

int IScene::GetSceneNo() const { return sceneNo; }


