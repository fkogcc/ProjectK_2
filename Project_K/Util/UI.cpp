#include "UI.h"
#include "DxLib.h"
#include"game.h"

namespace
{
	const int kWidthGauge = 100;
	const int kHightGauge = 40;
	const int kTimeBoxSize = 50;// 時間を表示する場所のボックスのサイズ
	const int kCenter = Game::kScreenWidth / 2;// 真ん中の位置
}

UI::UI()
{
	m_boxPos = { kCenter,90 };//時間を表示するボックスの初期化
	// 1Pの初期化
	UI1.m_pos = { m_boxPos.x - kTimeBoxSize,80 };
	UI1.m_life = 100;
	UI1.m_temp = 0;
	// 2Pの初期化
	UI2.m_pos = { m_boxPos.x + kTimeBoxSize,80 };
	UI2.m_life = 100;
	UI2.m_temp = 0;
	m_countFrame = 50;// タイマーの初期化
}

void UI::Update()
{
	m_countFrame++;//タイマーのカウント
	if (m_countFrame >= 40)
	{
		UI1.m_temp = UI1.m_life;// 仮のHPを今のHP似合わせる
		UI2.m_temp = UI2.m_life;// 仮のHPを今のHP似合わせる
		m_countFrame = 0;
	}
	if (UI1.m_temp == UI1.m_life && UI2.m_temp == UI2.m_life)
	{
		m_countFrame = 0;
	}

	if (UI1.m_life <= 0)
	{
		UI1.m_temp = 0;
		UI1.m_life = 0;
	}
	if (UI2.m_life <= 0)
	{
		UI2.m_temp = 0;
		UI2.m_life = 0;
	}
	printfDx("%d\n", UI1.m_life);
}

void UI::Draw()
{
	//DrawLine(Game::kScreenWidth / 2, 0, Game::kScreenWidth / 2, 600, 0xffffff);
	//仮のHPの表示
	DrawBox(static_cast<int>(UI1.m_pos.x), static_cast<int>(UI1.m_pos.y), 
		static_cast<int>(UI1.m_pos.x) - (5 * UI1.m_temp), static_cast<int>(UI1.m_pos.y) + kHightGauge, 0xff0000, true);
	DrawBox(static_cast<int>(UI1.m_pos.x), static_cast<int>(UI1.m_pos.y),
		static_cast<int>(UI1.m_pos.x) - (5 * UI1.m_life), static_cast<int>(UI1.m_pos.y) + kHightGauge, 0x00ff00, true);
	//現在HPの表示
	DrawBox(static_cast<int>(UI2.m_pos.x), static_cast<int>(UI2.m_pos.y),
		static_cast<int>(UI2.m_pos.x) + (5 * UI2.m_temp), static_cast<int>(UI2.m_pos.y)+ kHightGauge, 0xff0000, true);
	DrawBox(static_cast<int>(UI2.m_pos.x), static_cast<int>(UI2.m_pos.y),
		static_cast<int>(UI2.m_pos.x) + (5 * UI2.m_life), static_cast<int>(UI2.m_pos.y) + kHightGauge, 0x00ff00, true);

	//DrawFormatString(100, 0, 0x00ff00, "%d", m_countFrame);

	// ここに時間を表示する（目安の位置）
	DrawBox(static_cast<int>(m_boxPos.x) - kTimeBoxSize, static_cast<int>(m_boxPos.y) - kTimeBoxSize,
		static_cast<int>(m_boxPos.x) + kTimeBoxSize, static_cast<int>(m_boxPos.y) + kTimeBoxSize, 0xff00f0, false);

}