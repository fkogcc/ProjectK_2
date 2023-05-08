#pragma once
#include "ShotBase.h"
class Shot : public ShotBase
{
public:
	Shot(Vec2 Pos, Vec2 Vec)
	{
		m_Shot.Pos = Pos;
		m_Shot.Vec = Vec;
	}
	virtual ~Shot();

	virtual void Update() override;
};

