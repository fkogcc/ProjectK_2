#include "ElfAttackArrowChargeShot.h"
#include <DxLib.h>
namespace// ���̃l�[���X�y�[�X
{
	constexpr int kAttack_X = 16;
	constexpr int kAttack_Y = 13;
}

ElfAttackArrowChargeShot::ElfAttackArrowChargeShot()
{
	m_isMove = true;
}

void ElfAttackArrowChargeShot::Update()
{
	printfDx("%d\n", m_frameCount);
	m_frameCount++;
	if (m_frameCount == 5)//3�t���[���Ɉ��摜�`��ʒu��ύX����
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
