#include "SceneTitle.h"
#include "SceneMapSelect.h"
#include "../LogoRotation.h"

SceneTitle::SceneTitle():
	m_pLogo(nullptr)
{
	// ロゴ回転用だが後回しなのでまだ出来ていない。
	m_pLogo = new LogoRotation;
}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::Init()
{
	m_isFadeOut = IsFadingOut();
	m_pLogo->Init();
}

void SceneTitle::End()
{
	delete m_pLogo;
}

SceneBase* SceneTitle::Update()
{

	m_pLogo->Update();

	// フェードインアウトしている
	if (IsFading())
	{
		m_isFadeOut = IsFadingOut();
		SceneBase::UpdateFade();
		// フェードアウト終了時
		if (!IsFading() && m_isFadeOut)
		{
			return (new SceneMapSelect);
		}
	}

	// フェードインアウトしていない
	if (!IsFading())
	{
		// フェードアウト開始
		if (Pad::IsTrigger(PAD_INPUT_1,1))
		{
			StartFadeOut();
		}
	}
	

	return this;
}

void SceneTitle::Draw()
{

	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, 0xffffff, true);

//	DrawBox(500, 300, Game::kScreenWidth - 500, 500, 0x0000, true);

	DrawString(0, 0, "title", Color::kWhite, false);
	DrawString(0, 0, "title", 0x000000, false);

	m_pLogo->Draw();

	SceneBase::DrawFade();
}
