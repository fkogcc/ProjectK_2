#pragma once
#include "DinosaurStateBase.h"
class DinosaurAttackScratch : public DinosaurStateBase
{
public:
	DinosaurAttackScratch(Vec2 pos, Vec2 vec)
	{
		m_Pos = pos;
		m_Vec = vec;
		m_imagePosX = 4;
		m_imagePosY = 8;
		m_attackFlag = true;

		m_attakSizeLeft = -100;
		m_attackSizeTop = 30;
		m_attackSizeRight = 0;
		m_attackSizeBottom = 100;

		m_attackDamage = 10;
	}
	virtual ~DinosaurAttackScratch();

	virtual DinosaurStateBase* Update(int padNum) override;
};

