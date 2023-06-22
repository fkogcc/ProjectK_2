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
	updateChara1(); //�p�b�h1�̃A�b�v�f�[�g
	updateChara2(); //�p�b�h2�̃A�b�v�f�[�g
}

void CharaChoice::Draw()
{
	if (m_Decision1) //�L�����N�^�[�����肳�ꂽ�Ƃ��ԕ����ŕ\��
	{
		DrawDecision1P(0xff0000);
	}
	else //���肳��ĂȂ��Ƃ��������ŕ\��
	{
		DrawDecision1P(0xffffff);
	}

	if (m_Decision2)//�L�����N�^�[�����肳�ꂽ�Ƃ��ԕ����ŕ\��
	{
		DrawDecision2P(0xff0000);
	}
	else //���肳��ĂȂ��Ƃ��������ŕ\��
	{
		DrawDecision2P(0xffffff);
	}
}


void CharaChoice::updateChara1()
{
	//�L�����N�^�[�����肳��Ă��Ă���2�{�^���������ꂽ�ꍇ
	UpdateChara(1, m_charaNumber1, m_Decision1);
}

void CharaChoice::updateChara2()
{
	//�L�����N�^�[�����肳��Ă��Ă���2�{�^���������ꂽ�ꍇ
	UpdateChara(2, m_charaNumber2, m_Decision2);
}

void CharaChoice::UpdateChara(int padNum, int& charaNum, bool& decision)
{
	//�L�����N�^�[�����肳��Ă��Ă���2�{�^���������ꂽ�ꍇ
	if (Pad::IsTrigger(PAD_INPUT_1, padNum) && decision)
	{
		decision = false;
		return;
	}

	if (decision) return; //�L�����N�^�[�����肳��Ă����珈�������Ȃ�

	if (Pad::IsTrigger(PAD_INPUT_1, padNum) && !decision)
	{
		decision = true;
		return;
	}
	if (Pad::IsTrigger(PAD_INPUT_DOWN, padNum))
	{
		if (charaNum >= 3)
		{
			charaNum = 0;
			return;
		}
		charaNum++;
	}

	if (Pad::IsTrigger(PAD_INPUT_UP, padNum))
	{
		if (charaNum <= 0)
		{
			charaNum = 3;
			return;
		}
		charaNum--;
	}
}

void CharaChoice::DrawDecision1P(int color)
{
	DrawFormatString(300, 400, color,
		"%d", m_charaNumber1);
}

void CharaChoice::DrawDecision2P(int color)
{
	DrawFormatString(600, 400, color,
		"%d", m_charaNumber2);
}