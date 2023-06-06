#pragma once
#include <DxLib.h>
#include"DinosaurStateBase.h"
#include"../../Util/Vec2.h"
#include "../../Util/Pad.h"

class DinosaurStateManager
{
public:
	DinosaurStateManager(int Handle);
	virtual ~DinosaurStateManager() {}
	// 初期化
	void Init();
	// 終了
	void End();
	// 毎フレームの処理
	void Update(int padNum);
	// 描画
	void Draw();

	bool GetshotFlag(); // ショットを撃つとき

	Vec2 GetPos();

	bool GetAttackFlag();

	int GetAttackSizeLeft();
	int GetAttackSizeTop();
	int GetAttackSizeRight();
	int GetAttackSizeBottom();

	bool GetLookLeft() { return m_lookLeft; }

	int GetOnDamage();

	void SetAttackFlag();

	//死んだときm_deadFlagをtrueに
	void SetDeadFlag() { m_deadFlag = true; }

private:
	int m_Handle;

	bool m_lookLeft; // 左を向いているかどうか

	bool m_deadFlag = false; //死んでいるかどうか

	// シーンベースポインタ
	DinosaurStateBase* m_pState;
};

