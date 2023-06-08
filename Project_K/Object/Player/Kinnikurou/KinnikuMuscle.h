#pragma once
#include "../Base/MoveTypeBase.h"

class KinnikuMuscle : public MoveTypeBase
{
public:
	void Update(int& imagePosX, int& imagePosY);// çXêV

	bool IsAttackColMuscle() { return m_isAttackCol; }

	bool m_isAttackCol = false;
private:

	int m_nextCount = 0;
};

