#pragma once
#include "../Base/MoveTypeBase.h"

class KinnikuUpper : public MoveTypeBase
{
public:
	void Update(int& imagePosX, int& imagePosY);// çXêV

	bool IsAttackColUpper() { return m_isAttackCol; }

private:
	bool m_isAttackCol = false;
};

