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
	m_isVictory2P(false)
{
	m_pStage = new Stage;

	m_pPlayer[0] = Player1;
	m_pPlayer[1] = Player2;
	m_pColl = new Collision(m_pPlayer[0], m_pPlayer[1]);
	m_pUi = new UI(m_pPlayer[0]->GetHp(), m_pPlayer[1]->GetHp());
}

SceneMain::~SceneMain()
{
	// �������̊J��
	delete m_pStage;
	delete m_pPlayer[0];
	delete m_pPlayer[1];
	delete m_pColl;
	delete m_pUi;
	
}

void SceneMain::Init()
{
	m_pPlayer[0]->Init();
	m_pPlayer[1]->Init();

	m_pPlayer[0]->SetPadNum(1);
	m_pPlayer[1]->SetPadNum(2);


	m_pStage->Init();

	//m_pStage->Init();
}

void SceneMain::End()
{
	m_pPlayer[0]->End();
	m_pPlayer[1]->End();


}

SceneBase* SceneMain::Update()
{
	m_pPlayer[0]->Update();
	m_pPlayer[1]->Update();

	// UI�̍X�V����
	m_pUi->Update();
	m_pUi->GetHp1(m_pPlayer[0]->GetHp());// 1P��HP��n��
	m_pUi->GetHp2(m_pPlayer[1]->GetHp());// 2P��HP��n��

	//if (m_pColl->IsColl1() && m_pColl->IsColl2())
	//{
	//	if (m_pPlayer[0]->GetAttackFrame() < m_pPlayer[1]->GetAttackFrame())
	//	{
	//		m_pPlayer[1]->OnDamage(m_pPlayer[0]->GetDamage());
	//		m_pPlayer[0]->SetAttackFlag(false);
	//	}

	//	if (m_pPlayer[0]->GetAttackFrame() >= m_pPlayer[1]->GetAttackFrame())
	//	{
	//		m_pPlayer[0]->OnDamage(m_pPlayer[1]->GetDamage());
	//		m_pPlayer[1]->SetAttackFlag(false);
	//	}

	//	/*if (m_Player[0]->GetAttackFrame() == m_Player[1]->GetAttackFrame())
	//	{
	//		m_Player[1]->OnDamage(1);
	//	}*/
	//}

	if (m_pColl->IsColl1())
	{
		m_pPlayer[0]->OnDamage(m_pPlayer[1]->GetDamage());
		m_pPlayer[1]->SetAttackFlag(false);

	}

	if (m_pColl->IsColl2())
	{
		m_pPlayer[1]->OnDamage(m_pPlayer[0]->GetDamage());
		m_pPlayer[0]->SetAttackFlag(false);
	}

	if (m_pColl->ShotColl1())
	{
		m_pPlayer[0]->OnDamage(1);
	}

	if (m_pColl->ShotColl2())
	{
		m_pPlayer[1]->OnDamage(1);
	}

	if (m_pColl->AttackColl())
	{
		m_pPlayer[0]->OnDamage(m_pPlayer[1]->GetDamage());
		m_pPlayer[1]->SetAttackFlag(false);
		m_pPlayer[1]->OnDamage(m_pPlayer[0]->GetDamage());
		m_pPlayer[0]->SetAttackFlag(false);
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
		if (m_pPlayer[0]->GetHp() <= 0 || m_pPlayer[1]->GetHp() <= 0)
		{
			StartFadeOut();
		}
	}

	// 1P�̏���
	if (m_pPlayer[1]->GetHp() <= 0)
	{
		m_isVictory1P = true;
	}
	// 2P�̏���
	else if (m_pPlayer[0]->GetHp() <= 0)
	{
		m_isVictory2P = true;
	}

	return this;
}

void SceneMain::Draw()
{
	// �v���C���[��HP�̕ϐ�
	printfDx("Dino:%d\n", m_pPlayer[0]->GetHp());
	printfDx("Kin:%d\n", m_pPlayer[1]->GetHp());

	// �v���C���[�̕`��
	m_pPlayer[0]->Draw();
	m_pPlayer[1]->Draw();

	// �f�o�b�O�p�����蔻��`��
	m_pPlayer[0]->DebugDrawCollision();
	m_pPlayer[1]->DebugDrawCollision();

	// �X�e�[�W�̕`��
	m_pStage->Draw();

	// UI�̕`��
	m_pUi->Draw();

	SceneBase::DrawFade();
}