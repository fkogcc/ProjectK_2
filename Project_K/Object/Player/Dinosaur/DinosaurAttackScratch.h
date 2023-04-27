#pragma once
#include "DinosaurAttackBase.h"
class DinosaurAttackScratch : public DinosaurAttackBase
{
public:

	DinosaurAttackScratch();
	virtual ~DinosaurAttackScratch();

	virtual DinosaurAttackBase* Update();
};

