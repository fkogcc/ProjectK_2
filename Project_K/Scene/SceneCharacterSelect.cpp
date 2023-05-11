#include "SceneCharacterSelect.h"
#include "SceneMain.h"
#include "../Util/Pad.h"
#include "../Util/Pad2.h"

SceneCharacterSelect::SceneCharacterSelect():
	m_isDino(false),
	m_isElf(false),
	m_isKin(false),
	m_isWitch(false),
	m_isDino2(false),
	m_isElf2(false),
	m_isKin2(false),
	m_isWitch2(false)
{
}

SceneCharacterSelect::~SceneCharacterSelect()
{
}

void SceneCharacterSelect::Init()
{
}

void SceneCharacterSelect::End()
{
}

SceneBase* SceneCharacterSelect::Update()
{

	User1();
	User2();

	if (User1() && User2())
	{
		if(m_isDino2)m_isDino = m_isDino2;
		if(m_isElf2)m_isElf = m_isElf2;
		if(m_isKin2)m_isKin = m_isKin2;
		if(m_isWitch2)m_isWitch = m_isWitch2;
		
		return(new SceneMain(m_isDino, m_isElf, m_isKin, m_isWitch));// 1�X�e�[�W�؂�ւ�
	}

	return(new SceneMain(false, false, true, false));// 1�X�e�[�W�؂�ւ�
	return this;
}

void SceneCharacterSelect::Draw()
{

}

bool SceneCharacterSelect::User1()
{
	// �����Ȃ��[�I��
	if (Pad::IsTrigger(PAD_INPUT_1))// XBOX A
	{
		m_isDino = true;

		m_isElf = false;
		m_isKin = false;
		m_isWitch = false;

	}
	// �G���t�I��
	if (Pad::IsTrigger(PAD_INPUT_2))// XBOX 
	{
		m_isElf = true;

		m_isDino = false;
		m_isKin = false;
		m_isWitch = false;
	}
	// ����ɂ��낤�I��
	if (Pad::IsTrigger(PAD_INPUT_3))// XBOX A
	{
		m_isKin = true;

		m_isDino = false;
		m_isElf = false;
		m_isWitch = false;
	}
	// �����I��
	if (Pad::IsTrigger(PAD_INPUT_4))// XBOX A
	{
		m_isWitch = true;

		m_isDino = false;
		m_isElf = false;
		m_isKin = false;
	}

	if (m_isDino||
		m_isElf ||
		m_isKin ||
		m_isWitch)
	{
		return true;
	}

	return false;
}

bool SceneCharacterSelect::User2()
{
	// �����Ȃ��[�I��
	if (Pad2::IsTrigger(PAD_INPUT_1))// XBOX A
	{
		m_isDino2 = true;

		m_isElf2 = false;
		m_isKin2 = false;
		m_isWitch2 = false;

	}
	// �G���t�I��
	if (Pad2::IsTrigger(PAD_INPUT_2))// XBOX 
	{
		m_isElf2 = true;

		m_isDino2 = false;
		m_isKin2 = false;
		m_isWitch2 = false;
	}
	// ����ɂ��낤�I��
	if (Pad2::IsTrigger(PAD_INPUT_3))// XBOX A
	{
		m_isKin2 = true;

		m_isDino2 = false;
		m_isElf2 = false;
		m_isWitch2 = false;
	}
	// �����I��
	if (Pad2::IsTrigger(PAD_INPUT_4))// XBOX A
	{
		m_isWitch2 = true;

		m_isDino2 = false;
		m_isElf2 = false;
		m_isKin2 = false;
	}

	if (m_isDino2 ||
		m_isElf2  ||
		m_isKin2  ||
		m_isWitch2)
	{
		return true;
	}

	return false;
}
