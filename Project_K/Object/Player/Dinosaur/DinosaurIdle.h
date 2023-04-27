#pragma once
#include "DinosaurStateBase.h"
class DinosaurIdle : public DinosaurStateBase
{
public:
	DinosaurIdle(Vec2 pos, Vec2 vec)
	{
		m_Pos = pos;
		m_Vec = vec;
	}
	virtual ~DinosaurIdle();

	virtual DinosaurStateBase* Update() override;
};

