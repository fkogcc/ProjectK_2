#include "WitchLongShotAttack.h"

WitchLongShotAttack::WitchLongShotAttack() :
	m_animeWidth(0),
	m_animeHight(0),
	m_indexX(0),
	m_shiftX(0),
	m_animeMax(0)
{
}

void WitchLongShotAttack::Init()
{
	m_indexX = 3;
	m_shiftX = 100;
	m_animeWidth = 6;
	m_animeHight = 0;
	m_animeMax = 9;
}
