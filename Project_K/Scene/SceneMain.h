#pragma once
#include "SceneBase.h"
#include "../Util/Vec2.h"

#include <fstream>
#include <string>
#include <vector>

class Stage;		// ステージ
class PlayerBase;
class Collision;
class UI;			// UI

class SceneMain : public SceneBase
{
public:
	SceneMain(PlayerBase* Player1, PlayerBase* Player2);
	virtual ~SceneMain();

	virtual void Init();
	virtual void End();

	virtual SceneBase* Update() override;
	virtual void Draw();
private:
	void UpdateCountDown(); //試合開始前のカウント
	void UpdateMain();//試合開始
	void UpdateDead();//片方が死んだら
private:
	Stage* m_pStage;
	PlayerBase* m_pPlayer[2];
	Collision* m_pColl;
	UI* m_pUi;

	bool m_isVictory1P;// 1Pの勝敗
	bool m_isVictory2P;// 2Pの勝敗

	void (SceneMain::*m_updateFunc)();

	int countDown; //カウントダウン

	int m_font = 0;// フォントハンドル
};


	