#pragma once
#include "DinosaurStateBase.h"
class DinosaurAttackPounce : public DinosaurStateBase
{
public:
	DinosaurAttackPounce(Vec2 pos, Vec2 vec);
	
	virtual ~DinosaurAttackPounce();

	virtual DinosaurStateBase* Update() override;

private:
	float m_JumpPower;
};

