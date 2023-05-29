#include "SceneCharacterSelect.h"
#include "SceneMain.h"
#include "../Util/Pad.h"
#include "../Util/Pad2.h"
#include"../System/CharaChoice.h"
#include"../Object/Player/Dinosaur/Dinosaur.h"
#include"../Object/Player/Elf/Elf.h"
#include"../Object/Player/Kinnikurou/Kinnikurou.h"
#include"../Object/Player/Witch/Witch.h"

SceneCharacterSelect::SceneCharacterSelect() :
	m_isDino(false),
	m_isElf(false),
	m_isKin(false),
	m_isWitch(false),
	m_isDino2(false),
	m_isElf2(false),
	m_isKin2(false),
	m_isWitch2(false)
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

	//User1();
	//User2();


	//if (User1() && User2())
	//{
	//	if(m_isDino2)m_isDino = m_isDino2;
	//	if(m_isElf2)m_isElf = m_isElf2;
	//	if(m_isKin2)m_isKin = m_isKin2;
	//	if(m_isWitch2)m_isWitch = m_isWitch2;
	//	
	//	return(new SceneMain(m_isDino, m_isElf, m_isKin, m_isWitch));// 1ステージ切り替え
	//}

	m_CharaChoice->Update();


	if (m_CharaChoice->GetDecision1() && m_CharaChoice->GetDecision2())
	{
		/*if(m_isDino2)m_isDino = m_isDino2;
		if(m_isElf2)m_isElf = m_isElf2;
		if(m_isKin2)m_isKin = m_isKin2;
		if(m_isWitch2)m_isWitch = m_isWitch2;*/

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



	/*if (IsFading())
	{
		m_isFadeOut = IsFadingOut();
		SceneBase::UpdateFade();

		if (!IsFading() && m_isFadeOut)
		{
			return (new SceneMain(m_isDino, m_isElf, m_isKin, m_isWitch));
		}
	}

	if (!IsFading())
	{
		if (Pad::IsTrigger(PAD_INPUT_1))
		{
			StartFadeOut();
		}
	}*/

	//if (IsFading())
	//{
	//	m_isFadeOut = IsFadingOut();
	//	SceneBase::UpdateFade();

	//	if (!IsFading() && m_isFadeOut)
	//	{
	//		// シーン遷移(ダイナソー、エルフ、きんに君、魔女)
	//		return(new SceneMain(m_Player[0], m_Player[1]));// 1ステージ切り替え
	//	}
	//}

	//if (!IsFading())
	//{
	//	if (Pad::IsTrigger(PAD_INPUT_1,1))
	//	{
	//		StartFadeOut();
	//	}
	//}

	
	return this;
}

void SceneCharacterSelect::Draw()
{
	/*DrawString(0, 0, "CharacterSelect", Color::kWhite);
	DrawString(0, 20, "PAD_INPUT_1->SceneMain", Color::kWhite);*/

	m_CharaChoice->Draw();

//	SceneBase::DrawFade();
}

//bool SceneCharacterSelect::User1()
//{
//	// だいなそー選択
//	if (Pad::IsTrigger(PAD_INPUT_1))// XBOX A
//	{
//		m_isDino = true;
//
//		m_isElf = false;
//		m_isKin = false;
//		m_isWitch = false;
//
//	}
//	// エルフ選択
//	if (Pad::IsTrigger(PAD_INPUT_2))// XBOX 
//	{
//		m_isElf = true;
//
//		m_isDino = false;
//		m_isKin = false;
//		m_isWitch = false;
//	}
//	// きんにくろう選択
//	if (Pad::IsTrigger(PAD_INPUT_3))// XBOX A
//	{
//		m_isKin = true;
//
//		m_isDino = false;
//		m_isElf = false;
//		m_isWitch = false;
//	}
//	// 魔女選択
//	if (Pad::IsTrigger(PAD_INPUT_4))// XBOX A
//	{
//		m_isWitch = true;
//
//		m_isDino = false;
//		m_isElf = false;
//		m_isKin = false;
//	}
//
//	if (m_isDino||
//		m_isElf ||
//		m_isKin ||
//		m_isWitch)
//	{
//		return true;
//	}
//
//	return false;
//}

//bool SceneCharacterSelect::User2()
//{
//	// だいなそー選択
//	if (Pad2::IsTrigger(PAD_INPUT_1))// XBOX A
//	{
//		m_isDino2 = true;
//
//		m_isElf2 = false;
//		m_isKin2 = false;
//		m_isWitch2 = false;
//
//	}
//	// エルフ選択
//	if (Pad2::IsTrigger(PAD_INPUT_2))// XBOX 
//	{
//		m_isElf2 = true;
//
//		m_isDino2 = false;
//		m_isKin2 = false;
//		m_isWitch2 = false;
//	}
//	// きんにくろう選択
//	if (Pad2::IsTrigger(PAD_INPUT_3))// XBOX A
//	{
//		m_isKin2 = true;
//
//		m_isDino2 = false;
//		m_isElf2 = false;
//		m_isWitch2 = false;
//	}
//	// 魔女選択
//	if (Pad2::IsTrigger(PAD_INPUT_4))// XBOX A
//	{
//		m_isWitch2 = true;
//
//		m_isDino2 = false;
//		m_isElf2 = false;
//		m_isKin2 = false;
//	}
//
//	if (m_isDino2 ||
//		m_isElf2  ||
//		m_isKin2  ||
//		m_isWitch2)
//	{
//		return true;
//	}
//
//	return false;
//}
