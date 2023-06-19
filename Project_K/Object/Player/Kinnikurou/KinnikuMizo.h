#pragma once
#include "../Base/MoveTypeBase.h"

class KinnikuMizo : public MoveTypeBase
{
public:
	void Update(int& imagePosX, int& imagePosY);// 更新

	bool IsAttackColMizo() { return m_isAttackCol; }// 攻撃判定のタイミング

	bool m_isAttackCol = false;
private:

	int m_nextCount = 0;
};

