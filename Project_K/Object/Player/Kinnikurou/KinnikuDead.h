#pragma once
#include "../Base/MoveTypeBase.h"

class KinnikuDead : public MoveTypeBase
{
public:
	void Update(int& imagePosX, int& imagePosY);// �X�V
private:
	int m_nextCount = 5;// ���̃��[�V�����Ɉڍs���鎞��
};

