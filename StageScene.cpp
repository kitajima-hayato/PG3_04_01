#include "StageScene.h"
#include <Novice.cpp>

StageScene::StageScene() {}

StageScene::~StageScene() {}

void StageScene::Initialize() 
{ playerPos = {640, 500};
	bulletOut = {-50, -50};
	bulletPos = {bulletOut};
	enemyPos = {640, 200};
	isClear = false;
	isBullet = false;
	isEnemy = false;
}

void StageScene::Update() {
	if (keys[DIK_UP] != 0) {
		playerPos.y -= 5;
	}
	if (keys[DIK_DOWN] != 0) {
		playerPos.y += 5;
	}
	if (keys[DIK_LEFT] != 0) {
		playerPos.x -= 5;
	}
	if (keys[DIK_RIGHT] != 0) {
		playerPos.x += 5;
	}
	if (keys[DIK_SPACE] == 0 && preKeys[DIK_SPACE] != 0) {
		isBullet = true;
		bulletPos = playerPos;
	}
	if (isBullet) {
		bulletPos.y -= 5;
		if (bulletPos.y < 0) {
			isBullet = false;
			bulletPos = bulletOut;
		}
	}
	if (isEnemy) {
		enemyPos.y += 5;
		if (enemyPos.y > 720) {
			isEnemy = false;
		}
	}
	if (isBullet && isEnemy) {
		if (bulletPos.x > enemyPos.x - 50 && bulletPos.x < enemyPos.x + 50 && bulletPos.y > enemyPos.y - 50 && bulletPos.y < enemyPos.y + 50) {
			isEnemy = false;
			isBullet = false;
			bulletPos = bulletOut;
		}
	}
	if (isEnemy) {
		if (playerPos.x > enemyPos.x - 50 && playerPos.x < enemyPos.x + 50 && playerPos.y > enemyPos.y - 50 && playerPos.y < enemyPos.y + 50) {
			isClear = true;
		}
	}
	if (isClear) {
		sceneNo = CLEAR;
	}
}

void StageScene::Draw() {
	
	Novice::DrawBox((int)playerPos.x - 50, (int)playerPos.y - 50, 100, 100, 0, WHITE, kFillModeSolid);
	if (isBullet) {
		Novice::DrawBox((int)bulletPos.x - 10, (int)bulletPos.y - 10, 20, 20, 0, BLUE, kFillModeSolid);
	}
	if (isEnemy) {
		Novice::DrawBox((int)enemyPos.x - 50, (int)enemyPos.y - 50, 100, 100, 0, RED, kFillModeSolid);
	}
	if (isClear) {
		Novice::DrawBox(0, 0, 1280, 720, 0, GREEN, kFillModeSolid);
		
	}
}
