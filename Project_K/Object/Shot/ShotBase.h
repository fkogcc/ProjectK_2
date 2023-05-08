#pragma once
#include"../../Util/Vec2.h"
class ShotBase
{
public:
	ShotBase() {};

	virtual ~ShotBase();

	virtual void Update() {};
	virtual void Draw();

	virtual bool IsExist();

protected:
	struct Data
	{
		Vec2 Pos;
		Vec2 Vec;

	};

	Data m_Shot;
};

