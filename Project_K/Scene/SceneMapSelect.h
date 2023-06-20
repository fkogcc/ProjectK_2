#pragma once
#include "SceneBase.h"
#include "../Util/common.h"

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
	// �}�b�v���ʗp�̔ԍ��ϐ�
	int m_mapNum;
};

