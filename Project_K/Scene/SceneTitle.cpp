#include "SceneTitle.h"
#include "SceneMapSelect.h"

SceneTitle::SceneTitle() :
	m_isFadeOut(false)
{
}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::Init()
{
	m_isFadeOut = IsFadingOut();
}

void SceneTitle::End()
{
}

SceneBase* SceneTitle::Update()
{
	

	// フェードインアウトしている
	if (IsFading())
	{
		SceneBase::UpdateFade();
		// フェードアウト終了時
		if (!IsFading() && m_isFadeOut) return (new SceneMapSelect);
	}

	// フェードインアウトしていない
	if (!IsFading())
	{
		// フェードアウト開始
		if (Pad::IsTrigger(PAD_INPUT_2)) 
			StartFadeOut();
	}
	

	return this;
}

void SceneTitle::Draw()
{
	DrawString(0, 0, "title", Color::kWhite, false);

	SceneBase::DrawFade();
}
