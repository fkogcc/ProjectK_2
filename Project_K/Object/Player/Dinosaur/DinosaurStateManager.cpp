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
// 初期化
void DinosaurStateManager::Init()
{
	m_pState = new DinosaurIdle({ 500,500 }, { 0,0 });
}
// 終了
void DinosaurStateManager::End()
{
	assert(m_pState);// 確認処理
	if (!m_pState)	return;

	//m_pAttack->End();// 終了処理
	//delete m_pScene;
}
// 毎フレームの処理
void DinosaurStateManager::Update(int padNum)
{
	if (Pad::IsPress(PAD_INPUT_LEFT,padNum) && !m_pState->GetAttackFlag())// XBOX X or Y
	{
		m_lookLeft = true;
	}

	if (Pad::IsPress(PAD_INPUT_RIGHT, padNum) && !m_pState->GetAttackFlag())// XBOX X or Y
	{
		m_lookLeft = false;
	}
	assert(m_pState);// 確認処理
	if (!m_pState)	return;

	m_pState->SetLookFlag(m_lookLeft);
	DinosaurStateBase* pState = m_pState->Update();// AttackBaseのupdate処理呼び出し

	if (pState != m_pState)
	{
	//	m_pState->End();// 終了処理
		delete m_pState;

		m_pState = pState;
		m_pState->Init(m_Handle);// 初期化
	}
}
// 描画
void DinosaurStateManager::Draw()
{
	assert(m_pState);
	if (!m_pState)	return;
	m_pState->Draw(m_Handle , m_lookLeft);// 描画
}

bool DinosaurStateManager::GetshotFlag()
{
	return m_pState->GetshotFlag();
}

Vec2 DinosaurStateManager::GetPos()
{
	return m_pState->GetPos();
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
