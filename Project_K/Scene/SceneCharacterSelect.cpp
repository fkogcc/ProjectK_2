#include "SceneCharacterSelect.h"
#include "SceneMain.h"
#include "../Util/Pad.h"
#include"../System/CharaChoice.h"
#include"../Object/Player/Dinosaur/Dinosaur.h"
#include"../Object/Player/Elf/Elf.h"
#include"../Object/Player/Kinnikurou/Kinnikurou.h"
#include"../Object/Player/Witch/Witch.h"

SceneCharacterSelect::SceneCharacterSelect()
{
	m_pPlayer[0] = nullptr;
    m_pPlayer[1] = nullptr;
	m_pCharaChoice = new CharaChoice;
}

SceneCharacterSelect::~SceneCharacterSelect()
{
}

void SceneCharacterSelect::Init()
{
}

void SceneCharacterSelect::End()
{
}

SceneBase* SceneCharacterSelect::Update()
{
	m_pCharaChoice->Update();


	if (m_pCharaChoice->GetDecision1() && m_pCharaChoice->GetDecision2())
	{

		if (m_pCharaChoice->GetChackChara1() == 0) m_pPlayer[0] = new Dinosaur;
		if (m_pCharaChoice->GetChackChara1() == 1) m_pPlayer[0] = new Elf;
		if (m_pCharaChoice->GetChackChara1() == 2) m_pPlayer[0] = new Kinnikurou;
		if (m_pCharaChoice->GetChackChara1() == 3) m_pPlayer[0] = new Witch;

		if (m_pCharaChoice->GetChackChara2() == 0) m_pPlayer[1] = new Dinosaur;
		if (m_pCharaChoice->GetChackChara2() == 1) m_pPlayer[1] = new Elf;
		if (m_pCharaChoice->GetChackChara2() == 2) m_pPlayer[1] = new Kinnikurou;
		if (m_pCharaChoice->GetChackChara2() == 3) m_pPlayer[1] = new Witch;
		
		//return(new SceneMain(m_Player[0],m_Player[1]));// 1ステージ切り替え
	}

	// シーン遷移
	if (IsFading())
	{
		m_isFadeOut = IsFadingOut();
		SceneBase::UpdateFade();

		if (!IsFading() && m_isFadeOut)
		{
			// シーン遷移(1Pプレイヤー、2Pプレイヤー)
			return(new SceneMain(m_pPlayer[0], m_pPlayer[1]));// 1ステージ切り替え
		}
	}

	// フェードインアウトしていないとき
	if (!IsFading())
	{
		if (m_pPlayer[0] != nullptr && m_pPlayer[1] != nullptr)
		{
			StartFadeOut();
		}
	}

	
	return this;
}

void SceneCharacterSelect::Draw()
{
	DrawString(0, 0, "CharacterSelect", Color::kWhite);
	DrawString(0, 20, "PAD_INPUT_1->SceneMain", Color::kWhite);

	m_pCharaChoice->Draw();

	SceneBase::DrawFade();
}