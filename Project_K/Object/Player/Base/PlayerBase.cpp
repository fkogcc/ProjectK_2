#include "PlayerBase.h"
#include "../../Shot/NullShot.h"

PlayerBase::PlayerBase()
{
	{
		for (int i = 0; i < kShotMax; i++)
		{
			m_Shot[i] = new NullShot();
		}
	};
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

void PlayerBase::attackCountUp()
{
	m_attackFrameCount++;
}
