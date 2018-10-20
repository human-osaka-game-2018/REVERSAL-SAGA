#pragma once
#include <windows.h>
#include "Scene\Scene.h"

enum class SceneID
{
	VOID_SCENE,
	TITLE_SCENE,
	HOME_SCENE,
};

class SceneManager
{
public:
	SceneManager* GetInstance();
	void DeleteInstnce();
	void UpDate();
	void Render();


private:
	SceneManager();
	~SceneManager();
	void Manage();
	static SceneManager* m_pSceneManager;
	Scene* m_pScene = nullptr;
	SceneID m_currentScene = SceneID::VOID_SCENE;
	SceneID m_nextScene = SceneID::TITLE_SCENE;
};
