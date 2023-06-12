#pragma once
#include "DinosaurStateBase.h"
class DinosaurAttackShot : public DinosaurStateBase
{
public:
	DinosaurAttackShot(Vec2 vec) : 
		m_pastShotFlag(false)
	{
		m_Vec = vec;
		m_imagePosX = 0;
		m_imagePosY = 2;

		// 攻撃中のキャラクターの向きの制御のためにショットだけどtrueに
		m_attackFlag = true;

		// ショットの処理だから攻撃の当たり判定は実際はないため
		// 絶対に当たらない値にした
		m_attakSizeLeft = -10000;
		m_attackSizeTop = -10000;
		m_attackSizeRight = -10000;
		m_attackSizeBottom = -10000;
	}
	virtual ~DinosaurAttackShot();

	virtual DinosaurStateBase* Update(int padNum) override;

private:
	bool m_pastShotFlag;
};

