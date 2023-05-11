#include "Dinosaur.h"
#include "../../../condition.h"
#include "DinosaurStateManager.h"
#include"../../Shot/ShotBase.h"
#include"../../Shot/DinoShot.h"
#include"../../Shot/NullShot.h"

namespace
{
	const char* kFilename = "Data/Image/Player/kyouryuu/Enemy.png";
}

Dinosaur::Dinosaur() : 
	m_Handle(-1)
{
	m_hp = 150;
	m_Handle = LoadGraph(kFilename);
	m_StateManager = new DinosaurStateManager(m_Handle);
	m_StateManager->Init();
}

Dinosaur::~Dinosaur()
{
}

void Dinosaur::Init()
{
}

void Dinosaur::End()
{
}

void Dinosaur::Update()
{
	Pad::update();

	m_StateManager->Update();

	GetAttackSize();

	m_attackFlag = m_StateManager->GetAttackFlag();

	m_pos = m_StateManager->GetPos();

	for (int i = 0; i < kShotMax; i++)
	{
		// ショットの存在が消え、NullShotではないときm_ShotにNullShotを入れる
		if (!m_Shot[i]->GetExist() && !m_Shot[i]->GetNullShot())
		{
			m_Shot[i] = new NullShot();
		}
	}
	
	for (int i = 0; i < kShotMax; i++)
	{
		m_Shot[i]->Update();
	}

	////いなくなった敵は消えてもらう
	////消す命令のくせに、実際には決してなくて、後ろによけてるだけ
	//auto rmIt = std::remove_if(//条件に合致したものを消す
	//	m_Shot.begin(),	//対象はm_Enemyの最初から
	//	m_Shot.end(),		//最後まで
	//	//消えてもらう条件を表すラムダ式
	//	//trueだと消える。falseだと消えない
	//	[](ShotBase* &pShot) {
	//		return !pShot->IsExist();
	//	});

	////実際に範囲を指定して消す
	//m_Shot.erase(rmIt, m_Shot.end());
	////ここまでやらないと実際には消えないので注意

	// ショットのフラグたたったとき
	if (m_StateManager->GetshotFlag())
	{
		for (int i = 0; i < kShotMax; i++)
		{
			// ショットが存在しないとき
			if (!m_Shot[i]->GetExist())
			{
				m_Shot[i] = new DinoShot(m_pos, { 10,0 });
				break; //ループ抜ける
			}
		}
	}
}

void Dinosaur::Draw()
{
	m_StateManager->Draw();

	for (int i = 0; i < kShotMax; i++)
	{
		if (m_Shot[i] != nullptr)
		{
			m_Shot[i]->Draw();
		}
	}

	if (m_attackFlag)
	{
		DrawBox(m_pos.x + m_sizeLeftAttack, m_pos.y + m_sizeTopAttack,
			m_pos.x + m_sizeRightAttack, m_pos.y + m_sizeBottomAttack,
			0xff0000, false);
	}
}

void Dinosaur::GetAttackSize()
{
	m_sizeLeftAttack = m_StateManager->GetAttackSizeLeft();
	m_sizeTopAttack = m_StateManager->GetAttackSizeTop();
	m_sizeRightAttack = m_StateManager->GetAttackSizeRight();
	m_sizeBottomAttack = m_StateManager->GetAttackSizeBottom();
}

ShotBase* Dinosaur::GetShot(int i)
{
	return m_Shot[i];
}
