#include "SceneMain.h"
#include "SceneResult.h"
#include "../Object/Player/Dinosaur/Dinosaur.h"
#include "../Object/Player/Elf/Elf.h"
#include "../Object/Player/Kinnikurou/Kinnikurou.h"
#include "../Object/Player/Witch/Witch.h"
#include "../Object/Stage/Stage.h"
#include "../Util/DrawFunctions.h"
#include "../condition.h"
#include <assert.h>
#include"../Object/Shot/ShotBase.h"
#include"../Util/Collision.h"

#include <iostream>

SceneMain::SceneMain(PlayerBase* Player1, PlayerBase* Player2) :
	m_isVictory1P(false),
	m_isVictory2P(false)
{
	m_pStage = new Stage;

	m_Player[0] = Player1;
	m_Player[1] = Player2;
	m_Coll = new Collision(m_Player[0], m_Player[1]);
}

SceneMain::~SceneMain()
{
	// メモリの開放
	delete m_Player[0];
	delete m_Player[1];
	delete m_pStage;
}

void SceneMain::Init()
{
	m_Player[0]->Init();
	m_Player[1]->Init();

	m_Player[0]->SetPadNum(1);
	m_Player[1]->SetPadNum(2);


	m_pStage->Init();
}

void SceneMain::End()
{
	m_Player[0]->End();
	m_Player[1]->End();
}

SceneBase* SceneMain::Update()
{
	m_Player[0]->Update();
	m_Player[1]->Update();

	if (m_Coll->IsColl1())
	{
		m_Player[0]->OnDamage(1);
	}

	else if (m_Coll->IsColl2())
	{
		m_Player[1]->OnDamage(1);
	}

	m_pStage->Update();

	// シーン遷移
	if (IsFading())
	{
		m_isFadeOut = IsFadingOut();
		SceneBase::UpdateFade();
		if (!IsFading() && m_isFadeOut)
		{
			// trueの場合
			// m_isVictory1P = 1Pの勝利
			// m_isVictory2P = 2Pの勝利
			return(new SceneResult(m_isVictory1P, m_isVictory2P));// 1ステージ切り替え
		}
	}

	// フェードインアウトしていない時
	if (!IsFading())
	{
		// デバッグ用シーン遷移
		if (m_Player[0]->GetHp() <= 0 || m_Player[1]->GetHp() <= 0)
		{
			StartFadeOut();
		}
	}

	// 1Pの勝利
	if (m_Player[1]->GetHp() <= 0)
	{
		m_isVictory1P = true;
	}
	// 2Pの勝利
	else if (m_Player[0]->GetHp() <= 0)
	{
		m_isVictory2P = true;
	}

	return this;
}

void SceneMain::Draw()
{
	// プレイヤーのHPの変数
	printfDx("Dino:%d\n", m_Player[0]->GetHp());
	printfDx("Kin:%d\n", m_Player[1]->GetHp());

	// プレイヤーの描画
	m_Player[0]->Draw();
	m_Player[1]->Draw();

	// ステージの描画
	m_pStage->Draw();

	SceneBase::DrawFade();
}