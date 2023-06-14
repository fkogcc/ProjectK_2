#include "SceneMapSelect.h"
#include "SceneCharacterSelect.h"
#include "SceneTitle.h"

SceneMapSelect::SceneMapSelect() :
	m_mapNum(-1)
{
}

SceneMapSelect::~SceneMapSelect()
{
}

void SceneMapSelect::Init()
{
}

void SceneMapSelect::End()
{
}

SceneBase* SceneMapSelect::Update()
{
	if (IsFading())
	{
		m_isFadeOut = IsFadingOut();
		SceneBase::UpdateFade();
		
		if (!IsFading() && m_isFadeOut) 
		{ 
			return (new SceneCharacterSelect); 
		}
	}

	if (!IsFading())
	{
		if (Pad::IsTrigger(PAD_INPUT_1,1))
		{
			StartFadeOut();
		}
	}

	if (Pad::IsTrigger(PAD_INPUT_UP, 1))
	{
		m_mapNum++;
	}
	else if (Pad::IsTrigger(PAD_INPUT_DOWN, 1))
	{
		m_mapNum--;

		if()
	}

	return this;
}

void SceneMapSelect::Draw()
{
	DrawString(0, 0, "MapSelect", Color::kWhite);
	DrawFormatString(0, 15, 0xffffff, "MapNum = %d", m_mapNum);

	SceneBase::DrawFade();
}

void SceneMapSelect::ChooseNum()
{
}
