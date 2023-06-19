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
}

UI::UI(int Hp1, int Hp2) :
	m_boxPos(kCenter, 90),	// 時間を表示するボックスの初期化
	m_timeCount(99 * 60),// 時間を図るタイマー
	m_time(0),// 表示する時間
	m_letter("%d")// 文字
{
	m_font = CreateFontToHandle(kFont, 70, -1, -1);// 使用するフォント、サイズ
	// 1Pの初期化
	m_ui1.m_pos = { m_boxPos.x - kTimeBoxSize,80 };
	m_ui1.m_temp = Hp1;
	m_ui1.m_life = m_ui1.m_temp;
	m_ui1.m_lower = m_ui1.m_life;
	m_ui1.m_countFrame = 50;// タイマーの初期化
	m_ui1.m_attackFlag = false;// 攻撃中かしるためのフラグ
	// 2Pの初期化
	m_ui2.m_pos = { m_boxPos.x + kTimeBoxSize,80 };
	m_ui2.m_temp = Hp2;
	m_ui2.m_life = m_ui2.m_temp;
	m_ui2.m_lower = m_ui2.m_life;
	m_ui2.m_countFrame = 50;// タイマーの初期化
	m_ui2.m_attackFlag = false;// 攻撃中かしるためのフラグ
}

void UI::Update()
{
	HpUpdate();
	FontUpdate();
}

void UI::Draw()
{
	HpDraw();
	FontDraw();
}

void UI::HpUpdate()
{
	m_ui1.m_countFrame++;//タイマーのカウント
	m_ui2.m_countFrame++;//タイマーのカウント
	if (m_ui1.m_temp >= 0)
	{
		m_ui1.m_life--;// ゆっくり減らす
		if (m_ui1.m_life < m_ui1.m_temp)
		{
			m_ui1.m_life = m_ui1.m_temp;
		}
	}
	if (m_ui2.m_temp >= 0)
	{
		m_ui2.m_life--;// ゆっくり減らす
		if (m_ui2.m_life < m_ui2.m_temp)
		{
			m_ui2.m_life = m_ui2.m_temp;
		}
	}
	if (m_ui1.m_countFrame >= 40)
	{
		m_ui1.m_lower = m_ui1.m_life;// 仮のHPを今のHP似合わせる
		m_ui1.m_countFrame = 0;
	}

	if (m_ui2.m_countFrame >= 40)
	{
		m_ui2.m_lower = m_ui2.m_life;// 仮のHPを今のHP似合わせる
		m_ui2.m_countFrame = 0;
	}
	if (m_ui1.m_attackFlag)// 攻撃中だったらカウントを数えない
	{
		m_ui1.m_countFrame = 0;
	}
	if (m_ui2.m_attackFlag)// 攻撃中だったらカウントを数えない
	{
		m_ui2.m_countFrame = 0;
	}
	if (m_ui1.m_life <= 0)
	{
		m_ui1.m_lower = 0;
		m_ui1.m_life = 0;
	}
	if (m_ui2.m_life <= 0)
	{
		m_ui2.m_lower = 0;
		m_ui2.m_life = 0;
	}
}

void UI::HpDraw()
{
	//DrawLine(Game::kScreenWidth / 2, 0, Game::kScreenWidth / 2, 600, 0xffffff);
	//仮のHPの表示
	DrawBox(static_cast<int>(m_ui1.m_pos.x), static_cast<int>(m_ui1.m_pos.y),
		static_cast<int>(m_ui1.m_pos.x) - (5 * m_ui1.m_lower), static_cast<int>(m_ui1.m_pos.y) + kHightGauge, 0xff0000, true);
	DrawBox(static_cast<int>(m_ui1.m_pos.x), static_cast<int>(m_ui1.m_pos.y),
		static_cast<int>(m_ui1.m_pos.x) - (5 * m_ui1.m_life), static_cast<int>(m_ui1.m_pos.y) + kHightGauge, 0x00ff00, true);
	//現在HPの表示
	DrawBox(static_cast<int>(m_ui2.m_pos.x), static_cast<int>(m_ui2.m_pos.y),
		static_cast<int>(m_ui2.m_pos.x) + (5 * m_ui2.m_lower), static_cast<int>(m_ui2.m_pos.y) + kHightGauge, 0xff0000, true);
	DrawBox(static_cast<int>(m_ui2.m_pos.x), static_cast<int>(m_ui2.m_pos.y),
		static_cast<int>(m_ui2.m_pos.x) + (5 * m_ui2.m_life), static_cast<int>(m_ui2.m_pos.y) + kHightGauge, 0x00ff00, true);

	// ここに時間を表示する（目安の位置）
	//DrawBox(static_cast<int>(m_boxPos.x) - kTimeBoxSize, static_cast<int>(m_boxPos.y) - kTimeBoxSize,
	//	static_cast<int>(m_boxPos.x) + kTimeBoxSize, static_cast<int>(m_boxPos.y) + kTimeBoxSize, 0xff00f0, true);// 面白いことしたかったけどできませんでした
	DrawBox(static_cast<int>(m_boxPos.x) - kTimeBoxSize, static_cast<int>(m_boxPos.y) - kTimeBoxSize,
		static_cast<int>(m_boxPos.x) + kTimeBoxSize, static_cast<int>(m_boxPos.y) + kTimeBoxSize, 0xff00f0, false);
}

void UI::FontUpdate()
{
	// 時間を減らす
	m_timeCount--;
	if (m_timeCount < 0)
	{
		m_timeCount = 0;// 0よりちっちゃくならないように
	}
	if (m_time < 10)
	{
		m_letter = "0%d";// 一桁台になったら0を表示させる
	}
}

void UI::FontDraw()
{
	m_time = m_timeCount / 60;
	// 赤フォントの表示
	DrawFormatStringToHandle((Game::kScreenWidth -
		GetDrawStringWidthToHandle(m_letter, 2, m_font)) / 2 + 5,
		100 - 35, 0x800000, m_font, m_letter, m_time);
	// 青フォントの表示
	DrawFormatStringToHandle((Game::kScreenWidth -
		GetDrawStringWidthToHandle(m_letter, 2, m_font)) / 2,
		100 - 40, 0x7fffff, m_font, m_letter, m_time);
}
