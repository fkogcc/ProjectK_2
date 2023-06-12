#include "LogoRotation.h"
#include "Util/Pad.h"
#include "Util/DrawFunctions.h"

#include <DxLib.h>

LogoRotation::LogoRotation():
	m_hLogo  (-1),
	m_pos    (0.0, 0.0),
	m_logoPos(0.0, 0.0)
{
	m_pos.x = 500.0f;
	m_pos.y = 500.0f;

	m_logoPos.x = m_pos.x + 300.0f;
	m_logoPos.y = m_pos.y + 300.0f;

	m_isTrans = false;
}

LogoRotation::~LogoRotation()
{
	DeleteGraph(m_hLogo);
}

void LogoRotation::Init()
{
	m_hLogo = my::MyLoadGraph("Data/Image/Logo/logo.png");
}

void LogoRotation::Update()
{
	// 回転スピード
	const float transSpeed = 0.3f + 0.7f;
	// 回転
	m_pos.x     += transSpeed;
	m_logoPos.x -= transSpeed;
	
	

	if (m_pos.x == m_logoPos.x)
	{
		printfDx("半分\n");
		m_pos.x = 500.0f/2.0f;
		
		m_logoPos.x = 500.0f + 300.0f/2.0f;
	}

	if (Pad::IsPress(PAD_INPUT_3, 1))
	{
		m_pos.x = 500.0f;
		m_pos.y = 500.0f;

		m_logoPos.x = m_pos.x + 300.0f;
		m_logoPos.y = m_pos.y + 300.0f;
	}
	

}

void LogoRotation::Draw()
{
	my::MyDrawExtendGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), 
		static_cast<int>(m_logoPos.x), static_cast<int>(m_logoPos.y), m_hLogo, true);

	DrawFormatString(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), 0x000000, 
		"m_pos = %f", static_cast<int>(m_pos.x));
	DrawFormatString(static_cast<int>(m_logoPos.x), static_cast<int>(m_logoPos.y),
		0x000000, "m_logoPos = %f", static_cast<int>(m_logoPos.x));
}
