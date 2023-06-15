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

	// 画像からのプレイヤーの右下座標
	constexpr int kSizeX = 288;
	constexpr int kSizeY = 128;

	// プレイヤーサイズ
	constexpr int kSize = 4;

	// プレイヤー角度
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
	m_pIdle = new ElfIdle;// 待機
	m_pRun = new ElfRun; // 走り
	m_pJump = new ElfJump;
	m_pPunch = new ElfAttackArrowPunch;	  // 攻撃
	m_pShot = new ElfAttackArrowShot;       // 攻撃
	m_pChargeShot = new ElfAttackArrowChargeShot; // 攻撃
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


	if (m_attackFlag)
	{
		//DrawString(100, 100, "true : 動けません", 0xffffff);
	}
	else
	{
		// false だと行動できる
		//DrawString(100, 100, "false : 動けます", 0xffffff);
	}

	KnockBack();


	// アニメーション停止
	AnimStop();

	if (!m_attackFlag)
	{
		if (m_gapTime == -1)
		{
			m_damage = 0;
		}
	}

	// 操作
	UpdateControl();

	// 自身の当たり判定
	UpdateHitColl();

	// どの動きをするかを決める
	AnimSwitch();

	// 重力関連
	UpdateGravity();
}

void Elf::Draw()
{
	// プレイヤーの描画
	my::MyDrawRectRotaGraph(
		static_cast<int>(m_pos.x), static_cast<int>(m_pos.y),//プレイヤーの位置
		m_imageX, m_imageY,// 画像の左上
		kSizeX, kSizeY,    // 画像の右下
		kSize,			   // サイズ
		kRota,			   // 回転角度
		m_handle,		   // ハンドル
		true,		       // 画像透過
		m_isDirection      // 画像反転
	);


}

// 操作
void Elf::UpdateControl()
{
	// 攻撃が終わった時に待機状態に移行する
	if (m_isAttack)
	{
		m_moveType = static_cast<int>(moveType::Idol);// アイドル状態
		m_isAttack = false;
	}
	// 攻撃モーションに入ったら動けなくなる
	if (!m_attackFlag)
	{
		// 走る
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

		// 攻撃
		if (Pad::IsTrigger(PAD_INPUT_1, m_padNum) && m_moveType != static_cast<int>(moveType::Attack1))// XBOX A
		{
			m_moveType = static_cast<int>(moveType::Attack1);
			m_attackFlag = true;
		}
		// 攻撃
		if (Pad::IsTrigger(PAD_INPUT_2, m_padNum) && m_moveType != static_cast<int>(moveType::Attack2))// XBOX B
		{
			m_moveType = static_cast<int>(moveType::Attack2);
			m_attackFlag = true;
		}
		//　ジャンプ
		if (Pad::IsTrigger(PAD_INPUT_3, m_padNum))// XBOX X or Y
		{
			m_moveType = static_cast<int>(moveType::Jump);
			m_attackFlag = true;

			m_jumpAcc = kJumpPower;

		}
		if (Pad::IsTrigger(PAD_INPUT_5, m_padNum) && m_moveType != static_cast<int>(moveType::Attack3))// XBOX X or Y
		{
			m_moveType = static_cast<int>(moveType::Attack3);// 攻撃
			m_attackFlag = true;
		}
		if (Pad::IsTrigger(PAD_INPUT_6, m_padNum) && m_moveType != static_cast<int>(moveType::Attack4))// XBOX X or Y
		{
			m_moveType = static_cast<int>(moveType::Attack4);// 攻撃
			m_attackFlag = true;
		}

		if (m_moveType == static_cast<int>(moveType::Run) &&
			(Pad::IsRelase(PAD_INPUT_LEFT, m_padNum) || Pad::IsRelase(PAD_INPUT_RIGHT, m_padNum)))
		{
			m_isAttack = true;
		}
	}
}

// アニメーション停止
void Elf::AnimStop()
{
	// アニメーションが終わったら
	if (!m_pChargeShot->IsSetMove() ||

		!m_pJump->IsSetMove      () ||
		!m_pShot->IsSetMove		 () ||
		!m_pPunch->IsSetMove	 () ||
		!m_pUp->IsSetMove		 ())

#if _DEBUG
	// プレイヤーのサイズ
	DrawBox(m_sizeLeft + static_cast<int>(m_pos.x) ,
			m_sizeTop + static_cast<int>(m_pos.y),
			m_sizeRight + static_cast<int>(m_pos.x),
			m_sizeBottom + static_cast<int>(m_pos.y),
			0xffffff, false);
#endif
	// m_attackFlagがtrueのとき攻撃当たり判定を表示
	if (m_attackFlag)
		if(
		!m_pJump->IsSetMove() ||
		!m_pShot->IsSetMove() ||
		!m_pPunch->IsSetMove() ||
		!m_pUp->IsSetMove())

	{
		m_isAttack = true;
		m_attackFlag = true;

		m_gapTime--;

		// 攻撃範囲を0で初期化
		m_attackSizeLeft = 0;
		m_attackSizeTop = 0;
		m_attackSizeRight = 0;
		m_attackSizeBottom = 0;
	}
	// 硬直状態が終わったら
	if (m_gapTime < 0)
	{
		m_attackFlag = false;
		m_pChargeShot->SetMoveTime(true);
		m_pJump->SetMoveTime(true);
		m_pShot->SetMoveTime(true);
		m_pPunch->SetMoveTime(true);
		m_pUp->SetMoveTime(true);
	}
}

// アニメと攻撃範囲を指定
void Elf::AnimSwitch()
{
	switch (m_moveType)
	{
	case static_cast<int>(moveType::Idol):// 待機
		AnimIdol();
		break;
	case static_cast<int>(moveType::Run):// 走り
		AnimRun();
		break;
	case static_cast<int>(moveType::Jump):// ジャンプ
		AnimJump();
		m_gapTime = 1;
		break;
	case static_cast<int>(moveType::Attack1):// 攻撃 : 近接攻撃
		AnimAttackPunch();
		m_gapTime = 2;
		break;
	case static_cast<int>(moveType::Attack2):// 攻撃 : ノーマルショット
		AnimAttackNormalShot();
		m_gapTime = 10;
		break;
	case static_cast<int>(moveType::Attack3):// 攻撃 : 直線に最大火力ショット
		AnimAttackChargeShit();
		m_gapTime = 60;
		break;
	case static_cast<int>(moveType::Attack4):// 攻撃 : 斜め上に近接ショット
		AnimAttackUpShit();
		m_gapTime = 30;
		break;
	default:// 待機
		AnimIdol();
		break;
	}
}

// 自身の当たり判定
void Elf::UpdateHitColl()
{
	// プレイヤーの当たり判定用位置
	m_sizeLeft = -30;
	m_sizeTop = 75;
	m_sizeRight = m_sizeLeft + 60;
	m_sizeBottom = m_sizeTop + 176;
}

// 重力関連
void Elf::UpdateGravity()
{
	// 重力
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

// 待機状態アニメーション
void Elf::AnimIdol()
{
	m_pIdle->Update();
	// 画像読み込み位置
	m_imageX = m_pIdle->SetPosImageX();
	m_imageY = m_pIdle->SetPosImageY();
	// 攻撃範囲を指定　アイドル状態なので位置を初期化
	m_attackSizeLeft = 0;
	m_attackSizeTop = 0;
	m_attackSizeRight = 0;
	m_attackSizeBottom = 0;

	// 攻撃力
	m_damage = 0;
}

// 走りアニメーション
void Elf::AnimRun()
{
	m_pRun->Update();
	// 画像読み込み位置
	m_imageX = m_pRun->SetPosImageX();
	m_imageY = m_pRun->SetPosImageY();
	// 攻撃範囲を指定　走り状態なので位置を初期化
	m_attackSizeLeft = 0;
	m_attackSizeTop = 0;
	m_attackSizeRight = 0;
	m_attackSizeBottom = 0;

	// 攻撃力
	m_damage = 0;
}

// ジャンプアニメーション
void Elf::AnimJump()
{
	m_pJump->Update();
	// 画像読み込み位置
	m_imageX = m_pJump->SetPosImageX();
	m_imageY = m_pJump->SetPosImageY();

	// 攻撃力
	m_damage = 0;
}

// パンチアニメーション
void Elf::AnimAttackPunch()
{
	m_pPunch->Update();
	// 画像読み込み位置
	m_imageX = m_pPunch->SetPosImageX();
	m_imageY = m_pPunch->SetPosImageY();

	// 攻撃範囲を指定
	// 向いている方向で範囲を決定
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

	// 攻撃力
	m_damage = 1;
}

// 通常ショットアニメーション
void Elf::AnimAttackNormalShot()
{
	m_pShot->Update();
	// 画像読み込み位置
	m_imageX = m_pShot->SetPosImageX();
	m_imageY = m_pShot->SetPosImageY();

	// 攻撃力
	m_damage = 5;
}

// チャージショットアニメーション
void Elf::AnimAttackChargeShit()
{
	m_pChargeShot->Update();
	// 画像読み込み位置
	m_imageX = m_pChargeShot->SetPosImageX();
	m_imageY = m_pChargeShot->SetPosImageY();
	// 攻撃範囲を指定
	// 向いている方向で範囲を決定
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

	// 攻撃力
	m_damage = 20;
}

// 上攻撃アニメーション
void Elf::AnimAttackUpShit()
{
	m_pUp->Update();
	// 画像読み込み位置
	m_imageX = m_pUp->SetPosImageX();
	m_imageY = m_pUp->SetPosImageY();
	// 攻撃範囲を指定
	m_attackSizeLeft = -130;
	m_attackSizeTop = -130;
	m_attackSizeRight = static_cast<int>(m_attackSizeLeft) + 280;
	m_attackSizeBottom = static_cast<int>(m_attackSizeTop) + 180;

	// 攻撃力
	m_damage = 5;
}
