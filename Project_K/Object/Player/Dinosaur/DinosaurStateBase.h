#pragma once
#include "../../../condition.h"
#include"../../Util/Vec2.h"
#include "../../Util/Pad.h"

class DinosaurStateBase
{
public:
	virtual ~DinosaurStateBase(){};

	virtual void Init(int Handle);

	virtual DinosaurStateBase* Update() { return this; }

	virtual void Draw(int handle);

	virtual void ChangeGraph(int ChangeSpeed, int GraphNum , bool ChangeY);

	virtual void SetPos(Vec2 pos) { m_Pos = pos; }
	virtual Vec2 GetPos() { return m_Pos; }

	virtual bool GetshotFlag() { return m_shotFlag; }

protected:
	int m_Handle;

	bool m_shotFlag = false;
	
	int m_posAttackLeft = 0;// �v���C���[�̍U���͈�
	int m_posAttackTop = 0;
	int m_posAttackRight = 0;
	int m_posAttackBottom = 0;

	int m_frameCount = 0;// �A�j���[�V�������Đ�������p�t���[���J�E���g

	int m_imagePosX = 0;// �摜�̕`��ʒu
	int m_imagePosY = 0;

	int m_gapTime = 0; // �㌄

	int m_attackDamage = 0;// �v���C���[���G�l�~�[�ɗ^����_���[�W��
	bool m_isMove = false;
	Vec2 m_Pos = { 0.0f,0.0f };// ���݈ʒu
	Vec2 m_Vec = { 0.0f,0.0f };// �^����
};

