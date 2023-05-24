#pragma once
#include "../Base/MoveTypeBase.h"

class KinnikuMuscle : public MoveTypeBase
{
public:
	void Update(int& imagePosX, int& imagePosY);// çXêV

	bool IsAttackColMuscle() { return m_isAttackCol; }

private:
	bool m_isAttackCol = false;

	int m_nextCount = 0;
};

