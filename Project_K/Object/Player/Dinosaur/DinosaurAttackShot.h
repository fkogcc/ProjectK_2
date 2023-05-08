#pragma once
#include "DinosaurStateBase.h"
class DinosaurAttackShot : public DinosaurStateBase
{
public:
	DinosaurAttackShot(Vec2 pos, Vec2 vec) : 
		m_pastShotFlag(false)
	{
		m_Pos = pos;
		m_Vec = vec;
		m_imagePosX = 0;
		m_imagePosY = 2;
	}
	virtual ~DinosaurAttackShot();

	virtual DinosaurStateBase* Update() override;

private:
	bool m_pastShotFlag;
};

