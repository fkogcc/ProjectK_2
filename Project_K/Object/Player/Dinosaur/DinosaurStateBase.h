#pragma once
#include "../../../condition.h"
#include"../../Util/Vec2.h"
class DinosaurStateBase
{
public:
	virtual ~DinosaurStateBase(){};

	virtual void Init(int Handle);

	virtual DinosaurStateBase* Update() { return this; }

	virtual void Draw();

	virtual void SetPos(Vec2 pos) { m_Pos = pos; }

protected:
	int m_Handle;
	
	int m_posAttackLeft = 0;// プレイヤーの攻撃範囲
	int m_posAttackTop = 0;
	int m_posAttackRight = 0;
	int m_posAttackBottom = 0;

	int m_frameCount = 0;// アニメーションを再生させる用フレームカウント

	int m_imagePosX = 0;// 画像の描画位置
	int m_imagePosY = 0;

	int m_attackDamage = 0;// プレイヤーがエネミーに与えるダメージ量
	bool m_isMove = false;
	Vec2 m_Pos = { 0.0f,0.0f };// 現在位置
	Vec2 m_Vec = { 0.0f,0.0f };// 運動量
};

