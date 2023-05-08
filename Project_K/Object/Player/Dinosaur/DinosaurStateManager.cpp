#include "DinosaurStateManager.h"
#include <cassert>
#include "DinosaurAttackBite.h"
#include "DinosaurAttackPounce.h"
#include "DinosaurAttackScratch.h"
#include "DinosaurAttackShot.h"
#include "DinosaurIdle.h"
#include "DinosaurJump.h"
#include "DinosaurMove.h"
#include "DinosaurIdle.h"

DinosaurStateManager::DinosaurStateManager(int Handle) :
	m_Handle(Handle),
	m_pState(nullptr)
{
}
// ������
void DinosaurStateManager::Init()
{
	m_pState = new DinosaurIdle({ 0,0 }, { 0,0 });
}
// �I��
void DinosaurStateManager::End()
{
	assert(m_pState);// �m�F����
	if (!m_pState)	return;

	//m_pAttack->End();// �I������
	//delete m_pScene;
}
// ���t���[���̏���
void DinosaurStateManager::Update()
{
	assert(m_pState);// �m�F����
	if (!m_pState)	return;

	DinosaurStateBase* pState = m_pState->Update();// AttackBase��update�����Ăяo��

	if (m_pState != m_pState)
	{
	//	m_pState->End();// �I������
		delete m_pState;

		m_pState = m_pState;
		m_pState->Init(m_Handle);// ������
	}
}
// �`��
void DinosaurStateManager::Draw()
{
	assert(m_pState);
	if (!m_pState)	return;
	m_pState->Draw();// �`��
}