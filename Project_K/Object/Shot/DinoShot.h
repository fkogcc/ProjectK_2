#pragma once
#include "ShotBase.h"
class DinoShot : public ShotBase
{
public:
	DinoShot(Vec2 Pos, Vec2 Vec)
	{
		m_Shot.Pos = Pos;
		m_Shot.Vec = Vec;

		m_Shot.shotSizeLeft = -50;
		m_Shot.shotSizeTop = -50;
		m_Shot.shotSizeRight = 50;
		m_Shot.shotSizeBottom = 50;

		m_Exist = true;
		m_NullShot = false;
	}
	virtual ~DinoShot();

	virtual void Update() override;
};

