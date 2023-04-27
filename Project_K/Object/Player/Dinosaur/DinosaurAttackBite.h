#pragma once
#include "DinosaurAttackBase.h"
class DinosaurAttackBite : public DinosaurAttackBase
{
public:
	DinosaurAttackBite();
	virtual ~DinosaurAttackBite();

	virtual DinosaurAttackBase* Update();
};

