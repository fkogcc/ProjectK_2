#pragma once
#include "../Base/MoveTypeBase.h"
class WitchLongShotAttack :
    public MoveTypeBase
{
public:
	WitchLongShotAttack();
	virtual ~WitchLongShotAttack() {}

	void Init();

	int IndexX() { return m_animeWidth; }
	int IndexY() { return m_animeHight; }
	int SizeX() { return m_indexX; }
	int ShiftX() { return m_shiftX; }
	int AnimeMax() { return m_animeMax; }
private:
	int m_animeHight;
	int m_animeWidth;
	int m_indexX;
	int m_shiftX;
	int m_animeMax;
};

