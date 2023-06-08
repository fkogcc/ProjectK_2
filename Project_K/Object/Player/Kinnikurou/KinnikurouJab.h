#pragma once
#include "../Base/MoveTypeBase.h"

class KinnikurouJab : public MoveTypeBase
{
public:
	void Update(int& imagePosX, int& imagePosY);// çXêV

	bool IsAttackColJab() { return m_isAttackCol; }

	bool m_isAttackCol = false;
private:
};

