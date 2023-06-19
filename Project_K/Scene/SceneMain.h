#pragma once
#include "SceneBase.h"
#include "../Util/Vec2.h"

#include <fstream>
#include <string>
#include <vector>
#include <memory>

class StageBase;		// ステージ
class SceneBase;
class PlayerBase;
class Collision;
class UI;			// UI

class SceneMain : public SceneBase
{
public:
	SceneMain(PlayerBase* Player1, PlayerBase* Player2, int StageNo);
	virtual ~SceneMain();

	virtual void Init();
	virtual void End();

	virtual SceneBase* Update() override;
	virtual void Draw();

private:
	StageBase* m_pStageBase;	// ステージセレクトシーン
	PlayerBase* m_pPlayer[2];
	Collision* m_pColl;
	UI* m_pUi;

	bool m_isVictory1P;// 1Pの勝敗
	bool m_isVictory2P;// 2Pの勝敗
};


	