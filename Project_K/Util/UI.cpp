#include "UI.h"
#include "DxLib.h"
#include"game.h"

namespace
{
	const int kWidthGauge = 100;
	const int kHightGauge = 40;
	const int kTimeBoxSize = 50;// 時間を表示する場所のボックスのサイズ
	const int kCenter = Game::kScreenWidth / 2;// 真ん中の位置
	const char* kFont = "HGP行書体";
	int a = 0;
}

UI::UI(int Hp1, int Hp2) :
	m_boxPos(kCenter, 90),	//時間を表示するボックスの初期化
	m_countFrame(50),		// タイマーの初期化
	m_attackFlag(false)		//攻撃中かしるためのフラグ
{
	a = CreateFontToHandle(kFont, 70, -1, -1);
	// 1Pの初期化
	UI1.m_pos = { m_boxPos.x - kTimeBoxSize,80 };
	UI1.m_temp = Hp1;
	UI1.m_life = UI1.m_temp;
	UI1.m_lower = UI1.m_life;
	// 2Pの初期化
	UI2.m_pos = { m_boxPos.x + kTimeBoxSize,80 };
	UI2.m_temp = Hp2;
	UI2.m_life = UI2.m_temp;
	UI2.m_lower = UI2.m_life;
}

void UI::Update()
{
	HpUpdate();
}

void UI::Draw()
{
	HpDraw();
	FontDraw();
}

void UI::HpUpdate()
{
	m_countFrame++;//タイマーのカウント
	if (UI1.m_temp >= 0)
	{
		UI1.m_life = UI1.m_temp;
	}
	if (UI2.m_temp >= 0)
	{
		UI2.m_life = UI2.m_temp;
	}
	if (m_countFrame >= 40 && !m_attackFlag)
	{
		UI1.m_lower = UI1.m_life;// 仮のHPを今のHP似合わせる
		UI2.m_lower = UI2.m_life;// 仮のHPを今のHP似合わせる
		m_countFrame = 0;
	}
	if (UI1.m_lower != UI1.m_life && UI2.m_lower != UI2.m_life)
	{
		m_countFrame = 0;
	}
	if (UI1.m_life <= 0)
	{
		UI1.m_lower = 0;
		UI1.m_life = 0;
	}
	if (UI2.m_life <= 0)
	{
		UI2.m_lower = 0;
		UI2.m_life = 0;
	}
}

void UI::HpDraw()
{
	//DrawLine(Game::kScreenWidth / 2, 0, Game::kScreenWidth / 2, 600, 0xffffff);
	//仮のHPの表示
	DrawBox(static_cast<int>(UI1.m_pos.x), static_cast<int>(UI1.m_pos.y),
		static_cast<int>(UI1.m_pos.x) - (5 * UI1.m_lower), static_cast<int>(UI1.m_pos.y) + kHightGauge, 0xff0000, true);
	DrawBox(static_cast<int>(UI1.m_pos.x), static_cast<int>(UI1.m_pos.y),
		static_cast<int>(UI1.m_pos.x) - (5 * UI1.m_life), static_cast<int>(UI1.m_pos.y) + kHightGauge, 0x00ff00, true);
	//現在HPの表示
	DrawBox(static_cast<int>(UI2.m_pos.x), static_cast<int>(UI2.m_pos.y),
		static_cast<int>(UI2.m_pos.x) + (5 * UI2.m_lower), static_cast<int>(UI2.m_pos.y) + kHightGauge, 0xff0000, true);
	DrawBox(static_cast<int>(UI2.m_pos.x), static_cast<int>(UI2.m_pos.y),
		static_cast<int>(UI2.m_pos.x) + (5 * UI2.m_life), static_cast<int>(UI2.m_pos.y) + kHightGauge, 0x00ff00, true);

	//DrawFormatString(100, 0, 0x00ff00, "%d", m_countFrame);

	// ここに時間を表示する（目安の位置）
	DrawBox(static_cast<int>(m_boxPos.x) - kTimeBoxSize, static_cast<int>(m_boxPos.y) - kTimeBoxSize,
		static_cast<int>(m_boxPos.x) + kTimeBoxSize, static_cast<int>(m_boxPos.y) + kTimeBoxSize, 0xff00f0, false);

}

void UI::FontUpdate()
{
}

void UI::FontDraw()
{
	DrawFormatStringToHandle((Game::kScreenWidth -
		GetDrawStringWidthToHandle("%d", 11, a)) / 2,
		100 - 40, 0x7fffff, a, "%d", 99);
}
