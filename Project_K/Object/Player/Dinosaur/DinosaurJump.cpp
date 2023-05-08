#include "DinosaurJump.h"
#include"DinosaurIdle.h"

namespace
{
	constexpr float kJumpPower = -20.0f;

	constexpr float kGravity = 0.8f;
}

DinosaurJump::DinosaurJump(Vec2 pos, Vec2 vec)
{	
	m_Pos = pos;
	m_Vec = vec;
	m_imagePosX = 0;
	m_imagePosY = 4;
	m_JumpPower = kJumpPower;
}

DinosaurJump::~DinosaurJump()
{
}

DinosaurStateBase* DinosaurJump::Update()
{
	m_Pos.y += m_JumpPower;
	m_Pos.x += m_Vec.x;
	m_JumpPower += kGravity;

	if (m_imagePosX < 3)
	{
		ChangeGraph(8, 6, false);
	}
	else
	{
		m_imagePosX = 3;
		m_gapTime++;
	}

	if (m_JumpPower > -kJumpPower)
	{
		return new DinosaurIdle(m_Pos, m_Vec);
	}

	return this;
}
