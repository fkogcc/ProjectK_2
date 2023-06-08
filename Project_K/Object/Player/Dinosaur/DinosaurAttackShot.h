#pragma once
#include "DinosaurStateBase.h"
class DinosaurAttackShot : public DinosaurStateBase
{
public:
	DinosaurAttackShot(Vec2 pos, Vec2 vec) : 
		m_pastShotFlag(false)
	{
		m_Pos = pos;
		m_Vec = vec;
		m_imagePosX = 0;
		m_imagePosY = 2;

		// �U�����̃L�����N�^�[�̌����̐���̂��߂ɃV���b�g������true��
		m_attackFlag = true;

		// �V���b�g�̏���������U���̓����蔻��͎��ۂ͂Ȃ�����
		// ��΂ɓ�����Ȃ��l�ɂ���
		m_attakSizeLeft = 0;
		m_attackSizeTop = 0;
		m_attackSizeRight = 0;
		m_attackSizeBottom = 0;
	}
	virtual ~DinosaurAttackShot();

	virtual DinosaurStateBase* Update(int padNum) override;

private:
	bool m_pastShotFlag;
};

