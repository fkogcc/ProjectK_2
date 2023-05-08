#pragma once

#include"DinosaurStateBase.h"
#include"../../Util/Vec2.h"

class DinosaurStateManager
{
public:
	DinosaurStateManager(int Handle);
	virtual ~DinosaurStateManager() {}
	// ������
	void Init();
	// �I��
	void End();
	// ���t���[���̏���
	void Update();
	// �`��
	void Draw();

	bool GetshotFlag(); // �V���b�g�����Ƃ�

	Vec2 GetPos();

private:
	int m_Handle;

	// �V�[���x�[�X�|�C���^
	DinosaurStateBase* m_pState;
};

