#pragma once
#include "../Base/MoveTypeBase.h"

class KinnikuUpper : public MoveTypeBase
{
public:
	void Update(int& imagePosX, int& imagePosY);// �X�V

	bool IsAttackColUpper() { return m_isAttackCol; }// �U������̃^�C�~���O

	bool m_isAttackCol = false;
private:
};

