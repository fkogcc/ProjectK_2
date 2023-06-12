#pragma once
#include "DinosaurStateBase.h"
class DinosaurIdle : public DinosaurStateBase
{
public:
	DinosaurIdle(Vec2 vec)
	{
		m_Vec = vec;
		m_attackFlag = false;
	}
	virtual ~DinosaurIdle();

	virtual DinosaurStateBase* Update(int padNum) override;
};

