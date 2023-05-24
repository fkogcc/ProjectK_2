#include "SceneResult.h"
#include "SceneTitle.h"
#include "SceneMapSelect.h"

SceneResult::SceneResult() :
	m_isTitle(false),
	m_isRetry(false)
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
		if (Pad::IsTrigger(PAD_INPUT_1) || Pad::IsTrigger(PAD_INPUT_2))
		{
			StartFadeOut();
		}
	}

	if (!m_isTitle && !m_isRetry)
	{
		if (Pad::IsTrigger(PAD_INPUT_1))
		{
			m_isTitle = true;
		}
		else if (Pad::IsTrigger(PAD_INPUT_2))
		{
			m_isRetry = true;
		}
	}
	

	return this;
}

void SceneResult::Draw()
{
	DrawString(0, 0, "Result", Color::kWhite);
	DrawString(0, 20, "PAD_INPUT_1Å®Title", Color::kWhite);
	DrawString(0, 40, "PAD_INPUT_2Å®MapSelect", Color::kWhite);
	
	SceneBase::DrawFade();
}
