#pragma once
#include <memory>

class StageBase;	// �X�e�[�W�x�[�X

class StageManager
{
public:
	void Init();	// ������
	void Update();	// �X�V
	void Draw();	// �`��

private:
	std::shared_ptr<StageBase> m_pStage;	// �X�e�[�W�x�[�X�̃|�C���^�ϐ�
};

