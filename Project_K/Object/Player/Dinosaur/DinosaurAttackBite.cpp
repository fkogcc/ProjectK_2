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
	constexpr int kAttackStan = 10;

	
	constexpr int kAttackFlagOn = 3;//�U���t���O��On�ɂȂ�^�C�~���O

	constexpr int kAttackFlagOff = 10;//�U���t���O��Off�ɂȂ�^�C�~���O
	
}

DinosaurAttackBite::~DinosaurAttackBite()
{
}

DinosaurStateBase* DinosaurAttackBite::Update(int padNum)
{
	m_attackFrame++;

	if (m_attackFrame == kAttackFlagOn)
	{
		m_attackFlag = true;
	}

	if (m_attackFrame == kAttackFlagOff)
	{
		m_attackFlag = false;
	}

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
