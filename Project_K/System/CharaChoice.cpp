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
	updateChara1(); //パッド1のアップデート
	updateChara2(); //パッド2のアップデート
}

void CharaChoice::Draw()
{
	if (m_decision1) //キャラクターが決定されたとき赤文字で表示
	{
		DrawFormatString(300, 400, 0xff0000,
			"%d", m_charaNumber1);
	}
	else //決定されてないとき白文字で表示
	{
		DrawFormatString(300, 400, 0xffffff,
			"%d", m_charaNumber1);
	}

	if (m_decision2)//キャラクターが決定されたとき赤文字で表示
	{
		DrawFormatString(600, 400, 0xff0000,
			"%d", m_charaNumber2);
	}
	else //決定されてないとき白文字で表示
	{
		DrawFormatString(600, 400, 0xffffff,
			"%d", m_charaNumber2);
	}
}

void CharaChoice::updateChara1()
{
	//キャラクターが決定されていてかつ2ボタンを押された場合
	if (Pad::IsTrigger(PAD_INPUT_2, 1) && m_decision1)
	{
		m_decision1 = false;
		return;
	}

	if (m_decision1) return; //キャラクターが決定されていたら処理をしない

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
	//キャラクターが決定されていてかつ2ボタンを押された場合
	if (Pad::IsTrigger(PAD_INPUT_2, 2) && m_decision2)
	{
		m_decision2 = false;
		return;
	}
	if (m_decision2) return;//キャラクターが決定されていたら処理をしない

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
