#include "CharaChoice.h"
#include"../Util/Pad.h"

CharaChoice::CharaChoice() :
	m_charaNumber1(0),
	m_charaNumber2(0),
	m_decision1(false),
	m_decision2(false)
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
	updateChara1(); //�p�b�h1�̃A�b�v�f�[�g
	updateChara2(); //�p�b�h2�̃A�b�v�f�[�g
}

void CharaChoice::Draw()
{
	if (m_decision1) //�L�����N�^�[�����肳�ꂽ�Ƃ��ԕ����ŕ\��
	{
		DrawFormatString(300, 400, 0xff0000,
			"%d", m_charaNumber1);
	}
	else //���肳��ĂȂ��Ƃ��������ŕ\��
	{
		DrawFormatString(300, 400, 0xffffff,
			"%d", m_charaNumber1);
	}

	if (m_decision2)//�L�����N�^�[�����肳�ꂽ�Ƃ��ԕ����ŕ\��
	{
		DrawFormatString(600, 400, 0xff0000,
			"%d", m_charaNumber2);
	}
	else //���肳��ĂȂ��Ƃ��������ŕ\��
	{
		DrawFormatString(600, 400, 0xffffff,
			"%d", m_charaNumber2);
	}
}

void CharaChoice::updateChara1()
{
	//�L�����N�^�[�����肳��Ă��Ă���2�{�^���������ꂽ�ꍇ
	if (Pad::IsTrigger(PAD_INPUT_2, 1) && m_decision1)
	{
		m_decision1 = false;
		return;
	}

	if (m_decision1) return; //�L�����N�^�[�����肳��Ă����珈�������Ȃ�

	if (Pad::IsTrigger(PAD_INPUT_1, 1))
	{
		m_decision1 = true;
		return;
	}
	if (Pad::IsTrigger(PAD_INPUT_DOWN, 1))
	{
		if (m_charaNumber1 >= 3)
		{
			m_charaNumber1 = 0;
			return;
		}
		m_charaNumber1++;
	}

	if (Pad::IsTrigger(PAD_INPUT_UP, 1))
	{
		if (m_charaNumber1 <= 0)
		{
			m_charaNumber1 = 3;
			return;
		}
		m_charaNumber1--;
	}
}

void CharaChoice::updateChara2()
{
	//�L�����N�^�[�����肳��Ă��Ă���2�{�^���������ꂽ�ꍇ
	if (Pad::IsTrigger(PAD_INPUT_2, 2) && m_decision2)
	{
		m_decision2 = false;
		return;
	}
	if (m_decision2) return;//�L�����N�^�[�����肳��Ă����珈�������Ȃ�

	if (Pad::IsTrigger(PAD_INPUT_1, 2))
	{
		m_decision2 = true;
		return;
	}
	if (Pad::IsTrigger(PAD_INPUT_DOWN, 2))
	{
		if (m_charaNumber2 >= 3)
		{
			m_charaNumber2 = 0;
			return;
		}
		m_charaNumber2++;
	}

	if (Pad::IsTrigger(PAD_INPUT_UP, 2))
	{
		if (m_charaNumber2 <= 0)
		{
			m_charaNumber2 = 3;
			return;
		}
		m_charaNumber2--;
	}
}
