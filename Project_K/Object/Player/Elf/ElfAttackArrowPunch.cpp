#include "ElfAttackArrowPunch.h"
namespace// ���̃l�[���X�y�[�X
{
	constexpr int kAttack_X = 9;
	constexpr int kAttack_Y = 10;
}

ElfAttackArrowPunch::ElfAttackArrowPunch()
{
	m_isMove = true;
}

void ElfAttackArrowPunch::Update()
{

	m_frameCount++;
	if (m_frameCount == 1)//3�t���[���Ɉ��摜�`��ʒu��ύX����
	{
		m_frameCount = 0;
		if (m_imagePosX < 288 * kAttack_X)//�摜���E�ɑ����Ă�����E�ɂ��炷
		{
			m_imagePosX += 288;//X�����E�ɂ��炷
		}
		else
		{
			m_imagePosX = 0;// �摜�̕`�悳����ʒu�������l�ɖ߂�
			m_isMove = false;// �U���I��
		}
	}
	m_imagePosY = 128 * kAttack_Y;// �摜�̕`�悳����c�̈ʒu

	m_attackDamage = 30;//�U����
}
