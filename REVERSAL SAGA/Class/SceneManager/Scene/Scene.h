#pragma once
#include "../SceneManager.h"

class Scene
{
	friend class SceneManager;
public:
	virtual void Update() = 0;
	virtual void Render() = 0;
	SceneID GetNextScene();

protected:
	Scene();
	~Scene();

	SceneID m_nextScene;
};