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
		// �V���b�g�̑��݂������ANullShot�ł͂Ȃ��Ƃ�m_Shot��NullShot������
		if (!m_Shot[i]->GetExist() && !m_Shot[i]->GetNullShot())
		{
			m_Shot[i] = new NullShot();
		}
	}
	
	for (int i = 0; i < kShotMax; i++)
	{
		m_Shot[i]->Update();
	}

	////���Ȃ��Ȃ����G�͏����Ă��炤
	////�������߂̂����ɁA���ۂɂ͌����ĂȂ��āA���ɂ悯�Ă邾��
	//auto rmIt = std::remove_if(//�����ɍ��v�������̂�����
	//	m_Shot.begin(),	//�Ώۂ�m_Enemy�̍ŏ�����
	//	m_Shot.end(),		//�Ō�܂�
	//	//�����Ă��炤������\�������_��
	//	//true���Ə�����Bfalse���Ə����Ȃ�
	//	[](ShotBase* &pShot) {
	//		return !pShot->IsExist();
	//	});

	////���ۂɔ͈͂��w�肵�ď���
	//m_Shot.erase(rmIt, m_Shot.end());
	////�����܂ł��Ȃ��Ǝ��ۂɂ͏����Ȃ��̂Œ���

	// �V���b�g�̃t���O���������Ƃ�
	if (m_StateManager->GetshotFlag())
	{
		for (int i = 0; i < kShotMax; i++)
		{
			// �V���b�g�����݂��Ȃ��Ƃ�
			if (!m_Shot[i]->GetExist())
			{
				m_Shot[i] = new DinoShot(m_pos, { 10,0 });
				break; //���[�v������
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
