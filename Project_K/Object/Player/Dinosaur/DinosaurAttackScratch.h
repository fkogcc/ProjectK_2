#pragma once
#include "DinosaurStateBase.h"
class DinosaurAttackScratch : public DinosaurStateBase
{
public:
	DinosaurAttackScratch(Vec2 pos, Vec2 vec)
	{
		m_Pos = pos;
		m_Vec = vec;
	}
	virtual ~DinosaurAttackScratch();

	virtual DinosaurStateBase* Update() override;
};

