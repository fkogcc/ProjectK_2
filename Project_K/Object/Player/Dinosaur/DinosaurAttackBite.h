#pragma once
#include "DinosaurStateBase.h"
class DinosaurAttackBite : public DinosaurStateBase
{
public:
	DinosaurAttackBite(Vec2 vec)
	{
		m_vec = vec;
		m_imagePosX = 0;
		m_imagePosY = 5;
		m_attackFlag = true;

		m_attakSizeLeft = -130;

		m_attackSizeTop = 0;
		m_attackSizeRight = 0;
		m_attackSizeBottom = 80;

		m_attackDamage = 10;
	}
	virtual ~DinosaurAttackBite();

	virtual DinosaurStateBase* Update(int padNum) override;
};

