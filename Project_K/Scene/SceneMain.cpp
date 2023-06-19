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
#include "../Util/UI.h"

#include <iostream>

SceneMain::SceneMain(PlayerBase* Player1, PlayerBase* Player2) :
	m_isVictory1P(false),
	m_isVictory2P(false),
	m_countDown(0)
{
	m_pStage = new Stage;

	m_pPlayer[0] = Player1;
	m_pPlayer[1] = Player2;
	m_pColl = new Collision(m_pPlayer[0], m_pPlayer[1]);
	m_pUi = new UI(m_pPlayer[0]->GetHp(), m_pPlayer[1]->GetHp());

	m_updateFunc = &SceneMain::UpdateCountDown;
}

SceneMain::~SceneMain()
{
	// メモリの開放
	delete m_pStage;
	delete m_pPlayer[0];
	delete m_pPlayer[1];
	delete m_pColl;
	delete m_pUi;
	
}

void SceneMain::Init()
{
	m_pPlayer[0]->SetPadNum(1);
	m_pPlayer[1]->SetPadNum(2);

	m_pPlayer[0]->Init();
	m_pPlayer[1]->Init();

	m_pStage->Init();
}

void SceneMain::End()
{
	m_pPlayer[0]->End();
	m_pPlayer[1]->End();


}

SceneBase* SceneMain::Update()
{
	(this->*m_updateFunc)();
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
		if (m_pPlayer[0]->GetHp() <= 0 || m_pPlayer[1]->GetHp() <= 0)
		{
			StartFadeOut();
		}
	}

	return this;
}

void SceneMain::Draw()
{
	// プレイヤーのHPの変数
	printfDx("Dino:%d\n", m_pPlayer[0]->GetHp());
	printfDx("Kin:%d\n", m_pPlayer[1]->GetHp());

	// ステージの描画
	m_pStage->Draw();

	// UIの描画
	m_pUi->Draw();

	// プレイヤーの描画
	m_pPlayer[0]->Draw();
	m_pPlayer[1]->Draw();

	// デバッグ用当たり判定描画
	m_pPlayer[0]->DebugDrawCollision();
	m_pPlayer[1]->DebugDrawCollision();

	//プレイヤーカーソル描画
	m_pUi->DrawPlayerCursor(m_pPlayer[0]->GetPos(), m_pPlayer[1]->GetPos());

	SceneBase::DrawFade();
}

void SceneMain::UpdateCountDown()
{
	m_countDown++;

	if (m_countDown >= 180)
	{
		m_updateFunc = &SceneMain::UpdateMain;
	}
}

void SceneMain::UpdateMain()
{
	m_pPlayer[0]->Update();
	m_pPlayer[1]->Update();

	m_pPlayer[0]->moveLimit();
	m_pPlayer[1]->moveLimit();

	// UIの更新処理
	m_pUi->Update();
	m_pUi->GetHp1(m_pPlayer[0]->GetHp());// 1PのHPを渡す
	m_pUi->GetHp2(m_pPlayer[1]->GetHp());// 2PのHPを渡す
	m_pUi->AttackFlag1(false);// 攻撃中のフラグ
	m_pUi->AttackFlag2(false);// 攻撃中のフラグ

	float toPlayer1 = m_pPlayer[1]->GetPos().x - m_pPlayer[0]->GetPos().x;
	float toPlayer2 = m_pPlayer[0]->GetPos().x - m_pPlayer[1]->GetPos().x;

	if (m_pColl->IsColl1())
	{
		m_pPlayer[0]->OnDamage(m_pPlayer[1]->GetDamage());
		m_pPlayer[0]->SetOnDamageFrame();
		m_pPlayer[0]->SetKnockBack(toPlayer1);
		m_pPlayer[1]->SetAttackFlag(false);
		m_pUi->AttackFlag1(true);// 攻撃中のフラグ
	}

	if (m_pColl->IsColl2())
	{
		m_pPlayer[1]->OnDamage(m_pPlayer[0]->GetDamage());
		m_pPlayer[1]->SetOnDamageFrame();
		m_pPlayer[1]->SetKnockBack(toPlayer2);
		m_pPlayer[0]->SetAttackFlag(false);
		m_pUi->AttackFlag2(true);// 攻撃中のフラグ
	}

	if (m_pColl->ShotColl1())
	{
		m_pPlayer[0]->OnDamage(1);
		m_pPlayer[0]->SetOnDamageFrame();
		m_pPlayer[0]->SetKnockBack(toPlayer1);
		m_pPlayer[1]->SetAttackFlag(false);
		m_pUi->AttackFlag1(true);// 攻撃中のフラグ
	}

	if (m_pColl->ShotColl2())
	{
		m_pPlayer[1]->OnDamage(1);
		m_pPlayer[1]->SetOnDamageFrame();
		m_pPlayer[1]->SetKnockBack(toPlayer2);
		m_pPlayer[1]->SetAttackFlag(false);
		m_pUi->AttackFlag2(true);// 攻撃中のフラグ
	}

	if (m_pColl->AttackColl())
	{
		m_pPlayer[0]->OnDamage(m_pPlayer[1]->GetDamage());
		m_pPlayer[0]->SetOnDamageFrame();
		m_pPlayer[1]->SetAttackFlag(false);
		m_pPlayer[1]->OnDamage(m_pPlayer[0]->GetDamage());
		m_pPlayer[1]->SetOnDamageFrame();
		m_pPlayer[0]->SetAttackFlag(false);
		m_pPlayer[0]->SetKnockBack(toPlayer1);
		m_pPlayer[1]->SetKnockBack(toPlayer2);
	}

	// 1Pの勝利
	if (m_pPlayer[1]->GetHp() <= 0)
	{
		m_isVictory1P = true;
	}
	// 2Pの勝利
	else if (m_pPlayer[0]->GetHp() <= 0)
	{
		m_isVictory2P = true;
	}

	// デバッグ用シーン遷移
	if (m_pPlayer[0]->GetHp() <= 0 || m_pPlayer[1]->GetHp() <= 0)
	{
		m_updateFunc = &SceneMain::UpdateDead;
	}
}

void SceneMain::UpdateDead()
{
	// プレイヤーのHPの変数
	//printfDx("Dino:%d\n", m_pPlayer[0]->GetHp());
	//printfDx("Kin:%d\n", m_pPlayer[1]->GetHp());

	// ステージの描画
	m_pStage->Draw();

	// UIの描画
	m_pUi->Draw();

	// プレイヤーの描画
	m_pPlayer[0]->Draw();
	m_pPlayer[1]->Draw();

	// デバッグ用当たり判定描画
	m_pPlayer[0]->DebugDrawCollision();
	m_pPlayer[1]->DebugDrawCollision();

	SceneBase::DrawFade();
}
