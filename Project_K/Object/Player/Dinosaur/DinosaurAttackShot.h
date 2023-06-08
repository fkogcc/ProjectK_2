#pragma once
#include "DinosaurStateBase.h"
class DinosaurAttackShot : public DinosaurStateBase
{
public:
	DinosaurAttackShot(Vec2 pos, Vec2 vec) : 
		m_pastShotFlag(false)
	{
		m_Pos = pos;
		m_Vec = vec;
		m_imagePosX = 0;
		m_imagePosY = 2;

		// 攻撃中のキャラクターの向きの制御のためにショットだけどtrueに
		m_attackFlag = true;

		// ショットの処理だから攻撃の当たり判定は実際はないため
		// 絶対に当たらない値にした
		m_attakSizeLeft = 0;
		m_attackSizeTop = 0;
		m_attackSizeRight = 0;
		m_attackSizeBottom = 0;
	}
	virtual ~DinosaurAttackShot();

	virtual DinosaurStateBase* Update(int padNum) override;

private:
	bool m_pastShotFlag;
};

