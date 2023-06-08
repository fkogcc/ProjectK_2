#include "Elf.h"
#include "../../../Util/DrawFunctions.h"
#include "../../condition.h"
#include "ElfIdle.h"
#include "ElfRun.h"
#include "ElfJump.h"
#include "ElfAttackArrowChargeShot.h"
#include "ElfAttackArrowShot.h"
#include "ElfAttackArrowPunch.h"
#include "ElfAttackArrowUp.h"

#include "../../Object/Shot/ElfShot.h"
#include "../../Object/Shot/ShotBase.h"
#include "../../Object/Shot/NullShot.h"

#include "../../Util/Sound.h"

namespace
{
	const char* const kFilmName = "Data/Image/Player/Elf/Elf.png";
	constexpr float kSpeed = 10.0f;

	constexpr float kGravity = 2.0f;
	constexpr float kJumpPower = -40.0f;

	// �摜����̃v���C���[�̉E�����W
	constexpr int kSizeX = 288;
	constexpr int kSizeY = 128;

	// �v���C���[�T�C�Y
	constexpr int kSize = 4;

	// �v���C���[�p�x
	constexpr float kRota = DX_PI_F * 2;
}

Elf::Elf() :
	m_handle(0),
	m_imageX(0), m_imageY(0),
	m_isAttack(false),
	m_isDirection(false),
	m_pIdle(nullptr),
	m_pChargeShot(nullptr),
	m_pShot(nullptr),
	m_pPunch(nullptr),
	m_pUp(nullptr),
	m_pRun(nullptr)

{
	m_pIdle = new ElfIdle;// �ҋ@
	m_pRun  = new ElfRun; // ����
	m_pJump = new ElfJump;
	m_pPunch	  = new ElfAttackArrowPunch;	  // �U��
	m_pShot       = new ElfAttackArrowShot;       // �U��
	m_pChargeShot = new ElfAttackArrowChargeShot; // �U��
	m_pUp         = new ElfAttackArrowUp;	      // �U��

	m_pos.y = 600.0f - 176.0f;
}

Elf::~Elf()
{
}

void Elf::Init()
{
	m_handle = my::MyLoadGraph(kFilmName);
	m_pos = { 0.0f, 1080.0f / 2.0f };
}

void Elf::End()
{
	my::MyDeleteGraph(m_handle);
}

void Elf::Update()
{
	// �A�j���[�V������~
	AnimStop();

	if (m_attackFlag)
	{
		DrawString(100, 100, "true : �����܂���", 0xffffff);
	}
	else
	{
		// false ���ƍs���ł���
		DrawString(100, 100, "false : �����܂�", 0xffffff);
	}

	DrawFormatString(100, 200, 0xffffff,"damage : %d", m_damage);

	if (!m_attackFlag)
	{
		if (m_gapTime == -1)
		{
			m_damage = 0;
		}
	}
	if (m_gapTime != -1)
	{
	}

		// ����
		UpdateControl();

	// ���g�̓����蔻��
	UpdateHitColl();

	// �ǂ̓��������邩�����߂�
	AnimSwitch();

	// �d�͊֘A
	UpdateGravity();


}

void Elf::Draw()
{
	// �v���C���[�̕`��
	my::MyDrawRectRotaGraph(
		static_cast<int>(m_pos.x), static_cast<int>(m_pos.y),//�v���C���[�̈ʒu
		m_imageX, m_imageY,// �摜�̍���
		kSizeX, kSizeY,    // �摜�̉E��
		kSize,			   // �T�C�Y
		kRota,			   // ��]�p�x
		m_handle,		   // �n���h��
		true,		       // �摜����
		m_isDirection      // �摜���]
	);

#if _DEBUG
	// �v���C���[�̃T�C�Y
	DrawBox(m_sizeLeft + m_pos.x , 
			m_sizeTop + m_pos.y,
			m_sizeRight + m_pos.x, 
			m_sizeBottom + m_pos.y,
			0xffffff, false);

	// �U���͈�
	DrawBox(m_attackSizeLeft + m_pos.x,
			m_attackSizeTop + m_pos.y,
			m_attackSizeRight + m_pos.x,
			m_attackSizeBottom + m_pos.y,
			0xff0000, false);
#endif
}

// ����
void Elf::UpdateControl()
{

	// �U�����I��������ɑҋ@��ԂɈڍs����
	if (m_isAttack)
	{
		m_moveType = static_cast<int>(moveType::Idol);// �A�C�h�����
		m_isAttack = false;
	}

	// �U�����[�V�����ɓ������瓮���Ȃ��Ȃ�
	if (!m_attackFlag)
	{
		// ����
		if (Pad::IsPress(PAD_INPUT_RIGHT, m_padNum))
		{
			m_moveType = static_cast<int>(moveType::Run);
			m_pos.x += kSpeed;
			m_isDirection = false;
		}
		else if (Pad::IsPress(PAD_INPUT_LEFT, m_padNum))
		{
			m_moveType = static_cast<int>(moveType::Run);
			m_pos.x -= kSpeed;
			m_isDirection = true;
		}

		// �U��
		if (Pad::IsTrigger(PAD_INPUT_1, m_padNum) && m_moveType != static_cast<int>(moveType::Attack1))// XBOX A
		{
			m_moveType = static_cast<int>(moveType::Attack1);
			m_attackFlag = true;
		}
		// �U��
		if (Pad::IsTrigger(PAD_INPUT_2, m_padNum))// XBOX B
		{
			m_moveType = static_cast<int>(moveType::Attack2);
			m_attackFlag = true;
		}
		//�@�W�����v
		if (Pad::IsTrigger(PAD_INPUT_3, m_padNum))// XBOX X or Y
		{
			m_moveType = static_cast<int>(moveType::Jump);
			m_attackFlag = true;

			m_jumpAcc = kJumpPower;

		}
#if false	
		if (Pad::IsTrigger(PAD_INPUT_2, m_padNum) && // XBOX A && RIGHT
		   (Pad::IsTrigger(PAD_INPUT_RIGHT, m_padNum)) ||
			Pad::IsTrigger(PAD_INPUT_2, m_padNum) &&// XBOX A && LEFT
		   (Pad::IsTrigger(PAD_INPUT_LEFT, m_padNum)))   
		{
			m_moveType = static_cast<int>(moveType::Attack3);;// �U��
			m_attackFlag = true;
		}
		if (Pad::IsTrigger(PAD_INPUT_2, m_padNum) &&// XBOX A && UP
		   (Pad::IsTrigger(PAD_INPUT_UP, m_padNum)))
		{
			m_moveType = static_cast<int>(moveType::Attack4);// �U��
			m_attackFlag = true;
		}
#endif
		if (Pad::IsTrigger(PAD_INPUT_5, m_padNum) && m_moveType != static_cast<int>(moveType::Attack3))// XBOX X or Y
		{
			m_moveType = static_cast<int>(moveType::Attack3);// �U��
			m_attackFlag = true;
		}
		if (Pad::IsTrigger(PAD_INPUT_6, m_padNum))// XBOX X or Y
		{
			m_moveType = static_cast<int>(moveType::Attack4);// �U��
			m_attackFlag = true;
		}
	}
}

// �A�j���[�V������~
void Elf::AnimStop()
{
	printfDx("%d\n", m_gapTime);
	// �A�j���[�V�������I�������
	if (!m_pChargeShot->IsSetMove() ||
		!m_pJump->IsSetMove      () ||
		!m_pShot->IsSetMove		 () ||
		!m_pPunch->IsSetMove	 () ||
		!m_pUp->IsSetMove		 ())

	{
		m_isAttack   = true;
		m_attackFlag = true;

		m_gapTime--;

		// �d����Ԃ��I�������
		if (m_gapTime < 0)
		{
			m_attackFlag = false;
			m_pChargeShot->SetMoveTime(true);
			m_pJump->SetMoveTime(true);
			m_pShot->SetMoveTime(true);
			m_pPunch->SetMoveTime(true);
			m_pUp->SetMoveTime(true);
		}

		// �U���͈͂�0�ŏ�����
		m_attackSizeLeft   = 0;
		m_attackSizeTop    = 0;
		m_attackSizeRight  = 0;
		m_attackSizeBottom = 0;
	}
}

// �A�j���ƍU���͈͂��w��
void Elf::AnimSwitch()
{
	switch (m_moveType)
	{
	case static_cast<int>(moveType::Idol):// �ҋ@
		AnimIdol();
		break;
	case static_cast<int>(moveType::Run):// ����
		AnimRun();
		break;
	case static_cast<int>(moveType::Jump):// �W�����v
		AnimJump();
		m_gapTime = 1;
		break;
	case static_cast<int>(moveType::Attack1):// �U�� : �ߐڍU��
		AnimAttackPunch();
		m_gapTime = 2;
		break;
	case static_cast<int>(moveType::Attack2):// �U�� : �m�[�}���V���b�g
		AnimAttackNormalShot();
		m_gapTime = 10;
		break;
	case static_cast<int>(moveType::Attack3):// �U�� : �����ɍő�ἨV���b�g
		AnimAttackChargeShit();
		m_gapTime = 60;
		break;
	case static_cast<int>(moveType::Attack4):// �U�� : �΂ߏ�ɋߐڃV���b�g
		AnimAttackUpShit();
		m_gapTime = 30;
		break;
	default:// �ҋ@
		AnimIdol();
		break;
	}
}

// ���g�̓����蔻��
void Elf::UpdateHitColl()
{
	// �v���C���[�̓����蔻��p�ʒu
	m_sizeLeft = -30;
	m_sizeTop = 75;
	m_sizeRight = m_sizeLeft + 60;
	m_sizeBottom = m_sizeTop + 176;
}

// �d�͊֘A
void Elf::UpdateGravity()
{
	// �d��
	float posY = 600.0f - 176.0f;
	if (m_pos.y > posY)
	{
		m_pos.y = posY;
		if (m_jumpAcc > 0.0f)
		{
			m_jumpAcc = 0.0f;
		}
	}

	// �d��
	m_jumpAcc += kGravity;
	m_pos.y += m_jumpAcc;
}

// �ҋ@��ԃA�j���[�V����
void Elf::AnimIdol()
{
	m_pIdle->Update();
	// �摜�ǂݍ��݈ʒu
	m_imageX = m_pIdle->SetPosImageX();
	m_imageY = m_pIdle->SetPosImageY();
	// �U���͈͂��w��@�A�C�h����ԂȂ̂ňʒu��������
	m_attackSizeLeft = 0;
	m_attackSizeTop = 0;
	m_attackSizeRight = 0;
	m_attackSizeBottom = 0;

	// �U����
	m_damage = 0;
}

// ����A�j���[�V����
void Elf::AnimRun()
{
	m_pRun->Update();
	// �摜�ǂݍ��݈ʒu
	m_imageX = m_pRun->SetPosImageX();
	m_imageY = m_pRun->SetPosImageY();
	// �U���͈͂��w��@�����ԂȂ̂ňʒu��������
	m_attackSizeLeft = 0;
	m_attackSizeTop = 0;
	m_attackSizeRight = 0;
	m_attackSizeBottom = 0;

	// �U����
	m_damage = 0;
}

// �W�����v�A�j���[�V����
void Elf::AnimJump()
{
	m_pJump->Update();
	// �摜�ǂݍ��݈ʒu
	m_imageX = m_pJump->SetPosImageX();
	m_imageY = m_pJump->SetPosImageY();

	// �U����
	m_damage = 0;
}

// �p���`�A�j���[�V����
void Elf::AnimAttackPunch()
{
	m_pPunch->Update();
	// �摜�ǂݍ��݈ʒu
	m_imageX = m_pPunch->SetPosImageX();
	m_imageY = m_pPunch->SetPosImageY();

	// �U���͈͂��w��
	// �����Ă�������Ŕ͈͂�����
	if (m_isDirection)
	{
		m_attackSizeLeft = -230 - 90;
		m_attackSizeTop = 100;
		m_attackSizeRight = static_cast<int>(m_sizeLeft) - 50;
		m_attackSizeBottom = static_cast<int>(m_attackSizeTop) + 50;
	}
	else
	{
		m_attackSizeLeft = 90;
		m_attackSizeTop = 100;
		m_attackSizeRight = static_cast<int>(m_attackSizeLeft) + 230;
		m_attackSizeBottom = static_cast<int>(m_attackSizeTop) + 50;
	}

	// �U����
	m_damage = 1;
}

// �ʏ�V���b�g�A�j���[�V����
void Elf::AnimAttackNormalShot()
{
	m_pShot->Update();
	// �摜�ǂݍ��݈ʒu
	m_imageX = m_pShot->SetPosImageX();
	m_imageY = m_pShot->SetPosImageY();

	// �U����
	m_damage = 5;
}

// �`���[�W�V���b�g�A�j���[�V����
void Elf::AnimAttackChargeShit()
{
	m_pChargeShot->Update();
	// �摜�ǂݍ��݈ʒu
	m_imageX = m_pChargeShot->SetPosImageX();
	m_imageY = m_pChargeShot->SetPosImageY();
	// �U���͈͂��w��
	// �����Ă�������Ŕ͈͂�����
	if (m_isDirection)
	{
		m_attackSizeLeft = -580 - 10;
		m_attackSizeTop = 100;
		m_attackSizeRight = static_cast<int>(m_sizeLeft) - 80;
		m_attackSizeBottom = static_cast<int>(m_attackSizeTop) + 80;
	}
	else
	{
		m_attackSizeLeft = 10;
		m_attackSizeTop = 100;
		m_attackSizeRight = static_cast<int>(m_attackSizeLeft) + 580;
		m_attackSizeBottom = static_cast<int>(m_attackSizeTop) + 80;
	}

	// �U����
	m_damage = 20;
}

// ��U���A�j���[�V����
void Elf::AnimAttackUpShit()
{
	m_pUp->Update();
	// �摜�ǂݍ��݈ʒu
	m_imageX = m_pUp->SetPosImageX();
	m_imageY = m_pUp->SetPosImageY();
	// �U���͈͂��w��
	m_attackSizeLeft = -130;
	m_attackSizeTop = -130;
	m_attackSizeRight = static_cast<int>(m_attackSizeLeft) + 280;
	m_attackSizeBottom = static_cast<int>(m_attackSizeTop) + 180;

	// �U����
	m_damage = 5;
}
