#pragma once
#include "IScene.h"
class StageScene : public IScene {
public:
	StageScene();
	~StageScene();
	void Initialize() override;
	void Update() override;
	void Draw() override;

private:
	struct Vector2 {
		float x;
		float y;
	};
	// Player
	bool isClear = false;
	Vector2 playerPos;
	// Bullet
	bool isBullet = false;
	Vector2 bulletPos;
	Vector2 bulletOut;
	// Enemy
	Vector2 enemyPos;
	bool isEnemy = false;


};
