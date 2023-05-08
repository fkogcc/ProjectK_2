#pragma once

#include"DinosaurStateBase.h"
#include"../../Util/Vec2.h"

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
	void Update();
	// 描画
	void Draw();

	bool GetshotFlag(); // ショットを撃つとき

	Vec2 GetPos();

private:
	int m_Handle;

	// シーンベースポインタ
	DinosaurStateBase* m_pState;
};

