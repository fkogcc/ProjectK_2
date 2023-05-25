#include "KinnikuJump.h"

namespace
{
	// �d��
	constexpr float kGravity = 0.5f;
	// �W�����v��
	constexpr float kJumpPower = 24.0f;
}

KinnikuJump::KinnikuJump() :
	m_isJumping(true),
	m_isFalling(false)
{
}

KinnikuJump::~KinnikuJump()
{
}

void KinnikuJump::Update(float& jumpAcc, float& posY,int padNum)
{
	m_isJumping = true;
	m_isFalling = false;
	jumpAcc += kGravity;
	posY += jumpAcc;
	if (posY >= 650.0f)
	{
		posY = 650.0f;
		jumpAcc = 0.0f;
		m_isJumping = false;
	}

	if (!m_isJumping)
	{
		if (Pad::IsTrigger(PAD_INPUT_UP, padNum))
		{
			jumpAcc = -kJumpPower;
		}
	}

	if (jumpAcc >= 0)
	{
		m_isFalling = true;
	}
}

bool KinnikuJump::IsJump()
{
	return m_isJumping;
}

bool KinnikuJump::IsFall()
{
	return m_isFalling;
}

