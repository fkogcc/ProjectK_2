#pragma once
#include "../Base/MoveTypeBase.h"

class KinnikuMuscle : public MoveTypeBase
{
public:
	void Update(int& imagePosX, int& imagePosY);// �X�V

	bool IsAttackColMuscle() { return m_isAttackCol; }// �U������̃^�C�~���O

	// �U�����肪���邩�ǂ���
	bool m_isAttackCol = false;
private:

	int m_nextCount = 0;
};

