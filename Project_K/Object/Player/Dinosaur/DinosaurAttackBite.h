#pragma once
#include "DinosaurStateBase.h"
#include"../.././Util/Sound.h"
class DinosaurAttackBite : public DinosaurStateBase
{
public:
	DinosaurAttackBite(Vec2 vec)
	{
		m_vec = vec;
		m_imagePosX = 0; //�摜�̔ԍ�X���W
		m_imagePosY = 5;//�摜�̔ԍ�Y���W

		//�U���͈�
		m_attakSizeLeft = -130;
		m_attackSizeTop = 0;
		m_attackSizeRight = 0;
		m_attackSizeBottom = 80;

		//�U����
		m_attackDamage = 8;

		m_attackMotion = true;

		Sound::play(Sound::DinoAttack1);
	}
	virtual ~DinosaurAttackBite();

	virtual DinosaurStateBase* Update(int padNum) override;
};

