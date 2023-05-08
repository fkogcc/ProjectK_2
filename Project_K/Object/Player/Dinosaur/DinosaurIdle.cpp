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

DinosaurStateBase* DinosaurIdle::Update()
{
	m_Vec.x = 0;

	ChangeGraph(3, 9 , true);
	if (Pad::isPress(PAD_INPUT_LEFT) || (Pad::isPress(PAD_INPUT_RIGHT)))// XBOX X or Y
	{
		return new DinosaurMove(m_Pos, m_Vec);
	}
	if (Pad::isPress(PAD_INPUT_UP))// XBOX A
	{
		return new DinosaurJump(m_Pos,m_Vec);
	}
	if (Pad::isPress(PAD_INPUT_2))// XBOX B
	{
		return new DinosaurAttackBite(m_Pos, m_Vec);
	}
	if (Pad::isPress(PAD_INPUT_3))// XBOX X or Y
	{
		return new DinosaurAttackScratch(m_Pos, m_Vec);
	}
	if (Pad::isPress(PAD_INPUT_4))// XBOX X or Y
	{
		return new DinosaurAttackShot(m_Pos, m_Vec);
	}
	if (Pad::isPress(PAD_INPUT_5))// XBOX X or Y
	{
		return new DinosaurAttackPounce(m_Pos, m_Vec);
	}

	return this;
}
