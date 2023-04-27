#pragma once
class DinosaurAttackBase
{
public:
	DinosaurAttackBase() {}
	virtual ~DinosaurAttackBase() = 0;

	virtual DinosaurAttackBase* Update() { return this; }
};

