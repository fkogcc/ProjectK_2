#pragma once
#include "../Base/MoveTypeBase.h"

class KinnikuMizo : public MoveTypeBase
{
public:
	void Update(int& imagePosX, int& imagePosY, int& framecount);// �X�V

	bool IsAttackColMizo() { return m_isAttackCol; }// �U������̃^�C�~���O

	bool m_isAttackCol = false;
private:

	int m_nextCount = 0;

	bool m_isFlag = false;
};

