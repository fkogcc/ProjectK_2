#pragma once
#include "DinosaurStateBase.h"
class DinosaurAttackPounce : public DinosaurStateBase
{
public:
	DinosaurAttackPounce(Vec2 pos, Vec2 vec)
	{
		m_Pos = pos;
		m_Vec = vec;
	}
	virtual ~DinosaurAttackPounce();

	virtual DinosaurStateBase* Update() override;
};

