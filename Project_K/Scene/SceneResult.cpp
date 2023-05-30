#include "SceneResult.h"
#include "SceneTitle.h"
#include "SceneMapSelect.h"

SceneResult::SceneResult(bool isVictory1P, bool isVictory2P) :
	m_isTitle(false),
	m_isRetry(false),
	m_isVictory1P(isVictory1P),
	m_isVictory2P(isVictory2P)
{
}

SceneResult::~SceneResult()
{
}

void SceneResult::Init()
{
}

void SceneResult::End()
{
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
		if (Pad::IsTrigger(PAD_INPUT_1,1) || Pad::IsTrigger(PAD_INPUT_2,1))
		{
			StartFadeOut();
		}
	}

	if (!m_isTitle && !m_isRetry)
	{
		if (Pad::IsTrigger(PAD_INPUT_1,1))
		{
			m_isTitle = true;
		}
		else if (Pad::IsTrigger(PAD_INPUT_2,1))
		{
			m_isRetry = true;
		}
	}
	

	return this;
}

void SceneResult::Draw()
{
	DrawString(0, 0, "Result", Color::kWhite);
	DrawString(0, 20, "PAD_INPUT_1→Title", Color::kWhite);
	DrawString(0, 40, "PAD_INPUT_2→MapSelect", Color::kWhite);

	// 勝利状況
	// 引き分け
	if (m_isVictory1P && m_isVictory2P)
	{
		DrawString(100, 100, "Draw", Color::kRed);
	}
	// 1Pの勝利
	else if (m_isVictory1P)
	{
		DrawString(100, 100, "1P:Victory", Color::kRed);
	}
	// 2Pの勝利
	else if(m_isVictory2P)
	{
		DrawString(100, 100, "2P:Victory", Color::kRed);
	}
	
	SceneBase::DrawFade();
}
