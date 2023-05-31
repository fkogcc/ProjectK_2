#include "DinosaurMove.h"
#include "DinosaurStateBase.h"
#include <DxLib.h>
#include "DinosaurIdle.h"
#include"DinosaurJump.h"
#include"DinosaurAttackBite.h"
#include"DinosaurAttackPounce.h"
#include"DinosaurAttackScratch.h"
#include"DinosaurAttackShot.h"

namespace
{
	constexpr float kMoveSpeed = 10.0f;
}


DinosaurMove::~DinosaurMove()
{
}

void DinosaurMove::IsMove(int padNum)
{
	m_Vec.x = 0;
	if (Pad::IsPress(PAD_INPUT_LEFT, padNum))// XBOX X or Y
	{
		m_Vec.x = -kMoveSpeed;
	}

	if (Pad::IsPress(PAD_INPUT_RIGHT, padNum))
	{
		m_Vec.x = kMoveSpeed;
	}
}

DinosaurStateBase* DinosaurMove::Update(int padNum)
{
	ChangeGraph(3, 6, true);

	IsMove(padNum);

	m_Pos.x += m_Vec.x;

	if (Pad::IsPress(PAD_INPUT_UP, padNum))// XBOX X or Y
	{
		return new DinosaurJump(m_Pos,m_Vec);
	}

	if (Pad::IsPress(PAD_INPUT_UP, padNum))// XBOX A
	{
		return new DinosaurJump(m_Pos, m_Vec);
	}
	if (Pad::IsPress(PAD_INPUT_2, padNum))// XBOX B
	{
		return new DinosaurAttackBite(m_Pos, m_Vec);
	}
	if (Pad::IsPress(PAD_INPUT_3, padNum))// XBOX X or Y
	{
		return new DinosaurAttackScratch(m_Pos, m_Vec);
	}
	if (Pad::IsPress(PAD_INPUT_4, padNum))// XBOX X or Y
	{
		return new DinosaurAttackShot(m_Pos, m_Vec);
	}
	if (Pad::IsPress(PAD_INPUT_1, padNum))// XBOX X or Y
	{
		return new DinosaurAttackPounce(m_Pos, m_Vec);
	}

	if (m_Vec.x != 0)	// キャラクターが動いているとき
	{
		return this;
	}

	return new DinosaurIdle(m_Pos,m_Vec);
}
