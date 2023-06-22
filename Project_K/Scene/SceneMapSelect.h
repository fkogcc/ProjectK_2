#pragma once
#include "SceneBase.h"
#include "../Util/common.h"
#include "../Util/Vec2.h"

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

private:
	Vec2 m_pos;

	//**** UI�p�O���t�B�b�N�n���h�� ****//
	int m_stageHandle;	// 
	int m_bgHandle;		// �w�i
	int m_handle;
	int m_font;			// �t�H���g�n���h��

	// �}�b�v���ʗp�̔ԍ��ϐ�
	int m_mapNum;
};

