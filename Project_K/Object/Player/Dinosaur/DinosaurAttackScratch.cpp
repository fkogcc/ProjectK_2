#include "DinosaurAttackScratch.h"
#include "DinosaurIdle.h"

DinosaurAttackScratch::~DinosaurAttackScratch()
{
}

DinosaurStateBase* DinosaurAttackScratch::Update(int padNum)
{
	if (m_imagePosX < 7)
	{
		ChangeGraph(4, 10, false);
	}
	else
	{
		m_imagePosX = 7;
		m_gapTime++;
	}

	if (m_gapTime > 5)
	{
		return new DinosaurIdle(m_Vec);
	}
	return this;
}
