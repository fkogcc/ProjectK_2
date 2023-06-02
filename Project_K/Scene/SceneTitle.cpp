#include "SceneTitle.h"
#include "SceneMapSelect.h"
#include "../Util/DrawFunctions.h"

SceneTitle::SceneTitle():
	m_hLogo(-1),
	m_pos(0.0, 0.0),
	m_logoPos(0.0, 0.0)
{
	m_pos.x = 100.0f;
	m_pos.y = 100.0f;

	m_logoPos.x = 300.0f;
	m_logoPos.y = 300.0f;
}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::Init()
{
	m_isFadeOut = IsFadingOut();
	m_hLogo = my::MyLoadGraph("Data/Image/Logo/logo.png");
}

void SceneTitle::End()
{
	DeleteGraph(m_hLogo);
}

SceneBase* SceneTitle::Update()
{

	float trans = 0.8f;


	m_pos.x += trans;

	m_logoPos.x -= trans;


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

	DrawBox(500, 300, Game::kScreenWidth - 500, 500, 0x0000, true);

	DrawString(0, 0, "title", Color::kWhite, false);
	DrawString(0, 0, "title", 0x000000, false);

	my::MyDrawExtendGraph(m_pos.x, m_pos.y, m_logoPos.x, m_logoPos.y, m_hLogo, true);

	SceneBase::DrawFade();
}
