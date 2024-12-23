#pragma once
enum SCENE {
	TITLE,
	STAGE,
	CLEAR,
};

class IScene {
protected:
	static int sceneNo;

public:
	virtual ~IScene();
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	int GetSceneNo() const;

	char keys[256] = {0};
	char preKeys[256] = {0};



};
