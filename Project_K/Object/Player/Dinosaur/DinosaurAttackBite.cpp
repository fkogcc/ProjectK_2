#include "DinosaurAttackBite.h"
#include"DinosaurIdle.h"

namespace
{
	//‰æ‘œ‚ª“ü‚ê‘Ö‚í‚éƒXƒs[ƒh
	constexpr int kGraphSpeed = 4;
	//‰æ‘œ‚ÌÅ‘å”
	constexpr int kGraphSize = 10;
	//‰æ‘œ‚ÌÄ¶‚ğ~‚ß‚é
	constexpr int kStopGraph = 4;
	//UŒ‚d’¼ŠÔ
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
