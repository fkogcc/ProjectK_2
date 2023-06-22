#pragma once

#include "ShotBase.h"

class ElfShot : public ShotBase
{
public:
	ElfShot(Vec2 Pos, Vec2 Vec)
	{
		m_Shot.Pos = Pos;
		m_Shot.Vec = Vec;

		m_Shot.shotSizeLeft   = -20;
		m_Shot.shotSizeTop    = -20;
		m_Shot.shotSizeRight  =  60;
		m_Shot.shotSizeBottom =  20;

		m_Exist = true;
		m_NullShot = false;
	}
	virtual ~ElfShot();

	virtual void Update() override;
};
