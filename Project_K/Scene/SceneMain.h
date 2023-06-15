#pragma once
#include "SceneBase.h"
#include "../Util/Vec2.h"

#include <fstream>
#include <string>
#include <vector>
#include <memory>

class Stage;		// ステージ
class SceneMapSelect;	// ステージセレクトシーン
class DinoStage;	// 恐竜ステージ
class ElfStage;		// エルフステージ
class MachoStage;	// マッチョステージ
class WizardStage;	// 魔女ステージ
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
	Stage*		m_pStage;
	std::shared_ptr<SceneMapSelect> m_pSceneMapSelect;	// ステージセレクトシーン
	std::shared_ptr<DinoStage> m_pDinoStage;	// 恐竜ステージ
	std::shared_ptr<ElfStage> m_pElfStage;		// エルフステージ
	std::shared_ptr<MachoStage> m_pMachoStage;	// マッチョステージ
	std::shared_ptr<WizardStage> m_pWizStage;	// 魔女ステージ
	PlayerBase* m_pPlayer[2];
	Collision* m_pColl;
	UI* m_pUi;

	bool m_isVictory1P;// 1Pの勝敗
	bool m_isVictory2P;// 2Pの勝敗
};


	