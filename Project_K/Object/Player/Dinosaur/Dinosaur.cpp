#include "Dinosaur.h"
#include "../../../condition.h"
#include "DinosaurStateManager.h"
#include"../../Shot/ShotBase.h"
#include"../../Shot/DinoShot.h"
#include"../../Shot/NullShot.h"
#include<cassert>

namespace
{
	const char* kFilename = "Data/Image/Player/kyouryuu/Enemy.png";

	constexpr int kAttackDuration = 10; //攻撃持続時間
}

Dinosaur::Dinosaur() :
	m_Handle(-1)
{
	m_hp = 150;
	m_Handle = LoadGraph(kFilename);
	m_StateManager = new DinosaurStateManager(m_Handle);
	m_StateManager->Init();
	//m_pos.y = 100.0f;
}

Dinosaur::~Dinosaur()
{
}

void Dinosaur::Init()
{
	m_sizeLeft = -80;
	m_sizeTop = -50;
	m_sizeRight = 80;
	m_sizeBottom = 110;
}

void Dinosaur::End()
{
}

void Dinosaur::Update()
{
	// hpが0になったらm_StateManagerのm_deadFlagをtrueに
	if (m_hp < 0)
	{
		m_StateManager->SetDeadFlag();
	}
	// StateManagerのアップデート
	m_StateManager->Update(m_padNum);

	GetAttackSize(); //攻撃のサイズ取得

	// ダメージ取得
	m_damage = m_StateManager->GetOnDamage();

	// 攻撃フラグ取得
	m_attackFlag = m_StateManager->GetAttackFlag();

	// 攻撃フラグがtrueのとき
	if (m_attackFlag)
	{
		// カウントを増やす
		attackCountUp();
	}
	else// falseのとき
	{
		// カウントを0に
		m_attackFrameCount = 0;
	}

	// m_posの値を取得
	m_pos = m_StateManager->GetPos();

	for (int i = 0; i < kShotMax; i++)
	{
		// ショットの存在が消え、NullShotではないときm_ShotにNullShotを入れる
		if (!m_Shot[i]->GetExist() && !m_Shot[i]->GetNullShot())
		{
			m_Shot[i] = new NullShot();
		}
	}

	//ショットアップデート
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
				if (m_StateManager->GetLookLeft())
				{
					m_Shot[i] = new DinoShot(m_pos, { -15,0 });
				}
				else
				{
					m_Shot[i] = new DinoShot(m_pos, { 15,0 });
				}
				break; //ループ抜ける
			}
		}
	}
}

void Dinosaur::Draw()
{
	// キャラクター表示
	m_StateManager->Draw();

	//ショット表示
	for (int i = 0; i < kShotMax; i++)
	{
		if (m_Shot[i] != nullptr)
		{
			m_Shot[i]->Draw();
		}
	}

	// m_attackFlagがtrueのとき攻撃当たり判定を表示
	if (m_attackFlag)
	{
		/*DrawBox(static_cast<int>(m_pos.x) + m_attackSizeLeft, static_cast<int>(m_pos.y) + m_attackSizeTop,
			static_cast<int>(m_pos.x) + m_attackSizeRight, static_cast<int>(m_pos.y) + m_attackSizeBottom,
			0xff0000, false);*/
	}

	DrawBox(static_cast<int>(m_pos.x) + m_sizeLeft, static_cast<int>(m_pos.y) + m_sizeTop,
		static_cast<int>(m_pos.x) + m_sizeRight, static_cast<int>(m_pos.y) + m_sizeBottom,
		0xff0000, false);
}

void Dinosaur::GetAttackSize()
{
	m_attackSizeLeft = m_StateManager->GetAttackSizeLeft();
	m_attackSizeTop = m_StateManager->GetAttackSizeTop();
	m_attackSizeRight = m_StateManager->GetAttackSizeRight();
	m_attackSizeBottom = m_StateManager->GetAttackSizeBottom();
}

void Dinosaur::SetAttackFlag(bool attackFlag)
{
	m_attackFlag = attackFlag;
	m_StateManager->SetAttackFlag();
}

//ShotBase* Dinosaur::GetShot(int i)
//{
//	return m_Shot[i];
//}
