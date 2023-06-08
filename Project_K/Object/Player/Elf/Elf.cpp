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
//#include <memory>

namespace
{
	const char* const kFilmName = "Data/Image/Player/Elf/Elf.png";
	constexpr float kSpeed = 10.0f;

	constexpr float kGravity = 2.0f;
	constexpr float kJumpPower = -40.0f;
}

Elf::Elf() :
	m_handle(0),
	m_imageX(0), m_imageY(0),
	m_atackFlag(false),
	m_isDirection(false),
	m_isCollPos(false),
	m_pIdle(nullptr),
	m_pChargeShot(nullptr),
	m_pShot(nullptr),
	m_pPunch(nullptr),
	m_pUp(nullptr),
	m_pRun(nullptr)

{
	m_pIdle = new ElfIdle;// �ҋ@
	m_pRun = new ElfRun; // ����
	m_pJump = new ElfJump;
	m_pChargeShot = new ElfAttackArrowChargeShot; // �U��
	m_pShot = new ElfAttackArrowShot;       // �U��
	m_pPunch = new ElfAttackArrowPunch;	  // �U��
	m_pUp = new ElfAttackArrowUp;	      // �U��

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
	if (!m_pChargeShot->IsSetMove() ||
		!m_pJump->IsSetMove()||
		!m_pShot->IsSetMove() ||
		!m_pPunch->IsSetMove() ||
		!m_pUp->IsSetMove())

	{
		m_atackFlag = false;

		m_pChargeShot->SetMoveTime(true);
		m_pJump->SetMoveTime(true);
		m_pShot->SetMoveTime(true);
		m_pPunch->SetMoveTime(true);
		m_pUp->SetMoveTime(true);

		m_attackSizeLeft = 0;
		m_attackSizeTop = 0;
		m_attackSizeRight = 0;
		m_attackSizeBottom = 0;
	}

	// �U�����[�V�����ɓ������瓮���Ȃ��Ȃ�
	if (!m_atackFlag)
	{
		m_moveType = static_cast<int>(moveType::Idol);// �A�C�h�����

		if (Pad::IsPress(PAD_INPUT_RIGHT,m_padNum))
		{
			m_moveType = static_cast<int>(moveType::Run);// ����
			m_pos.x += kSpeed;
			m_isDirection = false;
		}
		else if (Pad::IsPress(PAD_INPUT_LEFT, m_padNum))
		{
			m_moveType = static_cast<int>(moveType::Run);// ����
			m_pos.x -= kSpeed;
			m_isDirection = true;
		}

		if (Pad::IsTrigger(PAD_INPUT_1, m_padNum))// XBOX A
		{
			m_moveType = static_cast<int>(moveType::Attack1);// �U��
			m_atackFlag = true;
		}
		if (Pad::IsTrigger(PAD_INPUT_2, m_padNum))// XBOX B
		{
			m_moveType = static_cast<int>(moveType::Attack2);// �U��
			m_atackFlag = true;
		}
		if (Pad::IsTrigger(PAD_INPUT_3, m_padNum))// XBOX X or Y
		{
			//�@�W�����v
			m_moveType = static_cast<int>(moveType::Jump);
			m_atackFlag = true;
			m_jumpAcc = kJumpPower;
			
		}
		if (Pad::IsTrigger(XINPUT_BUTTON_LEFT_SHOULDER, m_padNum) || (Pad::IsTrigger(PAD_INPUT_R, m_padNum)))// XBOX X or Y
		{
			//�@�W�����v

		}
		if (Pad::IsTrigger(PAD_INPUT_2, m_padNum) && (Pad::IsTrigger(PAD_INPUT_RIGHT, m_padNum)) ||// XBOX A && RIGHT
			Pad::IsTrigger(PAD_INPUT_2, m_padNum) && (Pad::IsTrigger(PAD_INPUT_LEFT, m_padNum)))   // XBOX A && LEFT
		{
			m_moveType = static_cast<int>(moveType::Attack3);;// �U��
			m_atackFlag = true;
		}
		if (Pad::IsTrigger(PAD_INPUT_2, m_padNum) && (Pad::IsTrigger(PAD_INPUT_UP, m_padNum)))// XBOX A && UP
		{
			m_moveType = static_cast<int>(moveType::Attack4);// �U��
			m_atackFlag = true;
		}
	}

	m_sizeLeft   = - 30;
	m_sizeTop    =   75;
	m_sizeRight  = m_sizeLeft + 60;
	m_sizeBottom = m_sizeTop + 176;

	AnimationSwitch();

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

	//m_Shot[0] = new ElfShot(m_pos, { -15,0 });

}

void Elf::Draw()
{
	my::MyDrawRectRotaGraph(
		static_cast<int>(m_pos.x), static_cast<int>(m_pos.y),//�v���C���[�̈ʒu
		m_imageX, m_imageY,// �摜�̉E��
		288, 128,
		4,
		DX_PI_F * 2,
		m_handle,
		true,
		m_isDirection
	);

#if _DEBUG	
	// �v���C���[�̃T�C�Y
	DrawBox(m_sizeLeft + static_cast<int>(m_pos.x),
			m_sizeTop + static_cast<int>(m_pos.y),
			m_sizeRight + static_cast<int>(m_pos.x),
			m_sizeBottom + static_cast<int>(m_pos.y),
		GetColor(GetRand(255), GetRand(255), GetRand(255)), false);
	// �U���͈�
	DrawBox(m_attackSizeLeft + static_cast<int>(m_pos.x),
			m_attackSizeTop + static_cast<int>(m_pos.y),
			m_attackSizeRight + static_cast<int>(m_pos.x),
			m_attackSizeBottom + static_cast<int>(m_pos.y),
			0xff0000, false);
#endif
	
}

void Elf::AnimationSwitch()
{
	switch (m_moveType)
	{
	case static_cast<int>(moveType::Idol):// �ҋ@
		m_pIdle->Update();
		// �摜�ǂݍ��݈ʒu
		m_imageX = m_pIdle->SetPosImageX();
		m_imageY = m_pIdle->SetPosImageY();
		// �U���͈͂��w��@�A�C�h����ԂȂ̂ňʒu��������
		m_attackSizeLeft   = 0;
		m_attackSizeTop    = 0;
		m_attackSizeRight  = 0;
		m_attackSizeBottom = 0;
		break;
	case static_cast<int>(moveType::Run):// ����
		m_pRun->Update();
		// �摜�ǂݍ��݈ʒu
		m_imageX = m_pRun->SetPosImageX();
		m_imageY = m_pRun->SetPosImageY();
		break;
	case static_cast<int>(moveType::Attack1):// �U�� : �ߐڍU��
		m_pPunch->Update();
		// �摜�ǂݍ��݈ʒu
		m_imageX = m_pPunch->SetPosImageX();
		m_imageY = m_pPunch->SetPosImageY();

		// �U���͈͂��w��
		// �����Ă�������Ŕ͈͂�����
		if (m_isDirection)
		{
			m_attackSizeLeft = - 230 - 90;
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
		break;
	case static_cast<int>(moveType::Attack2):// �U�� : �m�[�}���V���b�g
		m_pShot->Update();
		// �摜�ǂݍ��݈ʒu
		m_imageX = m_pShot->SetPosImageX();
		m_imageY = m_pShot->SetPosImageY();
		// �V���b�g
		break;
	case static_cast<int>(moveType::Attack3):// �U�� : �����ɍő�ἨV���b�g
		m_pChargeShot->Update();
		// �摜�ǂݍ��݈ʒu
		m_imageX = m_pChargeShot->SetPosImageX();
		m_imageY = m_pChargeShot->SetPosImageY();
		// �U���͈͂��w��
		// �����Ă�������Ŕ͈͂�����
		if (m_isDirection)
		{
			m_attackSizeLeft =- 580 - 10;
			m_attackSizeTop = 100;
			m_attackSizeRight = static_cast<int>(m_sizeLeft) - 80;
			m_attackSizeBottom = static_cast<int>(m_attackSizeTop) + 80;
		}
		else
		{
			m_attackSizeLeft =10;
			m_attackSizeTop = 100;
			m_attackSizeRight = static_cast<int>(m_attackSizeLeft) + 580;
			m_attackSizeBottom = static_cast<int>(m_attackSizeTop) + 80;
		}
		break;
	case static_cast<int>(moveType::Attack4):// �U�� : �΂ߏ�ɋߐڃV���b�g
		m_pUp->Update();
		// �摜�ǂݍ��݈ʒu
		m_imageX = m_pUp->SetPosImageX();
		m_imageY = m_pUp->SetPosImageY();
		// �U���͈͂��w��
		m_attackSizeLeft   = - 130;
		m_attackSizeTop    = - 130;
		m_attackSizeRight  = static_cast<int>(m_attackSizeLeft) + 280;
		m_attackSizeBottom = static_cast<int>(m_attackSizeTop) + 180;
		break;
	case static_cast<int>(moveType::Jump):// �W�����v
		m_pJump->Update();
		// �摜�ǂݍ��݈ʒu
		m_imageX = m_pJump->SetPosImageX();
		m_imageY = m_pJump->SetPosImageY();
		break;
	default:// �ҋ@
		m_pIdle->Update();
		// �摜�ǂݍ��݈ʒu
		m_imageX = m_pIdle->SetPosImageX();
		m_imageY = m_pIdle->SetPosImageY();
		// �U���͈͂��w��@�A�C�h����ԂȂ̂ňʒu��������
		m_attackSizeLeft   = 0;
		m_attackSizeTop    = 0;
		m_attackSizeRight  = 0;
		m_attackSizeBottom = 0;
		break;
	}
}