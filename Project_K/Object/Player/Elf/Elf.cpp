#include "Elf.h"
#include "../../../Util/DrawFunctions.h"
#include "../../condition.h"
#include "ElfIdle.h"
#include "ElfRun.h"
#include "ElfAttackArrowChargeShot.h"
#include "ElfAttackArrowShot.h"
#include "ElfAttackArrowPunch.h"
#include "ElfAttackArrowUp.h"

namespace
{
	const char* const kFilmName = "Data/Image/Player/Elf/Elf.png";
	constexpr float kSpeed = 10.0f;
}

Elf::Elf() :
	m_handle(0),
	m_imageX(0), m_imageY(0),
	m_isDirection(false),
	m_pIdle(nullptr),
	m_pChargeShot(nullptr),
	m_pShot(nullptr),
	m_pPunch(nullptr),
	m_pUp(nullptr),
	m_pRun(nullptr)

{
	m_pIdle = new ElfIdle;// 待機
	m_pRun = new ElfRun; // 走り
	m_pChargeShot = new ElfAttackArrowChargeShot; // 攻撃
	m_pShot = new ElfAttackArrowShot;       // 攻撃
	m_pPunch = new ElfAttackArrowPunch;	  // 攻撃
	m_pUp = new ElfAttackArrowUp;	      // 攻撃
}

Elf::~Elf()
{
}

void Elf::Init()
{
	m_handle = my::MyLoadGraph(kFilmName);
}

void Elf::End()
{
	my::MyDeleteGraph(m_handle);
}

void Elf::Update()
{
	Pad::update();

	if (!m_pChargeShot->IsSetMove() ||
		!m_pShot->IsSetMove() ||
		!m_pPunch->IsSetMove() ||
		!m_pUp->IsSetMove())
	{
		m_attackFlag = false;

		m_pChargeShot->SetMoveTime(true);
		m_pShot->SetMoveTime(true);
		m_pPunch->SetMoveTime(true);
		m_pUp->SetMoveTime(true);
	}

	if (!m_attackFlag)// 攻撃モーションに入ったら動けなくなる
	{
		m_moveType = static_cast<int>(moveType::Idol);// アイドル状態

		if (Pad::isPress(PAD_INPUT_RIGHT))
		{
			m_moveType = static_cast<int>(moveType::Run);// 走る
			m_pos.x += kSpeed;
			m_isDirection = false;
		}
		else if (Pad::isPress(PAD_INPUT_LEFT))
		{
			m_moveType = static_cast<int>(moveType::Run);// 走る
			m_pos.x -= kSpeed;
			m_isDirection = true;
		}
		else
		{
			//	m_moveType = static_cast<int>(moveType::Idol);// アイドル状態
			//	m_isAttack = false;
		}

		if (Pad::isTrigger(PAD_INPUT_1))// XBOX A
		{
			m_moveType = static_cast<int>(moveType::Attack1);// 攻撃
			m_attackFlag = true;

			m_attackSizeLeft = 0;
			m_attackSizeTop = 0;
			m_attackSizeRight = 0;
			m_attackSizeBottom = 0;
		}
		if (Pad::isTrigger(PAD_INPUT_2))// XBOX B
		{
			m_moveType = static_cast<int>(moveType::Attack2);// 攻撃
			m_attackFlag = true;

			m_attackSizeLeft = 0;
			m_attackSizeTop = 0;
			m_attackSizeRight = 0;
			m_attackSizeBottom = 0;
		}
		if (Pad::isTrigger(PAD_INPUT_3) || (Pad::isTrigger(PAD_INPUT_4)))// XBOX X or Y
		{
			//　ジャンプ
		//	m_moveType = static_cast<int>(moveType::Jump);
		}
		if (Pad::isTrigger(XINPUT_BUTTON_LEFT_SHOULDER) || (Pad::isTrigger(PAD_INPUT_R)))// XBOX X or Y
		{
			//　ジャンプ

		}
		if (Pad::isTrigger(PAD_INPUT_2) && (Pad::isTrigger(PAD_INPUT_RIGHT)) ||// XBOX A && RIGHT
			Pad::isTrigger(PAD_INPUT_2) && (Pad::isTrigger(PAD_INPUT_LEFT)))   // XBOX A && LEFT
		{
			m_moveType = static_cast<int>(moveType::Attack3);;// 攻撃
			m_attackFlag = true;

			m_attackSizeLeft = 0;
			m_attackSizeTop = 0;
			m_attackSizeRight = 0;
			m_attackSizeBottom = 0;
		}
		if (Pad::isTrigger(PAD_INPUT_2) && (Pad::isTrigger(PAD_INPUT_UP)) ||
			Pad::isTrigger(PAD_INPUT_3))// XBOX A && UP
		{
			m_moveType = static_cast<int>(moveType::Attack4);// 攻撃
			m_attackFlag = true;

			m_attackSizeLeft = 0;
			m_attackSizeTop = 0;
			m_attackSizeRight = 0;
			m_attackSizeBottom = 0;
		}
	}

	//m_posLeft   = m_pos.x   - 50;// プレイヤーのサイズ
	//m_posTop    = m_pos.y   + 90; 
	//m_posRight  = m_posLeft + 100;
	//m_posBottom = m_posTop  + 195; 

	AnimationSwitch();

}

void Elf::Draw()
{
	//	DrawBox(m_posLeft, m_posTop, m_posRight, m_posBottom, 0xffffff, true);

	my::MyDrawRectRotaGraph(
		static_cast<int>(m_pos.x), static_cast<int>(m_pos.y),//プレイヤーの位置
		m_imageX, m_imageY,// 画像の右上
		288, 128,
		6,
		DX_PI_F * 2,
		m_handle,
		true,
		m_isDirection
	);
}

void Elf::AnimationSwitch()
{
	switch (m_moveType)
	{
	case static_cast<int>(moveType::Idol):// 待機
		m_pIdle->Update();
		m_imageX = m_pIdle->SetPosImageX();
		m_imageY = m_pIdle->SetPosImageY();
		break;
	case static_cast<int>(moveType::Run):// 走り
		m_pRun->Update();
		m_imageX = m_pRun->SetPosImageX();
		m_imageY = m_pRun->SetPosImageY();
		break;
	case static_cast<int>(moveType::Attack1):// 攻撃
		m_pPunch->Update();
		m_imageX = m_pPunch->SetPosImageX();
		m_imageY = m_pPunch->SetPosImageY();
		break;
	case static_cast<int>(moveType::Attack2):// 攻撃
		m_pShot->Update();
		m_imageX = m_pShot->SetPosImageX();
		m_imageY = m_pShot->SetPosImageY();
		break;
	case static_cast<int>(moveType::Attack3):// 攻撃
		m_pChargeShot->Update();
		m_imageX = m_pChargeShot->SetPosImageX();
		m_imageY = m_pChargeShot->SetPosImageY();
		break;
	case static_cast<int>(moveType::Attack4):// 攻撃
		m_pUp->Update();
		m_imageX = m_pUp->SetPosImageX();
		m_imageY = m_pUp->SetPosImageY();
		break;
	default:// 待機
		m_pIdle->Update();
		m_imageX = m_pIdle->SetPosImageX();
		m_imageY = m_pIdle->SetPosImageY();
		break;
	}
}