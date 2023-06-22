#include "SceneTitle.h"
#include "SceneMapSelect.h"
#include "../LogoRotation.h"
#include "../Util/Sound.h"

SceneTitle::SceneTitle():
	m_pLogo(nullptr)
{
	// ���S��]�p������񂵂Ȃ̂ł܂��o���Ă��Ȃ��B
	m_pLogo = new LogoRotation;
}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::Init()
{
	// BGM �Đ�
	Sound::startBgm(Sound::TitleBgm, 255);

	m_isFadeOut = IsFadingOut();
	m_pLogo->Init();
}

void SceneTitle::End()
{
	// BGM ��~
	Sound::stopBgm(Sound::TitleBgm);

	delete m_pLogo;
}

SceneBase* SceneTitle::Update()
{
	Sound::loopBgm(Sound::TitleBgm);
	m_pLogo->Update();

	// �t�F�[�h�C���A�E�g���Ă���
	if (IsFading())
	{
		m_isFadeOut = IsFadingOut();
		SceneBase::UpdateFade();
		// �t�F�[�h�A�E�g�I����
		if (!IsFading() && m_isFadeOut && !m_isBackScene)
		{
			return (new SceneMapSelect);
		}
	}

	// �t�F�[�h�C���A�E�g���Ă��Ȃ�
	if (!IsFading())
	{
		// �t�F�[�h�A�E�g�J�n
		if (Pad::IsTrigger(PAD_INPUT_1,1) || Pad::IsTrigger(PAD_INPUT_1, 2))
		{
			StartFadeOut();
		}
	}
	

	return this;
}

void SceneTitle::Draw()
{

	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, 0xffffff, true);

	DrawString(0, 0, "title", Color::kWhite, false);
	DrawString(0, 0, "title", 0x000000, false);

	m_pLogo->Draw();

	SceneBase::DrawFade();
}


