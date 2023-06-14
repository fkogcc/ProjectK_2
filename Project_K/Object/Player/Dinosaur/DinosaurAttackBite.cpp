#include "DinosaurAttackBite.h"
#include"DinosaurIdle.h"

namespace
{
	//画像が入れ替わるスピード
	constexpr int kGraphSpeed = 4;
	//画像の最大数
	constexpr int kGraphSize = 10;
	//画像の再生を止める
	constexpr int kStopGraph = 4;
	//攻撃硬直時間
	constexpr int kAttackStan = 4;
}

DinosaurAttackBite::~DinosaurAttackBite()
{
}

DinosaurStateBase* DinosaurAttackBite::Update(int padNum)
{
	if (m_imagePosX < kStopGraph)
	{
		ChangeGraph(kGraphSpeed, kGraphSize, false);
	}
	else
	{
		m_imagePosX = kStopGraph;
		m_gapTime++;
	}

	if (m_gapTime > kAttackStan)
	{
		return new DinosaurIdle(m_vec);
	}


	return this;
}
