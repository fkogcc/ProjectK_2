#include "DinosaurAttackBite.h"
#include"DinosaurIdle.h"

DinosaurAttackBite::~DinosaurAttackBite()
{
}

DinosaurStateBase* DinosaurAttackBite::Update(int padNum)
{
	if (m_imagePosX < 4)
	{
		ChangeGraph(4, 10, false);
	}
	else
	{
		m_imagePosX = 4;
		m_gapTime++;
	}

	if (m_gapTime > 4)
	{
		return new DinosaurIdle(m_Pos, m_Vec);
	}


	return this;
}
