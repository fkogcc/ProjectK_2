#include "UI.h"
#include "DxLib.h"
#include"game.h"

namespace
{
	const int kWidthGauge = 100;
	const int kHightGauge = 25;
	const int kTimeBoxSize = 40;
	const int kCenter = Game::kScreenWidth / 2;
}

UI::UI()
{
	m_boxPos = { kCenter,60 };
	UI1.m_pos = { m_boxPos.x - kTimeBoxSize,50 };
	UI1.m_life = 100;
	UI1.m_damage = 0;
	UI1.m_empty = 100;

	UI2.m_pos = { m_boxPos.x + kTimeBoxSize,50 };
	UI2.m_life = 100;
	UI2.m_damage = 0;
	UI2.m_empty = 100;
	m_countFrame = 0;

}

void UI::Update()
{
	UI1.m_damage = 0;
	UI2.m_damage = 0;
	m_countFrame++;
	if (m_countFrame >= 60)
	{
		UI1.m_empty = UI1.m_life;
		UI2.m_empty = UI2.m_life;
		m_countFrame = 0;
	}
	/*if (Pad::isTrigger(PAD_INPUT_1))
	{
		UI1.m_damage -= 20;
		m_countFrame = 0;
	}*/
	/*if (Pad::isTrigger(PAD_INPUT_2))
	{
		UI2.m_damage -= 20;
		m_countFrame = 0;
	}*/

	UI1.m_life += UI1.m_damage;
	UI2.m_life += UI2.m_damage;
	if (UI1.m_life <= 0)
	{
		UI1.m_empty = 0;
		UI1.m_life = 0;
	}
	if (UI2.m_life <= 0)
	{
		UI2.m_empty = 0;
		UI2.m_life = 0;
	}
	//printfDx("%d\n", m_life1);
}

void UI::Draw()
{
	DrawLine(Game::kScreenWidth / 2, 0, Game::kScreenWidth / 2, 600, 0xffffff);
	DrawBox(UI1.m_pos.x, UI1.m_pos.y, UI1.m_pos.x - (5 * UI1.m_empty), UI1.m_pos.y + kHightGauge, 0xff0000, true);
	DrawBox(UI1.m_pos.x, UI1.m_pos.y, UI1.m_pos.x - (5 * UI1.m_life), UI1.m_pos.y + kHightGauge, 0x00ff00, true);
	DrawBox(UI2.m_pos.x, UI2.m_pos.y, UI2.m_pos.x + (5 * UI2.m_empty), UI2.m_pos.y + kHightGauge, 0xff0000, true);
	DrawBox(UI2.m_pos.x, UI2.m_pos.y, UI2.m_pos.x + (5 * UI2.m_life), UI2.m_pos.y + kHightGauge, 0x00ff00, true);

	DrawFormatString(100, 0, 0x00ff00, "%d", m_countFrame);

	DrawBox(m_boxPos.x - kTimeBoxSize, m_boxPos.y - kTimeBoxSize,
		m_boxPos.x + kTimeBoxSize, m_boxPos.y + kTimeBoxSize, 0xff00f0, false);


	/*
	時間　99
	100　外
	色変え
	*/
}