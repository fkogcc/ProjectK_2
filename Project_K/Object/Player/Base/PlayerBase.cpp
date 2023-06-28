#include "PlayerBase.h"
#include "../../Shot/NullShot.h"
#include"../../../Util/game.h"

namespace
{
	constexpr float kAccX = 0.5f; //X���̃m�b�N�o�b�N������
	constexpr float kAccY = 1.0f;//Y���̃m�b�N�o�b�N������

	constexpr float kKnockBackX = 8.0f;//X���̃m�b�N�o�b�N��
	constexpr float kKnockBackY = -5.0f;//Y���̃m�b�N�o�b�N��
}

PlayerBase::PlayerBase()
{
	//�V���b�g��������
	for (int i = 0; i < kShotMax; i++)
	{
		m_pShot[i] = new NullShot();
	}
}

//�m�b�N�o�b�N�Z�b�g
void PlayerBase::SetKnockBack(float toPlayer)//�v���C���[���m�̈ʒu
{
	// �G�v���C���[�������ɂ���Ƃ�
	if (toPlayer < 0.0f)
	{
		m_knockBack = { kKnockBackX ,kKnockBackY };
	}
	// �G�v���C���[���E���ɂ���Ƃ�
	if (toPlayer >= 0.0f)
	{
		m_knockBack = { -kKnockBackX ,kKnockBackY };
	}
}

void PlayerBase::DebugDrawCollision()
{
	if (m_attackFlag)
	{
		DrawBox(static_cast<int> (m_pos.x) + m_attackSizeLeft,
			static_cast<int> (m_pos.y) + m_attackSizeTop,
			static_cast<int> (m_pos.x) + m_attackSizeRight,
			static_cast<int> (m_pos.y) + m_attackSizeBottom,
			0xff0000, false);
	}
	
}

//�m�b�N�o�b�N����
void PlayerBase::KnockBack()
{
	//m_onDamageFrame��0�ɂȂ�܂ŉ������Ȃ�
	if (m_onDamageFrame > 0)
	{
		m_onDamageFrame-=2;
		damageMove();
	}
}

void PlayerBase::CharDefaultPos(bool& direction)
{
	if (m_padNum == 1)
	{
		m_pos.x = 500.0f;
		m_pos.y = 600.0f;
		direction = false;
	}
	else if (m_padNum == 2)
	{
		m_pos.x = 1400.0f;
		m_pos.y = 600.0f;
		direction = true;
	}
}

//�U����H��������̓���
void PlayerBase::damageMove()
{
	m_pos += m_knockBack;

	m_knockBack.x = min(max(m_knockBack.x- kAccX, 0), m_knockBack.x + kAccX);
	m_knockBack.y += kAccY;
}

//�v���C���[�̓����̐���
void PlayerBase::moveLimit()
{
	int playerSize = m_sizeRight - m_sizeLeft;
	if (m_pos.x < static_cast<float>(-abs(playerSize)))
	{
		m_pos.x = static_cast<float>(Game::kScreenWidth) + static_cast<float>(abs(playerSize));
	}

	if (m_pos.x > static_cast<float>(Game::kScreenWidth) + static_cast<float>(abs(playerSize)))
	{
		m_pos.x = static_cast<float>(-abs(playerSize)) ;
	}
}
