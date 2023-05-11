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
