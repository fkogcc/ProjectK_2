#include "Kinnikurou.h"
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
	Pad::update();

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
		if (Pad::isPress(PAD_INPUT_RIGHT))
		{
			m_moveType = 1;
			//ImgposInit();
			m_pos.x += 10;
			m_charDirection = false;
			m_charRun = true;
		}
		if (Pad::isPress(PAD_INPUT_LEFT))
		{
			m_moveType = 1;
			//ImgposInit();
			m_pos.x -= 10;
			m_charDirection = true;
			m_charRun = true;
		}
		if (Pad::isTrigger(PAD_INPUT_1))
		{
			m_moveType = 3;// �W���u�U�����
			ImgposInit();
			m_motionCount = 30;
		}
		if (Pad::isTrigger(PAD_INPUT_2))
		{
			m_moveType = 4;// �}�b�X���U�����
			ImgposInit();
			m_motionCount = 70;
		}
		if (Pad::isTrigger(PAD_INPUT_3))
		{
			m_moveType = 5;// �}�b�X���U�����
			ImgposInit();
			m_motionCount = 40;
		}
		if (Pad::isTrigger(PAD_INPUT_4))
		{
			m_moveType = 6;// �}�b�X���U�����
			ImgposInit();
			m_motionCount = 40;
		}

	}

	if (!Pad::isPress(PAD_INPUT_RIGHT) || !Pad::isPress(PAD_INPUT_LEFT))
	{
		m_attackFlag = false;
		m_charRun = false;
		//m_initCount = 0;
	}

	if ((Pad::isRelase(PAD_INPUT_RIGHT) || Pad::isRelase(PAD_INPUT_LEFT)) && m_motionCount == 0)
	{
		m_attackFlag = false;
		ImgposInit();
	}

	if (m_charRun) printfDx("�ړ����\n");

	// �A�C�h�����
	if (m_moveType == static_cast<int>(moveType::Idol))
	{
		m_attackFlag = false;

		m_pIdle->Update(m_imgPosX, m_imgPosY);
		printfDx("�A�C�h�����\n");
	}
	if (m_moveType == static_cast<int>(moveType::Attack1))
	{
		m_attackFlag = true;

		// �����蔻��
		m_sizeLeftAttack = -100;
		m_sizeTopAttack = 0;
		m_sizeRightAttack = 100;
		m_sizeBottomAttack = 100;

		m_pJab->Update(m_imgPosX, m_imgPosY);
		printfDx("�U���P\n");
	}
	if (m_moveType == static_cast<int>(moveType::Attack2))
	{
		m_attackFlag = true;

		// �����蔻��
		m_sizeLeftAttack = -100;
		m_sizeTopAttack = 0;
		m_sizeRightAttack = 100;
		m_sizeBottomAttack = 100;

		m_pMuscle->Update(m_imgPosX, m_imgPosY);
		printfDx("�U���Q\n");
	}
	if (m_moveType == static_cast<int>(moveType::Attack3))
	{
		m_attackFlag = true;

		// �����蔻��
		m_sizeLeftAttack = -100;
		m_sizeTopAttack = 0;
		m_sizeRightAttack = 100;
		m_sizeBottomAttack = 100;

		m_pUpper->Update(m_imgPosX, m_imgPosY);
		printfDx("�U���R\n");
	}
	if (m_moveType == static_cast<int>(moveType::Attack4))
	{
		m_attackFlag = true;

		// �����蔻��
		m_sizeLeftAttack = -100;
		m_sizeTopAttack = 0;
		m_sizeRightAttack = 100;
		m_sizeBottomAttack = 100;

		m_pMizo->Update(m_imgPosX, m_imgPosY);
		printfDx("�U���S\n");
	}
	if (m_moveType == static_cast<int>(moveType::Run))
	{
		m_attackFlag = false;
		m_pRun->Update(m_imgPosX, m_imgPosY);
		printfDx("�ړ�\n");
	}

}

void Kinnikurou::Draw()
{
	// �A�C�h�����
	if (m_moveType == static_cast<int>(moveType::Idol))
	{
		m_charHandle = m_idleHandle;
		m_imgWidth = 18;
		m_imgHeight = 23;
	}
	// �W���u�U�����
	else if (m_moveType == static_cast<int>(moveType::Attack1))
	{
		m_charHandle = m_jabHandle;
		m_imgWidth = 56 / 2;
		m_imgHeight = 23;
	}
	// �}�b�X���U�����
	else if (m_moveType == static_cast<int>(moveType::Attack2))
	{
		m_charHandle = m_muscleHandle;
		m_imgWidth = 27;
		m_imgHeight = 24;
	}
	// �A�b�p�[�U�����
	else if (m_moveType == static_cast<int>(moveType::Attack3))
	{
		m_charHandle = m_UpperHandle;
		m_imgWidth = 27;
		m_imgHeight = 24;
	}
	// �݂������U�����
	else if (m_moveType == static_cast<int>(moveType::Attack4))
	{
		m_charHandle = m_MizoHandle;
		m_imgWidth = 27;
		m_imgHeight = 24;
	}
	// �ړ����
	else if (m_moveType == static_cast<int>(moveType::Run))
	{
		m_charHandle = m_RunHandle;
		m_imgWidth = 54 / 3;
		m_imgHeight = 72 / 3;
	}


	// �L�����N�^�[�̕`��
	my::MyDrawRectRotaGraph(m_pos.x, m_pos.y,
		m_imgPosX * m_imgWidth, m_imgPosY * m_imgHeight,
		m_imgWidth, m_imgHeight,
		5.0f, 0.0f,
		m_charHandle,
		true, m_charDirection);

	if (m_attackFlag)
	{
		DrawBox(m_pos.x + m_sizeLeftAttack, m_pos.y + m_sizeTopAttack,
			m_pos.x + m_sizeRightAttack, m_pos.y + m_sizeBottomAttack,
			0xff0000, false);
	}
}

void Kinnikurou::ImgposInit()
{
	m_imgPosX = 0;
	m_imgPosY = 0;
}
