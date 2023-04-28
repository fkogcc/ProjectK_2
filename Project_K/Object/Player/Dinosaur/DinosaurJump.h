#pragma once
#include "DinosaurStateBase.h"
class DinosaurJump : public DinosaurStateBase
{
public:
	DinosaurJump(Vec2 pos, Vec2 vec)
	{
		m_Pos = pos;
		m_Vec = vec;
	}
	virtual ~DinosaurJump();

	virtual DinosaurStateBase* Update() override;
};

