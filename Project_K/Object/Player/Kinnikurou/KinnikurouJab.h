#pragma once
#include "../Base/MoveTypeBase.h"

class KinnikurouJab : public MoveTypeBase
{
public:
	void Update(int& imagePosX, int& imagePosY);// �X�V

	bool IsAttackColJab() { return m_isAttackCol; }// �U������̃^�C�~���O

	bool m_isAttackCol = false;
private:
};

