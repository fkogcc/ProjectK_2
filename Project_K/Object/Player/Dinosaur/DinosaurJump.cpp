#include "DinosaurJump.h"
#include"DinosaurIdle.h"

namespace
{
	constexpr float kJumpPower = -20.0f;

	constexpr float kGravity = 0.8f;
}

DinosaurJump::DinosaurJump(Vec2 vec)
{	
	m_Vec.x = vec.x;
	m_imagePosX = 0;
	m_imagePosY = 4;
	m_Vec.y = kJumpPower;
	m_attackFlag = false;
}

DinosaurJump::~DinosaurJump()
{
}

DinosaurStateBase* DinosaurJump::Update(int padNum)
{
	m_Vec.y += kGravity;

	if (m_imagePosX < 3)
	{
		ChangeGraph(8, 6, false);
	}
	else
	{
		m_imagePosX = 3;
		m_gapTime++;
	}

	if (m_Vec.y > -kJumpPower)
	{
		m_Vec.y = 0;
		return new DinosaurIdle(m_Vec);
	}

	return this;
}
