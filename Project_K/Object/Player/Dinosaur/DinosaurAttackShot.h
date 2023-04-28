#pragma once
#include "DinosaurStateBase.h"
class DinosaurAttackShot : public DinosaurStateBase
{
public:
	DinosaurAttackShot(Vec2 pos, Vec2 vec)
	{
		m_Pos = pos;
		m_Vec = vec;
	}
	virtual ~DinosaurAttackShot();

	virtual DinosaurStateBase* Update() override;
};

