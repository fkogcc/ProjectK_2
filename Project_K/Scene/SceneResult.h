#pragma once
#include "SceneBase.h"
#include "../Util/common.h"

class PlayerBase;

class SceneResult : public SceneBase
{
public:
	/// <summary>
	/// 勝敗フラグ付きコンストラクタ
	/// </summary>
	/// <param name="isVictoryOrDefeat"></param>
	SceneResult(bool isVictory1P, bool isVictory2P, PlayerBase* player1P, PlayerBase* player2P);
	virtual ~SceneResult();

	virtual void Init();
	virtual void End();

	virtual SceneBase* Update() override;
	virtual void Draw();

private:
	// ポインタ
	PlayerBase* m_pPlayer[2];// プレイヤーベース

	bool m_isTitle;// タイトルへ
	bool m_isRetry;// リトライ

	bool m_isNone = false;// 条件の中身がない状態

	bool m_isVictory1P;// 1Pの勝敗
	bool m_isVictory2P;// 2Pの勝敗
};

