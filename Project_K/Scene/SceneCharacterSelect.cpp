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
	m_Player[0] = nullptr;
    m_Player[1] = nullptr;
	m_CharaChoice = new CharaChoice;
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
	m_CharaChoice->Update();

	if (m_CharaChoice->GetDecision1() && m_CharaChoice->GetDecision2())
	{
		if (m_CharaChoice->GetChackChara1() == 0) m_Player[0] = new Dinosaur;
		if (m_CharaChoice->GetChackChara1() == 1) m_Player[0] = new Elf;
		if (m_CharaChoice->GetChackChara1() == 2) m_Player[0] = new Kinnikurou;
		if (m_CharaChoice->GetChackChara1() == 3) m_Player[0] = new Witch;

		if (m_CharaChoice->GetChackChara2() == 0) m_Player[1] = new Dinosaur;
		if (m_CharaChoice->GetChackChara2() == 1) m_Player[1] = new Elf;
		if (m_CharaChoice->GetChackChara2() == 2) m_Player[1] = new Kinnikurou;
		if (m_CharaChoice->GetChackChara2() == 3) m_Player[1] = new Witch;
		
		return(new SceneMain(m_Player[0],m_Player[1]));// 1ステージ切り替え
	}

	// シーン遷移
	//if (IsFading())
	//{
	//	m_isFadeOut = IsFadingOut();
	//	SceneBase::UpdateFade();
	//	if (!IsFading() && m_isFadeOut)
	//	{
	//		// trueの場合
	//		// m_isVictory1P = 1Pの勝利
	//		// m_isVictory2P = 2Pの勝利
	//		return(new SceneMain(m_Player[0], m_Player[1]));// 1ステージ切り替え
	//	}
	//}

	//// フェードインアウトしていない時
	//if (!IsFading())
	//{
	//	// デバッグ用シーン遷移
	//	if (m_CharaChoice->GetDecision1() && m_CharaChoice->GetDecision2())
	//	{
	//		StartFadeOut();
	//	}
	//}
	
	return this;
}

void SceneCharacterSelect::Draw()
{

	m_CharaChoice->Draw();

	//SceneBase::DrawFade();
}
