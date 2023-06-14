#include "DinosaurAttackBite.h"
#include"DinosaurIdle.h"

namespace
{
	//�摜������ւ��X�s�[�h
	constexpr int kGraphSpeed = 4;
	//�摜�̍ő吔
	constexpr int kGraphSize = 10;
	//�摜�̍Đ����~�߂�
	constexpr int kStopGraph = 4;
	//�U���d������
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
