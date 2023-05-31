#include "DinosaurIdle.h"
#include "../Base/PlayerBase.h"
#include "DinosaurAttackScratch.h"
#include "DinosaurAttackPounce.h"
#include "DinosaurAttackShot.h"
#include "DinosaurAttackBite.h"
#include"DinosaurJump.h"
#include"DinosaurMove.h"

DinosaurIdle::~DinosaurIdle()
{
}

DinosaurStateBase* DinosaurIdle::Update(int padNum)
{
	m_Vec.x = 0;

	ChangeGraph(3, 9 , true);
	if (Pad::IsPress(PAD_INPUT_LEFT,padNum) || (Pad::IsPress(PAD_INPUT_RIGHT, padNum)))// XBOX X or Y
	{
		return new DinosaurMove(m_Pos, m_Vec);
	}
	if (Pad::IsPress(PAD_INPUT_UP, padNum))// XBOX A
	{
		return new DinosaurJump(m_Pos,m_Vec);
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

	return this;
}
