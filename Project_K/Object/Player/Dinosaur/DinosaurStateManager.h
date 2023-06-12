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
	void Draw(Vec2 pos);

	bool GetshotFlag(); // �V���b�g�����Ƃ�

	Vec2 GetVec();

	bool GetAttackFlag();

	int GetAttackSizeLeft();
	int GetAttackSizeTop();
	int GetAttackSizeRight();
	int GetAttackSizeBottom();

	bool GetLookLeft() { return m_lookLeft; }

	int GetOnDamage();

	void SetAttackFlag();

	void SetondamageFlag(bool ondamageFlag) { m_ondamageFlag = ondamageFlag; }

	//���񂾂Ƃ�m_deadFlag��true��
	void SetDeadFlag() { m_deadFlag = true; }

private:
	int m_Handle;

	bool m_lookLeft; // ���������Ă��邩�ǂ���

	bool m_deadFlag = false; //����ł��邩�ǂ���

	bool m_ondamageFlag = false; //�U����H����Ă���Ƃ�

	// �V�[���x�[�X�|�C���^
	DinosaurStateBase* m_pState;
};

