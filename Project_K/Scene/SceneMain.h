#pragma once
#include "SceneBase.h"
#include "../Util/Vec2.h"

#include <fstream>
#include <string>
#include <vector>
#include <memory>

class Stage;		// �X�e�[�W
class SceneMapSelect;	// �X�e�[�W�Z���N�g�V�[��
class DinoStage;	// �����X�e�[�W
class ElfStage;		// �G���t�X�e�[�W
class MachoStage;	// �}�b�`���X�e�[�W
class WizardStage;	// �����X�e�[�W
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
	std::shared_ptr<SceneMapSelect> m_pSceneMapSelect;	// �X�e�[�W�Z���N�g�V�[��
	std::shared_ptr<DinoStage> m_pDinoStage;	// �����X�e�[�W
	std::shared_ptr<ElfStage> m_pElfStage;		// �G���t�X�e�[�W
	std::shared_ptr<MachoStage> m_pMachoStage;	// �}�b�`���X�e�[�W
	std::shared_ptr<WizardStage> m_pWizStage;	// �����X�e�[�W
	PlayerBase* m_pPlayer[2];
	Collision* m_pColl;
	UI* m_pUi;

	bool m_isVictory1P;// 1P�̏��s
	bool m_isVictory2P;// 2P�̏��s
};


	