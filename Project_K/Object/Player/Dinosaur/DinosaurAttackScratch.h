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
		m_sizeAttackLeft = -100;
		m_attackSizeTop = 0;
		m_attackSizeRight = 100;
		m_attackSizeBottom = 100;
	}
	virtual ~DinosaurAttackScratch();

	virtual DinosaurStateBase* Update() override;
};

