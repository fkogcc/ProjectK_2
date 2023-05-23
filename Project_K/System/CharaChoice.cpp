#include "CharaChoice.h"
#include"../Util/Pad.h"
#include"../Util/Pad2.h"

CharaChoice::CharaChoice() : 
	m_choiceNum1(0),
	m_choiceNum2(0),
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
	GetChackChara1();
	GetChackChara2();
}

void CharaChoice::Draw()
{
	DrawString(300, 400, "%d", m_charaNumber1);
	DrawString(600, 400, "%d", m_charaNumber2);
}

void CharaChoice::updateChara1()
{
	if (m_Decision1) return;

	if (Pad::IsTrigger(PAD_INPUT_1))
	{
		m_Decision1 = true;
		return;
	}
	if (Pad::IsTrigger(PAD_INPUT_RIGHT))
	{
		if (m_charaNumber1 >= 4)
		{
			m_charaNumber1 = 4;
			return;
		}
		m_charaNumber1++;
	}

	if (Pad::IsTrigger(PAD_INPUT_LEFT))
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

	if (Pad2::IsTrigger(PAD_INPUT_1))
	{
		m_Decision2 = true;
		return;
	}
	if (Pad2::IsTrigger(PAD_INPUT_RIGHT))
	{
		if (m_charaNumber2 >= 4)
		{
			m_charaNumber2 = 4;
			return;
		}
		m_charaNumber2++;
	}

	if (Pad2::IsTrigger(PAD_INPUT_LEFT))
	{
		if (m_charaNumber2 <= 0)
		{
			m_charaNumber2 = 0;
			return;
		}
		m_charaNumber2--;
	}
}
