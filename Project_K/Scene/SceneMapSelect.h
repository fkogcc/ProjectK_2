#pragma once
#include "SceneBase.h"
#include "../Util/common.h"
#include "../Util/Vec2.h"

class SceneMapSelect : public SceneBase
{
public:
	SceneMapSelect();			// �R���X�g���N�^
	virtual ~SceneMapSelect();	// �f�X�g���N�^

	virtual void Init();		// ������
	virtual void End();
	
	virtual SceneBase* Update() override;	// �X�V
	virtual void Draw();		// �`��

	// �I�����ꂽ�ԍ��ɂ���ă}�b�v��I��
	virtual void ChooseNum();

	// �X�e�[�W���I�΂ꂽ���̏���
	//bool IsSelected() { return };

private:
	Vec2 m_pos;	// ���W	

	//**** UI�p�O���t�B�b�N�n���h�� ****//
	int m_stageHandle;	// �e�X�e�[�W�k���\���̃n���h��
	int m_handle[5];	// �e�X�e�[�W�̃n���h��
	int m_bgHandle;		// �w�i
	int m_font;			// �t�H���g�n���h��

	// �}�b�v���ʗp�̔ԍ��ϐ�
	int m_mapNum;

	// �}�b�v�̏��
	enum StageState
	{
		RandStage = 1,	// �����_���X�e�[�W
		DinoStage,		// �����X�e�[�W
		ElfStage,		// �G���t�X�e�[�W
		MachoStage,		// �}�b�`���X�e�[�W
		WizardStage,	// �����X�e�[�W
	};
};

