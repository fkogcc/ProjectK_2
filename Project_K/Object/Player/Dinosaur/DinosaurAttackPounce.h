#pragma once
#include "DinosaurAttackBase.h"
class DinosaurAttackPounce : public DinosaurAttackBase
{
public:
	DinosaurAttackPounce();
	virtual ~DinosaurAttackPounce();

	virtual DinosaurAttackBase* Update();
};

