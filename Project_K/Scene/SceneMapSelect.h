#pragma once
#include "SceneBase.h"
#include "../Util/common.h"

class DinoStage;	// �����X�e�[�W
class ElfStage;		// �G���t�X�e�[�W
class MachoStage;	// �}�b�`���X�e�[�W
class WizardStage;	// �����X�e�[�W
class StageBase;	// �X�e�[�W

class SceneMapSelect : public SceneBase
{
public:
	SceneMapSelect();
	virtual ~SceneMapSelect();

	virtual void Init();
	virtual void End();

	virtual SceneBase* Update() override;
	virtual void Draw();

	// �I�����ꂽ�ԍ��ɂ���ă}�b�v��I��
	virtual void ChooseNum();

	void setWizStage(WizardStage* pWizStage) { m_pWizStage = pWizStage; }

	// �X�e�[�W���I�΂ꂽ���̏���
	//bool IsSelected() { return };

private:
	DinoStage* m_pDinoStage;	// �����X�e�[�W
	ElfStage* m_pElfStage;		// �G���t�X�e�[�W
	MachoStage* m_pMachoStage;	// �}�b�`���X�e�[�W
	WizardStage* m_pWizStage;	// �����X�e�[�W
	StageBase* m_pStageBase;	// �X�e�[�W�x�[�X

	// �}�b�v���ʗp�̔ԍ��ϐ�
	int m_mapNum;
};

