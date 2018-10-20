#include "SceneManager.h"

SceneManager* SceneManager::m_pSceneManager = nullptr;

SceneManager* SceneManager::GetInstance()
{
	if (!m_pSceneManager) m_pSceneManager = new SceneManager;

	return m_pSceneManager;
}

void SceneManager::DeleteInstnce()
{
	delete m_pSceneManager;
	m_pSceneManager = nullptr;
}

void SceneManager::Manage()
{
	if (m_currentScene == m_nextScene)
	{
		return;
	}

	switch (m_nextScene)
	{
	case SceneID::TITLE_SCENE:

		delete m_pScene;

		m_currentScene = SceneID::TITLE_SCENE;
		m_pScene = new TitleScene();

		break;
	case SceneID::HOME_SCENE:

		delete m_pScene;

		m_currentScene = SceneID::HOME_SCENE;
		m_pScene = new HomeScene();

		break;
	default:

		break;
	}
}

void SceneManager::UpDate()
{
	Manage();

	m_pScene->Update();
	m_nextScene  = m_pScene->GetNextScene();
}

void SceneManager::Render()
{
	m_pScene->Render();
}
