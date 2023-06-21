#include "SceneResult.h"
#include "SceneTitle.h"
#include "SceneMapSelect.h"
#include "../Object/Player/Dinosaur/Dinosaur.h"
#include "../Object/Player/Elf/Elf.h"
#include "../Object/Player/Kinnikurou/Kinnikurou.h"
#include "../Object/Player/Witch/Witch.h"
#include "../Util/Vec2.h"
#include "../StringFunction.h"

namespace
{
	// プレイヤーのサイズ
	constexpr int kPlayerSize = 3;
	constexpr int kPlayerNum = 2;
	constexpr int kFonstSize = 250;
	constexpr int kWinNameFontPosX = 100;
	constexpr int kWinNameFontPosY = 100;
	constexpr int kColor = 0x000000;
}

SceneResult::SceneResult(bool isVictory1P, bool isVictory2P, PlayerBase* player1P, PlayerBase* player2P) :
	m_isTitle(false),
	m_isRetry(false),
	m_isVictory1P(isVictory1P),
	m_isVictory2P(isVictory2P)
{
	m_pPlayer[0] = nullptr;
	m_pPlayer[1] = nullptr;
	m_pPlayer[0] = player1P;
	m_pPlayer[1] = player2P;

	m_pString = new StringFunction;
}

SceneResult::~SceneResult()
{
	delete m_pPlayer[0];
	delete m_pPlayer[1];
	delete m_pString;
}

void SceneResult::Init()
{
	bool isWin[2] = { m_isVictory1P ,m_isVictory2P };
	const char* fontName = "Valentina";

	for (int i = 0; i < kPlayerNum; i++)
	{
		// どちらのプレイヤーが勝利したか
		if (isWin[i])
		{
			// プレイヤーの初期化
			m_pPlayer[i]->Init();
			// 魔女が消えるためUpdate関数を呼び出し応急処置
			m_pPlayer[i]->Update();
			// どのキャラクターが勝利したか
			if (dynamic_cast<Dinosaur*>(m_pPlayer[i]))
			{
				Vec2 winPos = { static_cast<float>(Game::kScreenWidth) / 2.0f,
								static_cast<float>(Game::kScreenHeight) / 2.0f };
				// キャラクターの位置変更
				m_pPlayer[i]->SetPos(winPos);
				// キャラクターのサイズ変更
				m_pPlayer[i]->SetSize(kPlayerSize);
				// キャラクターのサイズ変更
				m_pString->Add(kWinNameFontPosX, kWinNameFontPosY, "Dinosaur WIN", kColor, kFonstSize, fontName);
			}
			// どのキャラクターが勝利したか
			else if (dynamic_cast<Elf*>(m_pPlayer[i]))
			{
				Vec2 winPos = { static_cast<float>(Game::kScreenWidth) / 2.0f,
					static_cast<float>(Game::kScreenHeight) / 2.0f - 500.0f };
				// キャラクターの位置変更
				m_pPlayer[i]->SetPos(winPos);
				// キャラクターのサイズ変更
				m_pPlayer[i]->SetSize(kPlayerSize);
				// キャラクターのサイズ変更
				m_pString->Add(kWinNameFontPosX, kWinNameFontPosY, "Elf WIN", kColor, kFonstSize, fontName);
			}
			// どのキャラクターが勝利したか
			else if (dynamic_cast<Kinnikurou*>(m_pPlayer[i]))
			{
				Vec2 winPos = { static_cast<float>(Game::kScreenWidth) / 2.0f,
					static_cast<float>(Game::kScreenHeight) / 2.0f };
				// キャラクターの位置変更
				m_pPlayer[i]->SetPos(winPos);
				// キャラクターのサイズ変更
				m_pPlayer[i]->SetSize(kPlayerSize);
				// キャラクターのサイズ変更
				m_pString->Add(kWinNameFontPosX, kWinNameFontPosY, "KinniKun WIN", kColor, kFonstSize, fontName);
			}
			// どのキャラクターが勝利したか
			else if (dynamic_cast<Witch*>(m_pPlayer[i]))
			{
				Vec2 winPos = { static_cast<float>(Game::kScreenWidth) / 2.0f,
					static_cast<float>(Game::kScreenHeight) / 2.0f };
				// キャラクターの位置変更
				m_pPlayer[i]->SetPos(winPos);
				// キャラクターのサイズ変更
				m_pPlayer[i]->SetSize(kPlayerSize);
				// キャラクターのサイズ変更
				m_pString->Add(kWinNameFontPosX, kWinNameFontPosY, "Witch WIN", kColor, kFonstSize, fontName);
			}
		}
	}
}

void SceneResult::End()
{
	m_pPlayer[0]->End();
	m_pPlayer[1]->End();
}

SceneBase* SceneResult::Update()
{
	if (IsFading())
	{
		m_isFadeOut = IsFadingOut();
		SceneBase::UpdateFade();

		if (!IsFading() && m_isFadeOut && m_isTitle)
		{
			return (new SceneTitle);
		}
		if (!IsFading() && m_isFadeOut && m_isRetry)
		{
			return (new SceneMapSelect);
		}
	}

	if (!IsFading())
	{
		if (Pad::IsTrigger(PAD_INPUT_1,1) || Pad::IsTrigger(PAD_INPUT_2,1) ||
			Pad::IsTrigger(PAD_INPUT_1, 2) || Pad::IsTrigger(PAD_INPUT_2, 2))
		{
			StartFadeOut();
		}
	}

	if (!m_isTitle && !m_isRetry)
	{
		if (Pad::IsTrigger(PAD_INPUT_1, 1) || Pad::IsTrigger(PAD_INPUT_1, 2))
		{
			m_isTitle = true;
		}
		else if (Pad::IsTrigger(PAD_INPUT_2,1) || Pad::IsTrigger(PAD_INPUT_2, 2))
		{
			m_isRetry = true;
		}
	}

	return this;
}

void SceneResult::Draw()
{

	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, 0xffffff, true);

	DrawString(0, 0, "Result", Color::kWhite);
	DrawString(0, 20, "PAD_INPUT_1→Title", Color::kWhite);
	DrawString(0, 40, "PAD_INPUT_2→MapSelect", Color::kWhite);

	m_pString->Draw();

	// 勝利状況
	// 引き分け
	if ((m_isVictory1P && m_isVictory2P) || (!m_isVictory1P && !m_isVictory2P))
	{
		DrawString(100, 100, "Draw", Color::kRed);
		m_pPlayer[0]->Draw();
		m_pPlayer[1]->Draw();
	}
	// 1Pの勝利
	else if (m_isVictory1P)
	{
		DrawString(100, 100, "1P:Victory", Color::kRed);
		m_pPlayer[0]->Draw();
		
	}
	// 2Pの勝利
	else if(m_isVictory2P)
	{
		DrawString(100, 100, "2P:Victory", Color::kRed);
		m_pPlayer[1]->Draw();
	}
	
	

	SceneBase::DrawFade();
}
