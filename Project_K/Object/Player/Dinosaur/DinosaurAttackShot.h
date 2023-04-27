#pragma once
#include "DinosaurAttackBase.h"
class DinosaurAttackShot : public DinosaurAttackBase
{
public:
	DinosaurAttackShot();
	virtual ~DinosaurAttackShot();

	virtual DinosaurAttackBase* Update();
};

