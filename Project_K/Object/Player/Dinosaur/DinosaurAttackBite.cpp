#include "DinosaurAttackBite.h"
#include"DinosaurIdle.h"

DinosaurAttackBite::~DinosaurAttackBite()
{
}

DinosaurStateBase* DinosaurAttackBite::Update(int padNum)
{
	if (m_imagePosX < 9)
	{
		ChangeGraph(4, 10, false);
	}
	else
	{
		m_imagePosX = 9;
		m_gapTime++;
	}

	if (m_gapTime > 10)
	{
		return new DinosaurIdle(m_Pos, m_Vec);
	}


	return this;
}
