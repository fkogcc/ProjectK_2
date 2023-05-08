#include <cassert>
#include "SceneManager.h"
#include "SceneMain.h"
#include "SceneTitle.h"
#include "SceneCharacterSelect.h"

SceneManager::SceneManager():
	m_pScene(nullptr)
{
}
// ������
void SceneManager::Init()
{
	m_pScene = new SceneCharacterSelect;
	m_pScene->Init();
}
// �I��
void SceneManager::End()
{
	assert(m_pScene);// �m�F����
	if (!m_pScene)	return;

	m_pScene->End();// �I������
	delete m_pScene;
}
// ���t���[���̏���
void SceneManager::Update()
{
	assert(m_pScene);// �m�F����
	if (!m_pScene)	return;

	SceneBase* pScene = m_pScene->Update();// SceneBase��update�����Ăяo��

	if (pScene != m_pScene)
	{
		m_pScene->End();// �I������
		delete m_pScene;
		
		m_pScene = pScene;
		m_pScene->Init();// ������
	}
}
// �`��
void SceneManager::Draw()
{
	assert(m_pScene);
	if (!m_pScene)	return;
	m_pScene->Draw();// �`��
}