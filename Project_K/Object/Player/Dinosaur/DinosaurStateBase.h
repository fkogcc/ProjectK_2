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

	virtual bool GetAttackFlag() { return m_attackFlag; }

	int GetAttackSizeLeft() { return m_attackSizeLeft; }
	int GetAttackSizeTop() { return m_attackSizeTop; }
	int GetAttackSizeRight() { return m_attackSizeRight; }
	int GetAttackSizeBottom() { return m_attackSizeBottom; }

protected:
	int m_Handle;

	bool m_shotFlag = false;
	
	int m_attackSizeLeft = 0;
	int m_attackSizeTop = 0;
	int m_attackSizeRight = 0;
	int m_attackSizeBottom = 0;

	int m_frameCount = 0;// �A�j���[�V�������Đ�������p�t���[���J�E���g

	int m_imagePosX = 0;// �摜�̕`��ʒu
	int m_imagePosY = 0;

	int m_gapTime = 0; // �㌄

	int m_attackDamage = 0;// �v���C���[���G�l�~�[�ɗ^����_���[�W��
	bool m_attackFlag = false;
	bool m_isMove = false;
	Vec2 m_Pos = { 0.0f,0.0f };// ���݈ʒu
	Vec2 m_Vec = { 0.0f,0.0f };// �^����
};

