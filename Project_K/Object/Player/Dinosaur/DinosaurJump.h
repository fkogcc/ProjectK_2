#pragma once
#include "DinosaurStateBase.h"
class DinosaurJump : public DinosaurStateBase
{
public:
	DinosaurJump(Vec2 pos, Vec2 vec);
	
	virtual ~DinosaurJump();

	virtual DinosaurStateBase* Update() override;

private:
	float m_JumpPower;
};

