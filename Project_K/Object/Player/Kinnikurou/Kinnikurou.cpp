#include "Kinnikurou.h"
#include "../../condition.h"
#include "../../Util/DrawFunctions.h"
#include "KinnikuIdle.h"
#include "KinnikurouJab.h"
#include "KinnikuMuscle.h"
#include "KinnikuUpper.h"
#include "KinnikuMizo.h"

namespace
{
	const char* const kIdle = "Data/Image/Player/Kinnikurou/Idle";
	const char* const kJab = "Data/Image/Player/Kinnikurou/AttackNeutral.png";
	const char* const kMuscle = "Data/Image/Player/Kinnikurou/AttackSide.png";
	const char* const kUpper = "Data/Image/Player/Kinnikurou/AttackUp.png";
	const char* const kMizo = "Data/Image/Player/Kinnikurou/AttackDown.png";
}

Kinnikurou::Kinnikurou() :
	m_pushBottom(false),
	m_charHandle(-1),
	m_idleHandle(-1),
	m_jabHandle(-1),
	m_muscleHandle(-1),
	m_UpperHandle(-1),
	m_MizoHandle(-1),
	m_drawPosX(0),
	m_drawPosY(0),
	m_imgPosX(0),
	m_imgPosY(0),
	m_imgWidth(0),
	m_imgHeight(0)
{
	m_pIdle = new KinnikuIdle;
	m_pJab = new KinnikurouJab;
	m_pMuscle = new KinnikuMuscle;
	m_pUpper = new KinnikuUpper;
	m_pMizo = new KinnikuMizo;
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
}

void Kinnikurou::Init()
{
	m_idleHandle = my::MyLoadGraph(kIdle);
	m_jabHandle = my::MyLoadGraph(kJab);
	m_muscleHandle = my::MyLoadGraph(kMuscle);

	m_drawPosX = 200;
	m_drawPosY = 900;

	m_imgPosX = 0;
	m_imgPosY = 0;
}

void Kinnikurou::End()
{
	my::MyDeleteGraph(m_idleHandle);
	my::MyDeleteGraph(m_jabHandle);
	my::MyDeleteGraph(m_muscleHandle);
}

void Kinnikurou::Update()
{
	Pad::update();

	//if (!m_pushBottom) m_moveType = static_cast<int>(moveType::Idol);// アイドル状態
	if (Pad::isTrigger(PAD_INPUT_1)) m_moveType = static_cast<int>(moveType::Attack1);// ジャブ攻撃状態
	if (Pad::isTrigger(PAD_INPUT_2)) m_moveType = static_cast<int>(moveType::Attack2);// マッスル攻撃状態
	if (Pad::isTrigger(PAD_INPUT_3)) m_moveType = static_cast<int>(moveType::Attack3);// マッスル攻撃状態
	if (Pad::isTrigger(PAD_INPUT_4)) m_moveType = static_cast<int>(moveType::Attack4);// マッスル攻撃状態

	if (Pad::isPress(PAD_INPUT_RIGHT))m_pos.x += 10;
	if (Pad::isPress(PAD_INPUT_LEFT))m_pos.x -= 10;

	// アイドル状態
	if (m_moveType == static_cast<int>(moveType::Idol)) m_pIdle->Update(m_imgPosX, m_imgPosY);
	if (m_moveType == static_cast<int>(moveType::Attack1)) m_pJab->Update(m_imgPosX, m_imgPosY);
	if (m_moveType == static_cast<int>(moveType::Attack2)) m_pMuscle->Update(m_imgPosX, m_imgPosY);
	if (m_moveType == static_cast<int>(moveType::Attack3)) m_pUpper->Update(m_imgPosX, m_imgPosY);
	if (m_moveType == static_cast<int>(moveType::Attack4)) m_pMizo->Update(m_imgPosX, m_imgPosY);

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
		m_imgWidth = 28;
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


	// キャラクターの描画
	my::MyDrawRectRotaGraph(m_drawPosX, m_drawPosY,
		m_imgPosX * m_imgWidth, m_imgPosY * m_imgHeight,
		18, 23,
		3.0f, 0.0f,
		m_charHandle,
		true, false);
}
