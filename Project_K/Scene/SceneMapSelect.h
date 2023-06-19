#pragma once
#include "SceneBase.h"
#include "../Util/common.h"

class DinoStage;	// 恐竜ステージ
class ElfStage;		// エルフステージ
class MachoStage;	// マッチョステージ
class WizardStage;	// 魔女ステージ
class StageBase;	// ステージ

class SceneMapSelect : public SceneBase
{
public:
	SceneMapSelect();
	virtual ~SceneMapSelect();

	virtual void Init();
	virtual void End();

	virtual SceneBase* Update() override;
	virtual void Draw();

	// 選択された番号によってマップを選ぶ
	virtual void ChooseNum();

	void setWizStage(WizardStage* pWizStage) { m_pWizStage = pWizStage; }

	// ステージが選ばれた時の処理
	//bool IsSelected() { return };

private:
	DinoStage* m_pDinoStage;	// 恐竜ステージ
	ElfStage* m_pElfStage;		// エルフステージ
	MachoStage* m_pMachoStage;	// マッチョステージ
	WizardStage* m_pWizStage;	// 魔女ステージ
	StageBase* m_pStageBase;	// ステージベース

	// マップ判別用の番号変数
	int m_mapNum;
};

