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
	

	// �t�F�[�h�C���A�E�g���Ă���
	if (IsFading())
	{
		SceneBase::UpdateFade();
		// �t�F�[�h�A�E�g�I����
		if (!IsFading() && m_isFadeOut) return (new SceneMapSelect);
	}

	// �t�F�[�h�C���A�E�g���Ă��Ȃ�
	if (!IsFading())
	{
		// �t�F�[�h�A�E�g�J�n
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
