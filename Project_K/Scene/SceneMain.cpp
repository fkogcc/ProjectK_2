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
	// �������̊J��
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

	// �V�[���J��
	if (IsFading())
	{
		m_isFadeOut = IsFadingOut();
		SceneBase::UpdateFade();
		if (!IsFading() && m_isFadeOut)
		{
			// true�̏ꍇ
			// m_isVictory1P = 1P�̏���
			// m_isVictory2P = 2P�̏���
			return(new SceneResult(m_isVictory1P, m_isVictory2P));// 1�X�e�[�W�؂�ւ�
		}
	}

	// �t�F�[�h�C���A�E�g���Ă��Ȃ���
	if (!IsFading())
	{
		// �f�o�b�O�p�V�[���J��
		if (m_Player[0]->GetHp() <= 0 || m_Player[1]->GetHp() <= 0)
		{
			StartFadeOut();
		}
	}

	// 1P�̏���
	if (m_Player[1]->GetHp() <= 0)
	{
		m_isVictory1P = true;
	}
	// 2P�̏���
	else if (m_Player[0]->GetHp() <= 0)
	{
		m_isVictory2P = true;
	}

	return this;
}

void SceneMain::Draw()
{
	// �v���C���[��HP�̕ϐ�
	printfDx("Dino:%d\n", m_Player[0]->GetHp());
	printfDx("Kin:%d\n", m_Player[1]->GetHp());

	// �v���C���[�̕`��
	m_Player[0]->Draw();
	m_Player[1]->Draw();

	// �X�e�[�W�̕`��
	m_pStage->Draw();

	SceneBase::DrawFade();
}