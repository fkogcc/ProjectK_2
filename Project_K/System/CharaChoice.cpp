#include "CharaChoice.h"
#include"../Util/Pad.h"
#include"../Util/Pad2.h"

CharaChoice::CharaChoice() : 
	m_choiceNum1(0),
	m_choiceNum2(0)
{
	for (int i = 0; i < kCharaNum; i++)
	{
		m_chackChara1[i] = false;
		m_chackChara2[i] = false;
	}
}

CharaChoice::~CharaChoice()
{
}

void CharaChoice::Init()
{

}

void CharaChoice::Update()
{

}

void CharaChoice::Draw()
{

}

void CharaChoice::updateChara1()
{
//	if(Pad::IsTrigger())
}

void CharaChoice::updateChara2()
{

}
