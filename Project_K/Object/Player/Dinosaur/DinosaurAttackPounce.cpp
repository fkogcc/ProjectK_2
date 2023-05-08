#include "DinosaurAttackPounce.h"
#include "DinosaurIdle.h"

namespace
{
	constexpr float kJumpPower = -15.0f;

	constexpr float kGravity = 1.25f;

	constexpr float kMoveSpeed = 12.0f;
}

DinosaurAttackPounce::DinosaurAttackPounce(Vec2 pos, Vec2 vec)
{
	{
		m_Pos = pos;
		m_Vec = vec;
		m_imagePosX = 0;
		m_imagePosY = 4;
		m_JumpPower = kJumpPower;
	}
}

DinosaurAttackPounce::~DinosaurAttackPounce()
{
}

DinosaurStateBase* DinosaurAttackPounce::Update()
{
	if (m_imagePosX < 3)
	{
		ChangeGraph(6, 6, false);
	}
	else
	{
		m_imagePosY = 5;

		m_imagePosX = 7 + (m_gapTime / 5);
		m_gapTime++;
	}

	if (m_JumpPower < -kJumpPower)
	{
		m_Pos.y += m_JumpPower;
		m_JumpPower += kGravity;

		m_Pos.x += kMoveSpeed;
	}

	if (m_gapTime > 15)
	{
		return new DinosaurIdle(m_Pos, m_Vec);
	}

	return this;
}
