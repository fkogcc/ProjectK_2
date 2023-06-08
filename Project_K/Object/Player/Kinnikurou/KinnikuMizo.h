#pragma once
#include "../Base/MoveTypeBase.h"

class KinnikuMizo : public MoveTypeBase
{
public:
	void Update(int& imagePosX, int& imagePosY);// 更新

	bool IsAttackColMizo() { return m_isAttackCol; }

	bool m_isAttackCol = false;
private:

	// 次のモーションに入るフレーム
	int m_nextCount = 0;
};

