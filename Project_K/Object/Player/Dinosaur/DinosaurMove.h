#pragma once
#include "DinosaurStateBase.h"
class DinosaurMove : public DinosaurStateBase
{
public:
	DinosaurMove(Vec2 pos, Vec2 vec)
	{
		m_Pos = pos;
		m_Vec = vec;
		m_imagePosY = 7;
		m_attackFlag = false;
	}
	virtual ~DinosaurMove();

	void IsMove(int padNum);

	virtual DinosaurStateBase* Update(int padNum) override;
};

