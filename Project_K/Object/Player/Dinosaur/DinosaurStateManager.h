#pragma once
#include <DxLib.h>
#include"DinosaurStateBase.h"
#include"../../Util/Vec2.h"
#include "../../Util/Pad.h"

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
	void Update(int padNum);
	// �`��
	void Draw();

	bool GetshotFlag(); // �V���b�g�����Ƃ�

	Vec2 GetPos();

	bool GetAttackFlag();

	int GetAttackSizeLeft();
	int GetAttackSizeTop();
	int GetAttackSizeRight();
	int GetAttackSizeBottom();

	bool GetLookLeft() { return m_lookLeft; }

	int GetOnDamage();

	void SetAttackFlag();

	//���񂾂Ƃ�m_deadFlag��true��
	void SetDeadFlag() { m_deadFlag = true; }

private:
	int m_Handle;

	bool m_lookLeft; // ���������Ă��邩�ǂ���

	bool m_deadFlag = false; //����ł��邩�ǂ���

	// �V�[���x�[�X�|�C���^
	DinosaurStateBase* m_pState;
};

