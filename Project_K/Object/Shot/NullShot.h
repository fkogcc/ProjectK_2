#pragma once
#include "ShotBase.h"

// �V���b�g���o�Ă��Ȃ�
class NullShot : public ShotBase
{
public:
	NullShot()
	{
		m_Exist = false;
		m_NullShot = true;
	}

	virtual ~NullShot() {};

	virtual void Update() {};

	virtual void Draw() {};
};

