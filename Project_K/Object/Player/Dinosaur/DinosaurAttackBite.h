#pragma once
#include "DinosaurStateBase.h"
class DinosaurAttackBite : public DinosaurStateBase
{
public:
	DinosaurAttackBite(Vec2 pos, Vec2 vec)
	{
		m_Pos = pos;
		m_Vec = vec;
		m_imagePosX = 0;
		m_imagePosY = 5;
		m_attackFlag = true;
		m_sizeAttackLeft = -100;
		m_attackSizeTop = 0;
		m_attackSizeRight = 100;
		m_attackSizeBottom = 100;
	}
	virtual ~DinosaurAttackBite();

	virtual DinosaurStateBase* Update() override;
};

