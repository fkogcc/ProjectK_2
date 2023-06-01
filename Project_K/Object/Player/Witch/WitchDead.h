#pragma once
#include "../Base/MoveTypeBase.h"
class WitchDead :
	public MoveTypeBase
{
public:
	WitchDead();
	virtual ~WitchDead() {}

	void Init();

	int IndexX() { return m_animeWidth; }
	int IndexY() { return m_animeHight; }
	int AnimeMax() { return m_animeMax; }
private:
	int m_animeWidth;
	int m_animeHight;
	int m_animeMax;
};