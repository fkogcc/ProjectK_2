#include "Elf.h"
#include "../../../Util/DrawFunctions.h"
#include "../../condition.h"
#include "ElfIdol.h"

namespace
{
	const char* const kFilmName = "../../Data/Image/Player/Elf/Elf.png";
}

Elf::Elf():
	m_handle(0),
	m_pIdle(nullptr)
{
	m_pIdle = new ElfIdol;
}

Elf::~Elf()
{
}

void Elf::Init()
{
	m_handle = my::MyLoadGraph(kFilmName);
}

void Elf::End()
{
	my::MyDeleteGraph(m_handle);
}

void Elf::Update()
{
	Pad::update();

	m_pIdle->Update();

	m_imageX = m_pIdle->SetPosImageX();
	m_imageY = m_pIdle->SetPosImageY();

	m_moveType = static_cast<int>(moveType::Idol);// アイドル状態

	if (Pad::isPress(PAD_INPUT_RIGHT))m_pos.x += 10;
	if (Pad::isPress(PAD_INPUT_LEFT ))m_pos.x -= 10;
	if (Pad::isPress(PAD_INPUT_UP   ))m_pos.y -= 10;
	if (Pad::isPress(PAD_INPUT_DOWN ))m_pos.y += 10;

	if (Pad::isTrigger(PAD_INPUT_1  ))// XBOX A
	{
		m_moveType = static_cast<int>(moveType::Attack2);// 攻撃
	}
	if (Pad::isTrigger(PAD_INPUT_2))// XBOX B
	{
		m_moveType = static_cast<int>(moveType::Attack1);// 攻撃
	}
	if (Pad::isTrigger(PAD_INPUT_3) || (Pad::isTrigger(PAD_INPUT_4)))// XBOX X or Y
	{
		//　ジャンプ
		m_moveType = static_cast<int>(moveType::Jump);
	}
	if (Pad::isTrigger(XINPUT_BUTTON_LEFT_SHOULDER) || (Pad::isTrigger(PAD_INPUT_R)))// XBOX X or Y
	{
		//　ジャンプ

	}
	if (Pad::isTrigger(PAD_INPUT_1 ) && (Pad::isTrigger(PAD_INPUT_RIGHT))||// XBOX A && RIGHT
		Pad::isTrigger(PAD_INPUT_1) && (Pad::isTrigger(PAD_INPUT_LEFT)))   // XBOX A && LEFT
	{
		m_moveType = static_cast<int>(moveType::Attack3);;// 攻撃
	}

	m_posLeft   = m_pos.x   - 50;// プレイヤーのサイズ
	m_posTop    = m_pos.y   + 90;
	m_posRight  = m_posLeft + 100;
	m_posBottom = m_posTop  + 195;

}

void Elf::Draw()
{
	my::MyDrawRectRotaGraph(
		m_pos.y, m_pos.y,//プレイヤーの位置
		0, 0,// 画像の右上
		m_imageX, m_imageY,
		1.5,
		DX_PI_F * 2,
		m_handle,
		true,
		false
		);
}
