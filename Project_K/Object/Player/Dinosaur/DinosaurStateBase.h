#pragma once
#include "../../../condition.h"
#include"../../Util/Vec2.h"
#include "../../Util/Pad.h"

class DinosaurStateBase
{
public:
	virtual ~DinosaurStateBase() {};

	virtual void Init(int Handle);

	virtual DinosaurStateBase* Update(int padNum) { return this; }

	virtual void Draw(int handle, bool lookRight,Vec2 pos);

	virtual void ChangeGraph(int ChangeSpeed, int GraphNum, bool ChangeY);

	virtual Vec2 GetVec() { return m_vec; }

	virtual bool GetshotFlag() { return m_shotFlag; }

	virtual bool GetAttackFlag() { return m_attackFlag; }
	virtual bool SetAttackFlag(bool attackFlag) { return m_attackFlag = attackFlag; }

	virtual void SetDeadFlag() { m_deadFlag = true; }

	virtual void SetLookFlag(bool RightFlag) { m_lookLeft = RightFlag; }

	int GetAttackSizeLeft() { return m_attakSizeLeft; }

	int GetAttackSizeTop() { return m_attackSizeTop; }
	int GetAttackSizeRight() { return m_attackSizeRight; }
	int GetAttackSizeBottom() { return m_attackSizeBottom; }

	int GetAttackDamage() { return m_attackDamage; }

	bool GetAttackMotion() { return m_attackMotion; }

protected:
	int m_handle;

	bool m_shotFlag = false;
	bool m_lookLeft;	// 左を向いているか
	bool m_deadFlag = false; //死んでいるかどうか

	int m_attakSizeLeft = 0;
	int m_attackSizeTop = 0;
	int m_attackSizeRight = 0;
	int m_attackSizeBottom = 0;

	int m_frameCount = 0;// アニメーションを再生させる用フレームカウント

	int m_imagePosX = 0;// 画像の描画位置
	int m_imagePosY = 0;

	int m_gapTime = 0; // 後隙

	int m_attackFrame = 0;//攻撃フラグがtrueになるまでの時間

	int m_attackDamage = 0;// プレイヤーがエネミーに与えるダメージ量
	bool m_attackFlag = false; //攻撃判定があるとき
	bool m_isMove = false;
	Vec2 m_vec = { 0.0f,0.0f };// 運動量

	bool m_attackMotion = false; //攻撃モーションのとき
};

