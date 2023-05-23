#pragma once
#include "../Base/MoveTypeBase.h"

class KinnikuMizo : public MoveTypeBase
{
public:
	void Update(int& imagePosX, int& imagePosY);// çXêV

	bool IsAttackColMizo() { return m_isAttackCol; }

private:
	bool m_isAttackCol = false;
};

