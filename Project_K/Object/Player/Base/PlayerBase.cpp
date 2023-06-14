#include "PlayerBase.h"
#include "../../Shot/NullShot.h"

namespace
{
	constexpr float kAccX = 0.5f;
	constexpr float kAccY = 1.0f;

	constexpr float kKnockBackX = 10.0f;
	constexpr float kKnockBackY = -5.0f;
}

PlayerBase::PlayerBase()
{
	for (int i = 0; i < kShotMax; i++)
	{
		m_pShot[i] = new NullShot();
	}
}

void PlayerBase::SetKnockBack(float toPlayer)
{
	if (toPlayer < 0.0f)
	{
		m_knockBack = { kKnockBackX ,kKnockBackY };
	}

	if (toPlayer >= 0.0f)
	{
		m_knockBack = { -kKnockBackX ,kKnockBackY };
	}
}

void PlayerBase::DebugDrawCollision()
{
	if (m_attackFlag)
	{
		DrawBox(static_cast<int> (m_pos.x) + m_attackSizeLeft,
			static_cast<int> (m_pos.y) + m_attackSizeTop,
			static_cast<int> (m_pos.x) + m_attackSizeRight,
			static_cast<int> (m_pos.y) + m_attackSizeBottom,
			0xff0000, false);
	}
	
}

void PlayerBase::KnockBack()
{
	if (m_onDamageFrame > 0)
	{
		m_onDamageFrame--;
		damageMove();
	}
}

void PlayerBase::damageMove()
{
	m_pos += m_knockBack;

	m_knockBack.x = min(max(m_knockBack.x- kAccX, 0), m_knockBack.x + kAccX);
	m_knockBack.y += kAccY;
}
