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

#include "../../Shot/ShotBase.h"

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
	m_isAttack(false),
	m_isDirection(false),
	m_isCollPos(false),
	m_pIdle(nullptr),
	m_pChargeShot(nullptr),
	m_pShot(nullptr),
	m_pPunch(nullptr),
	m_pUp(nullptr),
	m_pRun(nullptr)

{
	m_pIdle = new ElfIdle;// 待機
	m_pRun = new ElfRun; // 走り
	m_pJump = new ElfJump;
	m_pChargeShot = new ElfAttackArrowChargeShot; // 攻撃
	m_pShot = new ElfAttackArrowShot;       // 攻撃
	m_pPunch = new ElfAttackArrowPunch;	  // 攻撃
	m_pUp = new ElfAttackArrowUp;	      // 攻撃

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
		m_isAttack = false;

		m_pChargeShot->SetMoveTime(true);
		m_pJump->SetMoveTime(true);
		m_pShot->SetMoveTime(true);
		m_pPunch->SetMoveTime(true);
		m_pUp->SetMoveTime(true);
	}

#if true

	if (Pad::IsPress(PAD_INPUT_DOWN))m_pos.y += 15.0f;
//	if (Pad::IsPress(PAD_INPUT_UP)) m_pos.y -= 15.0f;

#endif


	if (!m_isAttack)// 攻撃モーションに入ったら動けなくなる
	{
		m_moveType = static_cast<int>(moveType::Idol);// アイドル状態

	//	m_moveType = static_cast<int>(moveType::Jump);

		if (Pad::IsPress(PAD_INPUT_RIGHT,m_padNum))
		{
			m_moveType = static_cast<int>(moveType::Run);// 走る
			m_pos.x += kSpeed;
			m_isDirection = false;
		}
		else if (Pad::IsPress(PAD_INPUT_LEFT, m_padNum))
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

		if (Pad::IsTrigger(PAD_INPUT_1, m_padNum))// XBOX A
		{
			m_moveType = static_cast<int>(moveType::Attack1);// 攻撃
			m_isAttack = true;
		}
		if (Pad::IsTrigger(PAD_INPUT_2, m_padNum))// XBOX B
		{
			m_moveType = static_cast<int>(moveType::Attack2);// 攻撃
			m_isAttack = true;
		}
		if (Pad::IsTrigger(PAD_INPUT_3, m_padNum))// XBOX X or Y
		{
			//　ジャンプ
			m_moveType = static_cast<int>(moveType::Jump);
			m_isAttack = true;
			m_jumpAcc = kJumpPower;
			
		}
		if (Pad::IsTrigger(XINPUT_BUTTON_LEFT_SHOULDER, m_padNum) || (Pad::IsTrigger(PAD_INPUT_R, m_padNum)))// XBOX X or Y
		{
			//　ジャンプ

		}
		if (Pad::IsTrigger(PAD_INPUT_2, m_padNum) && (Pad::IsTrigger(PAD_INPUT_RIGHT, m_padNum)) ||// XBOX A && RIGHT
			Pad::IsTrigger(PAD_INPUT_2, m_padNum) && (Pad::IsTrigger(PAD_INPUT_LEFT, m_padNum)))   // XBOX A && LEFT
		{
			m_moveType = static_cast<int>(moveType::Attack3);;// 攻撃
			m_isAttack = true;
		}
		if (Pad::IsTrigger(PAD_INPUT_2, m_padNum) && (Pad::IsTrigger(PAD_INPUT_UP, m_padNum)))// XBOX A && UP
		{
			m_moveType = static_cast<int>(moveType::Attack4);// 攻撃
			m_isAttack = true;
		}
	}

	m_sizeLeft   = static_cast<int>(m_pos.x) - 30;
	m_sizeTop    = static_cast<int>(m_pos.y) + 75;
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
	
	// 重力
	m_jumpAcc += kGravity;
	m_pos.y += m_jumpAcc;

}

void Elf::Draw()
{
	//	DrawBox(m_posLeft, m_posTop, m_posRight, m_posBottom, 0xffffff, true);

	my::MyDrawRectRotaGraph(
		static_cast<int>(m_pos.x), static_cast<int>(m_pos.y),//プレイヤーの位置
		m_imageX, m_imageY,// 画像の右上
		288, 128,
		4,
		DX_PI_F * 2,
		m_handle,
		true,
		m_isDirection
	);

	DrawBox(m_sizeLeft, m_sizeTop, m_sizeRight, m_sizeBottom,0xffffff,false);

	if(m_isAttack)DrawBox(m_attackSizeLeft, m_attackSizeTop, m_attackSizeRight, m_attackSizeBottom, 0xff0000, false);
	
}

void Elf::AnimationSwitch()
{
	switch (m_moveType)
	{
	case static_cast<int>(moveType::Idol):// 待機
		m_pIdle->Update();
		// 画像読み込み位置
		m_imageX = m_pIdle->SetPosImageX();
		m_imageY = m_pIdle->SetPosImageY();
		// 攻撃範囲を指定　アイドル状態なので位置を初期化
		m_attackSizeLeft   = 0;
		m_attackSizeTop    = 0;
		m_attackSizeRight  = 0;
		m_attackSizeBottom = 0;
		break;
	case static_cast<int>(moveType::Run):// 走り
		m_pRun->Update();
		// 画像読み込み位置
		m_imageX = m_pRun->SetPosImageX();
		m_imageY = m_pRun->SetPosImageY();
		break;
	case static_cast<int>(moveType::Attack1):// 攻撃
		m_pPunch->Update();
		// 画像読み込み位置
		m_imageX = m_pPunch->SetPosImageX();
		m_imageY = m_pPunch->SetPosImageY();
		// 攻撃範囲を指定
		m_attackSizeLeft   = static_cast<int>(m_pos.x) + 90;
		m_attackSizeTop    = static_cast<int>(m_pos.y) + 100;
		m_attackSizeRight  = static_cast<int>(m_attackSizeLeft) + 230;
		m_attackSizeBottom = static_cast<int>(m_attackSizeTop) + 50;
		break;
	case static_cast<int>(moveType::Attack2):// 攻撃
		m_pShot->Update();
		// 画像読み込み位置
		m_imageX = m_pShot->SetPosImageX();
		m_imageY = m_pShot->SetPosImageY();
		// ショット
		break;
	case static_cast<int>(moveType::Attack3):// 攻撃
		m_pChargeShot->Update();
		// 画像読み込み位置
		m_imageX = m_pChargeShot->SetPosImageX();
		m_imageY = m_pChargeShot->SetPosImageY();
		// 攻撃範囲を指定
		m_attackSizeLeft = static_cast<int>(m_pos.x) + 10;
		m_attackSizeTop = static_cast<int>(m_pos.y)  + 100;
		m_attackSizeRight = static_cast<int>(m_attackSizeLeft) + 580;
		m_attackSizeBottom = static_cast<int>(m_attackSizeTop) + 80;
		break;
	case static_cast<int>(moveType::Attack4):// 攻撃
		m_pUp->Update();
		// 画像読み込み位置
		m_imageX = m_pUp->SetPosImageX();
		m_imageY = m_pUp->SetPosImageY();
		// 攻撃範囲を指定
		m_attackSizeLeft   = static_cast<int>(m_pos.x) - 130;
		m_attackSizeTop    = static_cast<int>(m_pos.y) - 130;
		m_attackSizeRight  = static_cast<int>(m_attackSizeLeft) + 280;
		m_attackSizeBottom = static_cast<int>(m_attackSizeTop) + 180;
		break;
	case static_cast<int>(moveType::Jump):// 攻撃
		m_pJump->Update();
		// 画像読み込み位置
		m_imageX = m_pJump->SetPosImageX();
		m_imageY = m_pJump->SetPosImageY();
		// 
	//	m_pos.y -= m_pJump->Gravity();
		break;
	default:// 待機
		m_pIdle->Update();
		// 画像読み込み位置
		m_imageX = m_pIdle->SetPosImageX();
		m_imageY = m_pIdle->SetPosImageY();
		// 攻撃範囲を指定　アイドル状態なので位置を初期化
		m_attackSizeLeft   = 0;
		m_attackSizeTop    = 0;
		m_attackSizeRight  = 0;
		m_attackSizeBottom = 0;
		break;
	}
}