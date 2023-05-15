﻿#include "Kinnikurou.h"
#include "../../condition.h"
#include "../../Util/DrawFunctions.h"
#include "KinnikuIdle.h"
#include "KinnikurouJab.h"
#include "KinnikuMuscle.h"
#include "KinnikuUpper.h"
#include "KinnikuMizo.h"
#include "KinnikuRun.h"

namespace
{
	const char* const kIdle = "Data/Image/Player/Kinnikurou/Idle.png";
	const char* const kJab = "Data/Image/Player/Kinnikurou/AttackNeutral.png";
	const char* const kMuscle = "Data/Image/Player/Kinnikurou/AttackSide.png";
	const char* const kUpper = "Data/Image/Player/Kinnikurou/AttackUp.png";
	const char* const kMizo = "Data/Image/Player/Kinnikurou/AttackDown.png";
	const char* const kRun = "Data/Image/Player/Kinnikurou/Run.png";
}

Kinnikurou::Kinnikurou() :
	m_pushBottom(false),
	m_charHandle(-1),
	m_idleHandle(-1),
	m_jabHandle(-1),
	m_muscleHandle(-1),
	m_UpperHandle(-1),
	m_MizoHandle(-1),
	m_RunHandle(-1),
	m_imgPosX(0),
	m_imgPosY(0),
	m_imgWidth(0),
	m_imgHeight(0),
	m_motionCount(0),
	m_initCount(0),
	m_charDirection(false),
	m_charRun(false)
{
	m_pIdle = new KinnikuIdle;
	m_pJab = new KinnikurouJab;
	m_pMuscle = new KinnikuMuscle;
	m_pUpper = new KinnikuUpper;
	m_pMizo = new KinnikuMizo;
	m_pRun = new KinnikuRun;
}

Kinnikurou::~Kinnikurou()
{
	delete m_pIdle;
	m_pIdle = nullptr;
	delete m_pJab;
	m_pJab = nullptr;
	delete m_pMuscle;
	m_pMuscle = nullptr;
	delete m_pUpper;
	m_pUpper = nullptr;
	delete m_pMizo;
	m_pMizo = nullptr;
	delete m_pRun;
	m_pRun = nullptr;
}

void Kinnikurou::Init()
{
	m_idleHandle = my::MyLoadGraph(kIdle);
	m_jabHandle = my::MyLoadGraph(kJab);
	m_muscleHandle = my::MyLoadGraph(kMuscle);
	m_UpperHandle = my::MyLoadGraph(kUpper);
	m_MizoHandle = my::MyLoadGraph(kMizo);
	m_RunHandle = my::MyLoadGraph(kRun);

	m_pos.x = 200;
	m_pos.y = 600;

	m_imgPosX = 0;
	m_imgPosY = 0;

	m_sizeLeft = -50;
	m_sizeTop = -50;
	m_sizeRight = 50;
	m_sizeBottom = 50;
}

void Kinnikurou::End()
{
	my::MyDeleteGraph(m_idleHandle);
	my::MyDeleteGraph(m_jabHandle);
	my::MyDeleteGraph(m_muscleHandle);
	my::MyDeleteGraph(m_UpperHandle);
	my::MyDeleteGraph(m_MizoHandle);
	my::MyDeleteGraph(m_RunHandle);
}

void Kinnikurou::Update()
{

	if (m_motionCount != 0)
	{
		m_motionCount--;
		if (m_motionCount <= 0) m_motionCount = 0;
	}

	if (m_motionCount == 0 && !m_charRun)
	{

		m_moveType = 0;
	}

	if (m_moveType == 0)
	{
		if (m_initCount <= 0)
		{
			ImgposInit();
			m_initCount++;
		}
	}

	if (m_motionCount == 0)
	{
		if (Pad2::IsPress(PAD_INPUT_RIGHT))
		{
			m_moveType = 1;
			//ImgposInit();
			m_pos.x += 10;
			m_charDirection = false;
			m_charRun = true;
		}
		if (Pad2::IsPress(PAD_INPUT_LEFT))
		{
			m_moveType = 1;
			//ImgposInit();
			m_pos.x -= 10;
			m_charDirection = true;
			m_charRun = true;
		}
		if (Pad2::IsTrigger(PAD_INPUT_1))
		{
			m_moveType = 3;// ジャブ攻撃状態
			ImgposInit();
			m_motionCount = 3 * 3;
		}
		if (Pad2::IsTrigger(PAD_INPUT_2))
		{
			m_moveType = 4;// マッスル攻撃状態
			ImgposInit();
			m_motionCount = 70;
		}
		if (Pad2::IsTrigger(PAD_INPUT_3))
		{
			m_moveType = 5;// アッパー攻撃状態
			ImgposInit();
			m_motionCount = 40;
		}
		if (Pad2::IsTrigger(PAD_INPUT_4))
		{
			m_moveType = 6;// みぞおち攻撃状態
			ImgposInit();
			m_motionCount = 40;
		}

	}

	if (!Pad2::IsPress(PAD_INPUT_RIGHT) || !Pad2::IsPress(PAD_INPUT_LEFT))
	{
		m_attackFlag = false;
		m_charRun = false;
	}

	if ((Pad2::IsRelase(PAD_INPUT_RIGHT) || Pad2::IsRelase(PAD_INPUT_LEFT)) && m_motionCount == 0)
	{
		m_attackFlag = false;
		ImgposInit();
	}


	// アイドル状態
	if (m_moveType == static_cast<int>(moveType::Idol))
	{
		m_attackFlag = false;

		m_pIdle->Update(m_imgPosX, m_imgPosY);
	}
	if (m_moveType == static_cast<int>(moveType::Attack1))
	{
		m_attackFlag = true;

		if (!m_charDirection)
		{
			// 当たり判定
			m_sizeLeftAttack = 30;
			m_sizeTopAttack = -30;
			m_sizeRightAttack = 90;
			m_sizeBottomAttack = 10;
		}
		else if (m_charDirection)
		{
			// 当たり判定
			m_sizeLeftAttack = -30;
			m_sizeTopAttack = -30;
			m_sizeRightAttack = -90;
			m_sizeBottomAttack = 10;
		}

		m_pJab->Update(m_imgPosX, m_imgPosY);
	}
	if (m_moveType == static_cast<int>(moveType::Attack2))
	{
		m_attackFlag = true;

		if (!m_charDirection)
		{
			// 当たり判定
			m_sizeLeftAttack = -200;
			m_sizeTopAttack = -200;
			m_sizeRightAttack = 200;
			m_sizeBottomAttack = 200;
		}
		else if (m_charDirection)
		{
			m_sizeLeftAttack = -200;
			m_sizeTopAttack = -200;
			m_sizeRightAttack = 200;
			m_sizeBottomAttack = 200;
		}
		

		m_pMuscle->Update(m_imgPosX, m_imgPosY);
	}
	if (m_moveType == static_cast<int>(moveType::Attack3))
	{
		m_attackFlag = true;

		if (!m_charDirection)
		{
			// 当たり判定
			m_sizeLeftAttack = 30;
			m_sizeTopAttack = -80;
			m_sizeRightAttack = 100;
			m_sizeBottomAttack = 80;
		}
		else if (m_charDirection)
		{
			m_sizeLeftAttack = -30;
			m_sizeTopAttack = -80;
			m_sizeRightAttack = -100;
			m_sizeBottomAttack = 80;
		}

		

		m_pUpper->Update(m_imgPosX, m_imgPosY);
	}
	if (m_moveType == static_cast<int>(moveType::Attack4))
	{
		m_attackFlag = true;

		if (!m_charDirection)
		{
			// 当たり判定
			m_sizeLeftAttack = 30;
			m_sizeTopAttack = -10;
			m_sizeRightAttack = 80;
			m_sizeBottomAttack = 10;
		}
		else if (m_charDirection)
		{
			m_sizeLeftAttack = -30;
			m_sizeTopAttack = -10;
			m_sizeRightAttack = -80;
			m_sizeBottomAttack = 10;
		}

		

		m_pMizo->Update(m_imgPosX, m_imgPosY);
	}
	if (m_moveType == static_cast<int>(moveType::Run))
	{
		m_attackFlag = false;
		m_pRun->Update(m_imgPosX, m_imgPosY);
	}

}

void Kinnikurou::Draw()
{
	// アイドル状態
	if (m_moveType == static_cast<int>(moveType::Idol))
	{
		m_charHandle = m_idleHandle;
		m_imgWidth = 18;
		m_imgHeight = 23;
	}
	// ジャブ攻撃状態
	else if (m_moveType == static_cast<int>(moveType::Attack1))
	{
		m_charHandle = m_jabHandle;
		m_imgWidth = 56 / 2;
		m_imgHeight = 23;
	}
	// マッスル攻撃状態
	else if (m_moveType == static_cast<int>(moveType::Attack2))
	{
		m_charHandle = m_muscleHandle;
		m_imgWidth = 27;
		m_imgHeight = 24;
	}
	// アッパー攻撃状態
	else if (m_moveType == static_cast<int>(moveType::Attack3))
	{
		m_charHandle = m_UpperHandle;
		m_imgWidth = 27;
		m_imgHeight = 24;
	}
	// みぞおち攻撃状態
	else if (m_moveType == static_cast<int>(moveType::Attack4))
	{
		m_charHandle = m_MizoHandle;
		m_imgWidth = 27;
		m_imgHeight = 24;
	}
	// 移動状態
	else if (m_moveType == static_cast<int>(moveType::Run))
	{
		m_charHandle = m_RunHandle;
		m_imgWidth = 54 / 3;
		m_imgHeight = 72 / 3;
	}


	// キャラクターの描画
	my::MyDrawRectRotaGraph(static_cast<int> (m_pos.x), static_cast<int> (m_pos.y),
		m_imgPosX * m_imgWidth, m_imgPosY * m_imgHeight,
		m_imgWidth, m_imgHeight,
		5.0f, 0.0f,
		m_charHandle,
		true, m_charDirection);

	if (m_attackFlag)
	{
		DrawBox(static_cast<int> (m_pos.x) + m_sizeLeftAttack, 
			static_cast<int> (m_pos.y) + m_sizeTopAttack,
			static_cast<int> (m_pos.x) + m_sizeRightAttack, 
			static_cast<int> (m_pos.y) + m_sizeBottomAttack,
			0xff0000, false);
	}

	DrawBox(static_cast<int> (m_pos.x) + m_sizeLeft, 
		static_cast<int> (m_pos.y) + m_sizeTop,
		static_cast<int> (m_pos.x) + m_sizeRight, 
		static_cast<int> (m_pos.y) + m_sizeBottom,
		0xffffff, false);
}

void Kinnikurou::ImgposInit()
{
	m_imgPosX = 0;
	m_imgPosY = 0;
}
