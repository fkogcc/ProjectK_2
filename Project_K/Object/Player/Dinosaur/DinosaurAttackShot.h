#pragma once
#include "DinosaurStateBase.h"
class DinosaurAttackShot : public DinosaurStateBase
{
public:
	DinosaurAttackShot(Vec2 vec) : 
		m_pastShotFlag(false)
	{
		m_Vec = vec;
		m_imagePosX = 0;
		m_imagePosY = 2;

		// �U�����̃L�����N�^�[�̌����̐���̂��߂ɃV���b�g������true��
		m_attackFlag = true;

		// �V���b�g�̏���������U���̓����蔻��͎��ۂ͂Ȃ�����
		// ��΂ɓ�����Ȃ��l�ɂ���
		m_attakSizeLeft = -10000;
		m_attackSizeTop = -10000;
		m_attackSizeRight = -10000;
		m_attackSizeBottom = -10000;
	}
	virtual ~DinosaurAttackShot();

	virtual DinosaurStateBase* Update(int padNum) override;

private:
	bool m_pastShotFlag;
};

