#include "SceneMapSelect.h"
#include "SceneCharacterSelect.h"
#include "SceneTitle.h"

SceneMapSelect::SceneMapSelect() 
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
		if (Pad::IsTrigger(PAD_INPUT_1))
		{
			StartFadeOut();
		}
	}

	return this;
}

void SceneMapSelect::Draw()
{
	DrawString(0, 0, "MapSelect", Color::kWhite);

	SceneBase::DrawFade();
}
