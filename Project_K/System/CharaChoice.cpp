#include "CharaChoice.h"
#include"../Util/Pad.h"

CharaChoice::CharaChoice() : 
	m_charaNumber1(0),
	m_charaNumber2(0),
	m_Decision1(false),
	m_Decision2(false)
{
}

CharaChoice::~CharaChoice()
{
}

void CharaChoice::Init()
{

}

void CharaChoice::Update()
{
	updateChara1();
	updateChara2();
}

void CharaChoice::Draw()
{
	if (m_Decision1)
	{
		DrawFormatString(300, 400, 0xff0000,
			"%d", m_charaNumber1);
	}
	else
	{
		DrawFormatString(300, 400, 0xffffff,
				"%d", m_charaNumber1);
	}

	if (m_Decision2)
	{
		DrawFormatString(600, 400, 0xff0000,
			"%d", m_charaNumber2);
	}
	else
	{
		DrawFormatString(600, 400, 0xffffff,
			"%d", m_charaNumber2);
	}
}

void CharaChoice::updateChara1()
{
	if (m_Decision1) return;

	if (Pad::IsTrigger(PAD_INPUT_1,1))
	{
		m_Decision1 = true;
		return;
	}
	if (Pad::IsTrigger(PAD_INPUT_RIGHT,1))
	{
		if (m_charaNumber1 >= 3)
		{
			m_charaNumber1 = 3;
			return;
		}
		m_charaNumber1++;
	}

	if (Pad::IsTrigger(PAD_INPUT_LEFT,1))
	{
		if (m_charaNumber1 <= 0)
		{
			m_charaNumber1 = 0;
			return;
		}
		m_charaNumber1--;
	}
}

void CharaChoice::updateChara2()
{
	if (m_Decision2) return;

	if (Pad::IsTrigger(PAD_INPUT_1, 2))
	{
		m_Decision2 = true;
		return;
	}
	if (Pad::IsTrigger(PAD_INPUT_RIGHT, 2))
	{
		if (m_charaNumber2 >= 3)
		{
			m_charaNumber2 = 3;
			return;
		}
		m_charaNumber2++;
	}

	if (Pad::IsTrigger(PAD_INPUT_LEFT, 2))
	{
		if (m_charaNumber2 <= 0)
		{
			m_charaNumber2 = 0;
			return;
		}
		m_charaNumber2--;
	}
}
