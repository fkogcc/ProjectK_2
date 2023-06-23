#pragma once
#include "DinosaurStateBase.h"
#include"../.././Util/Sound.h"

class DinosaurAttackScratch : public DinosaurStateBase
{
public:
	DinosaurAttackScratch(Vec2 vec)
	{
		m_vec = vec;
		m_imagePosX = 4; //�摜�̔ԍ�X���W
		m_imagePosY = 8;//�摜�̔ԍ�Y���W

		//�U���͈�
		m_attakSizeLeft = -100;
		m_attackSizeTop = 30;
		m_attackSizeRight = 0;
		m_attackSizeBottom = 100;

		//�U����
		m_attackDamage = 6;

		//�U������������܂ł̎���
		m_attackFrame = 0;
		m_attackMotion = true;

		Sound::play(Sound::DinoAttack3);

	}
	virtual ~DinosaurAttackScratch();

	virtual DinosaurStateBase* Update(int padNum) override;
};

