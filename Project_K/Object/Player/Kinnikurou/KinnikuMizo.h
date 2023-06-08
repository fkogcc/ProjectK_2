#pragma once
#include "../Base/MoveTypeBase.h"

class KinnikuMizo : public MoveTypeBase
{
public:
	void Update(int& imagePosX, int& imagePosY);// çXêV

	bool IsAttackColMizo() { return m_isAttackCol; }

	bool m_isAttackCol = false;
private:

	int m_nextCount = 0;
};

