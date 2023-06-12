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
	m_pState = new DinosaurIdle({ 0,0 });
	m_deadFlag = false;
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
void DinosaurStateManager::Update(int padNum)
{
	if (m_deadFlag)
	{
		m_pState->SetDeadFlag();
	}
	if (Pad::IsPress(PAD_INPUT_LEFT, padNum) && !m_pState->GetAttackFlag())// XBOX X or Y
	{
		m_lookLeft = true;
	}

	if (Pad::IsPress(PAD_INPUT_RIGHT, padNum) && !m_pState->GetAttackFlag())// XBOX X or Y
	{
		m_lookLeft = false;
	}
	assert(m_pState);// �m�F����
	if (!m_pState)	return;

	m_pState->SetLookFlag(m_lookLeft);
	DinosaurStateBase* pState = m_pState->Update(padNum);// AttackBase��update�����Ăяo��

	if (m_ondamageFlag)
	{
		pState = new DinosaurIdle({ 0,0 });
	}

	if (pState != m_pState)
	{
		//	m_pState->End();// �I������
		delete m_pState;

		m_pState = pState;
		m_pState->Init(m_Handle);// ������
	}
}
// �`��
void DinosaurStateManager::Draw(Vec2 pos)
{
	assert(m_pState);
	if (!m_pState)	return;
	m_pState->Draw(m_Handle, m_lookLeft, pos);// �`��
}

bool DinosaurStateManager::GetshotFlag()
{
	return m_pState->GetshotFlag();
}

Vec2 DinosaurStateManager::GetVec()
{
	return m_pState->GetVec();
}

bool DinosaurStateManager::GetAttackFlag()
{
	return m_pState->GetAttackFlag();
}

int DinosaurStateManager::GetAttackSizeLeft()
{

	return ((m_lookLeft) ? m_pState->GetAttackSizeLeft() : -m_pState->GetAttackSizeRight());
}

int DinosaurStateManager::GetAttackSizeTop()
{
	return m_pState->GetAttackSizeTop();
}

int DinosaurStateManager::GetAttackSizeRight()
{
	return ((m_lookLeft) ? m_pState->GetAttackSizeRight() : -m_pState->GetAttackSizeLeft());
}

int DinosaurStateManager::GetAttackSizeBottom()
{
	return m_pState->GetAttackSizeBottom();
}

int DinosaurStateManager::GetOnDamage()
{
	return m_pState->GetAttackDamage();
}

void DinosaurStateManager::SetAttackFlag()
{
	m_pState->SetAttackFlag(false);
}
