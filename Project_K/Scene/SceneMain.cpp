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

SceneMain::SceneMain(bool isDino, bool isElf, bool isKin, bool isWitch) :
	m_pDino(nullptr),
	m_pElf(nullptr),
	m_pKin(nullptr),
	m_pWitch(nullptr),
	m_isDino(isDino),
	m_isElf(isElf),
	m_isKin(isKin),
	m_isWitch(isWitch)
	
{
	m_pDino = new Dinosaur;
	m_pElf = new Elf;
	m_pKin = new Kinnikurou;
	m_pWitch = new Witch;
	m_pStage = new Stage;


	m_Player[0] = new Dinosaur;
	m_Player[1] = new Kinnikurou;
	m_Coll = new Collision(m_Player[0], m_Player[1]);
}

SceneMain::~SceneMain()
{
	delete m_pDino;
	delete m_pElf;
	delete m_pKin;
	delete m_pWitch;
	delete m_Player[0];
	delete m_Player[1];

	delete m_pStage;
}

void SceneMain::Init()
{
	if (m_isDino) m_pDino->Init();
	if (m_isElf) m_pElf->Init();
	if (m_isKin) m_pKin->Init();
	if (m_isWitch) m_pWitch->Init();

	m_Player[0]->Init();
	m_Player[1]->Init();


	m_pStage->Init();
}

void SceneMain::End()
{
	if (m_isDino) m_pDino->End();
	if (m_isElf) m_pElf->End();
	if (m_isKin) m_pKin->End();
	//if (m_isWitch) m_pWitch->End();

	m_Player[0]->End();
	m_Player[1]->End();
}

SceneBase* SceneMain::Update()
{
	if (m_isDino) m_pDino->Update();
	if (m_isElf) m_pElf->Update();
	if (m_isKin) m_pKin->Update();
	if (m_isWitch) m_pWitch->Update();

	/*m_Player[0]->Update();
	m_Player[1]->Update();

	if (m_Coll->IsColl1())
	{
		m_Player[0]->OnDamage(1);
	}

	else if (m_Coll->IsColl2())
	{
		m_Player[1]->OnDamage(1);
	}*/

	m_pStage->Update();

	// シーン遷移
	if (IsFading())
	{
		m_isFadeOut = IsFadingOut();
		SceneBase::UpdateFade();

		if (!IsFading() && m_isFadeOut)
		{
			return(new SceneResult);// 1ステージ切り替え
		}
	}

	if (!IsFading())
	{
		/*if (Pad::IsTrigger(PAD_INPUT_1))
		{
			StartFadeOut();
		}*/
	}

	return this;
}

void SceneMain::Draw()
{
	if (m_isDino) m_pDino->Draw();
	if (m_isElf) m_pElf->Draw();
	if (m_isKin) m_pKin->Draw();
	if (m_isWitch) m_pWitch->Draw();

	/*printfDx("Dino:%d\n", m_Player[0]->GetHp());
	printfDx("Kin:%d\n", m_Player[1]->GetHp());

	m_Player[0]->Draw();
	m_Player[1]->Draw();*/

	m_pStage->Draw();

	SceneBase::DrawFade();
}