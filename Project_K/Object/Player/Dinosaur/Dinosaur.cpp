#include "Dinosaur.h"
#include "../../../condition.h"

Dinosaur::Dinosaur()
{
	m_hp = 150;

}

Dinosaur::~Dinosaur()
{
}

void Dinosaur::Init()
{
}

void Dinosaur::End()
{
}

void Dinosaur::Update()
{
	Pad::update();

	m_moveType = static_cast<int>(moveType::Idol);// アイドル状態

	if (Pad::isPress(PAD_INPUT_RIGHT))m_pos.x += 10;
	if (Pad::isPress(PAD_INPUT_LEFT))m_pos.x -= 10;
	if (Pad::isPress(PAD_INPUT_UP))m_pos.y -= 10;
	if (Pad::isPress(PAD_INPUT_DOWN))m_pos.y += 10;

	if (Pad::isTrigger(PAD_INPUT_1))// XBOX A
	{
		m_moveType = static_cast<int>(moveType::Attack2);;// 攻撃
	}
	if (Pad::isTrigger(PAD_INPUT_2))// XBOX B
	{
		m_moveType = static_cast<int>(moveType::Attack1);;// 攻撃
	}
	if (Pad::isTrigger(PAD_INPUT_3) || (Pad::isTrigger(PAD_INPUT_4)))// XBOX X or Y
	{
		//　ジャンプ
	}
	if (Pad::isTrigger(XINPUT_BUTTON_LEFT_SHOULDER) || (Pad::isTrigger(PAD_INPUT_R)))// XBOX X or Y
	{
		//　ジャンプ
		printfDx("aaaa");
	}
	if (Pad::isTrigger(PAD_INPUT_1) && (Pad::isTrigger(PAD_INPUT_RIGHT)) ||// XBOX A && RIGHT
		Pad::isTrigger(PAD_INPUT_1) && (Pad::isTrigger(PAD_INPUT_LEFT)))   // XBOX A && LEFT
	{
		m_moveType = static_cast<int>(moveType::Attack3);;// 攻撃
	}

	m_posLeft = m_pos.x - 50;// プレイヤーのサイズ
	m_posTop = m_pos.y + 90;
	m_posRight = m_posLeft + 100;
	m_posBottom = m_posTop + 195;
}

void Dinosaur::Draw()
{
}
