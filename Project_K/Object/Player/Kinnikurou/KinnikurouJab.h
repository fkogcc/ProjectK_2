#pragma once
#include "../Base/MoveTypeBase.h"

class KinnikurouJab : public MoveTypeBase
{
public:
	void Update(int& imagePosX, int& imagePosY);// �X�V

	bool IsAttackColJab() { return m_isAttackCol; }

private:
	bool m_isAttackCol = false;
};

