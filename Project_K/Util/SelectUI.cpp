#include "SelectUI.h"
#include"game.h"
#include"DrawFunctions.h"
#include"DxLib.h"

namespace
{
	int kBottomStandard = Game::kScreenHeight - 150; // ���̊���i�I���v���C���[�̈ʒu�����ō��킹��j
}

SelectUI::SelectUI() :
	m_wallHandle(0),
	m_frameHandle(0),
	m_dinoHandle(0),
	m_elfHandle(0),
	m_kinnikuHandle(0),
	m_witchHandle(0),
	m_cursor1(0),
	m_frameCount1(0),
	m_indexWidth1(0),
	m_indexHight1(0),
	m_frameCount2(0),
	m_indexWidth2(0),
	m_indexHight2(0),
	m_cursor2(0),
	m_wallOffset(0),
	m_waitFrame(0)
{
}

SelectUI::~SelectUI()
{
	// �摜�̃f���[�g����
	my::MyDeleteGraph(m_wallHandle);
	my::MyDeleteGraph(m_frameHandle);
	my::MyDeleteGraph(m_dinoHandle);
	my::MyDeleteGraph(m_elfHandle);
	my::MyDeleteGraph(m_kinnikuHandle);
	my::MyDeleteGraph(m_witchHandle);
}

void SelectUI::Init()
{
	InitLoad();// �摜�̃��[�h
	InitChar();// �L�����N�^�̏���������
}

void SelectUI::Update()
{
	//m_wallOffset++;// �X�N���[��
	//if (m_wallOffset >= 64)
	//{
	//	m_wallOffset -= 64;// �X�N���[��
	//}
	SelectCursor(m_cursor1, 1);// �J�[�\���ɂ���ăA�b�v�f�[�g
	SelectCursor(m_cursor2, 2);// �J�[�\���ɂ���ăA�b�v�f�[�g 
	UpdateAnimation();// �A�j���[�V����
}

void SelectUI::Draw()
{
	//// �Ȃ񂩃X�N���[�����Ă�
	//for (int x = 0; x < Game::kScreenWidth / 64 + 1; x++)
	//{
	//	for (int y = 0; y < Game::kScreenHeight / 64 + 1; y++)
	//	{
	//		DrawGraph(x * 64 - m_wallOffset, y * 64, m_wallHandle, false);
	//	}
	//}
	// �t���[��
	for (int i = 1; i <= 4; i++)
	{
		int pos = 200;
		my::MyDrawRectRotaGraph(
			static_cast<int>(Game::kScreenWidth / 2), static_cast<int>(48) + pos * i,//�v���C���[�̈ʒu
			0, 0,// �摜�̉E��
			48, 48,
			4,
			DX_PI_F * 2,
			m_frameHandle,
			true,
			false);
	}

	// �A�C�R��(�Ƃ�������)
	my::MyDrawRectRotaGraph(
		static_cast<int>(Game::kScreenWidth / 2 + 270), static_cast<int>(200 - 25),//�v���C���[�̈ʒu
		320, 0,// �摜�̉E��
		450, 180,
		1.5,
		DX_PI_F * 2,
		m_dinoHandle,
		true,
		false);
	// �A�C�R��(Elf����)
	my::MyDrawRectRotaGraph(
		static_cast<int>(Game::kScreenWidth / 2), static_cast<int>(200 + 10),//�v���C���[�̈ʒu
		0, 0,// �摜�̉E��
		288, 100,
		6,
		DX_PI_F * 2,
		m_elfHandle,
		true,
		false);
	// �A�C�R��(����ɂ���)
	my::MyDrawRectRotaGraph(
		static_cast<int>(Game::kScreenWidth / 2), static_cast<int>(600 + 50),//�v���C���[�̈ʒu
		0, 0,// �摜�̉E��
		18, 18,
		7,
		DX_PI_F * 2,
		m_kinnikuHandle,
		true,
		false);
	// �A�C�R��(�܂���)
	my::MyDrawRectRotaGraph(
		static_cast<int>(Game::kScreenWidth / 2), static_cast<int>(840),//�v���C���[�̈ʒu
		0, 0,// �摜�̉E��
		48, 30,
		5,
		DX_PI_F * 2,
		m_witchHandle,
		true,
		false);


	// 1P���I�����Ă�L����
	my::MyDrawRectRotaGraph(
		400, m_player1.m_posY,//�v���C���[�̈ʒu
		m_player1.m_imgWidth * m_indexWidth1, m_player1.m_imgHight * m_indexHight1,// �摜�̉E��
		m_player1.m_imgWidth, m_player1.m_imgHight,// �摜�̐؂���
		m_player1.m_imgSize,// �摜�̊g�嗦
		DX_PI_F * 2,// ��]
		m_player1.m_handle,// �摜
		true,// ���]
		false);// ����

	// 2P���I�����Ă�L����
	my::MyDrawRectRotaGraph(
		Game::kScreenWidth - 400, m_player2.m_posY,//�v���C���[�̈ʒu
		m_player2.m_imgWidth * m_indexWidth2, m_player2.m_imgHight * m_indexHight2,// �摜�̉E��
		m_player2.m_imgWidth, m_player2.m_imgHight,// �摜�̐؂���
		m_player2.m_imgSize,// �摜�̊g�嗦
		DX_PI_F * 2,// ��]
		m_player2.m_handle,// �摜
		true,// ���]
		true);// ����
}

void SelectUI::InitLoad()
{
	// �摜�̃��[�h����
	m_wallHandle = my::MyLoadGraph("Data/Image/UI/pink.png");
	m_frameHandle = my::MyLoadGraph("Data/Image/UI/frame.png");
	m_dinoHandle = my::MyLoadGraph("Data/Image/Player/kyouryuu/Enemy.png");
	m_elfHandle = my::MyLoadGraph("Data/Image/Player/Elf/Elf.png");
	m_kinnikuHandle = my::MyLoadGraph("Data/Image/Player/Kinnikurou/Idle.png");
	m_witchHandle = my::MyLoadGraph("Data/Image/Player/Witch/Witch.png");
}

void SelectUI::InitChar()
{
	// P1�̏�����
	m_player1.m_imgWidth = 0;
	m_player1.m_imgHight = 0;
	m_player1.m_imgSize = 0;
	m_player1.m_posY = 0;
	m_player1.m_maxWidth = 0;
	m_player1.m_maxHight = 0;
	m_player1.m_animFrame = 0;
	m_temp = m_player1;

	// P2�̏�����
	m_player2.m_imgWidth = 0;
	m_player2.m_imgHight = 0;
	m_player2.m_imgSize = 0;
	m_player2.m_posY = 0;
	m_player2.m_maxWidth = 0;
	m_player2.m_maxHight = 0;
	m_player2.m_animFrame = 0;

	// �Ƃ�������̏�����
	m_dino.m_imgWidth = 640;
	m_dino.m_imgHight = 222;
	m_dino.m_imgSize = 2;
	float kyouryuuPos = kBottomStandard - (m_dino.m_imgHight * m_dino.m_imgSize / 2);
	m_dino.m_posY = kyouryuuPos;
	m_dino.m_maxWidth = 9;
	m_dino.m_maxHight = 2;
	m_dino.m_animFrame = 5;

	// �G���t����̏�����
	m_elf.m_imgWidth = 288;
	m_elf.m_imgHight = 128;
	m_elf.m_imgSize = 7;
	float elfPos = kBottomStandard - (m_elf.m_imgHight * m_elf.m_imgSize / 2);
	m_elf.m_posY = elfPos;
	m_elf.m_maxWidth = 12;
	m_elf.m_maxHight = 0;
	m_elf.m_animFrame = 5;

	// ����ɂ���̏�����
	m_kinnniku.m_imgWidth = 18;
	m_kinnniku.m_imgHight = 23;
	m_kinnniku.m_imgSize = 10;
	float kinPos = kBottomStandard - (m_kinnniku.m_imgHight * m_kinnniku.m_imgSize / 2);
	m_kinnniku.m_posY = kinPos;
	m_kinnniku.m_maxHight = 0;
	m_kinnniku.m_maxWidth = 2;
	m_kinnniku.m_animFrame = 60;

	// �����̏�����
	m_witch.m_imgWidth = 48;
	m_witch.m_imgHight = 48;
	m_witch.m_imgSize = 6;
	float witchPos = kBottomStandard - (m_witch.m_imgHight * m_witch.m_imgSize / 2);
	m_witch.m_posY = witchPos;
	m_witch.m_maxWidth = 1;
	m_witch.m_maxHight = 8;
	m_witch.m_animFrame = 15;

}

void SelectUI::UpdateAnimation()
{
	// 1P�̃A�j���[�V����
	m_frameCount1++;
	if (m_player1.m_animFrame <= m_frameCount1)
	{
		m_indexWidth1++;
		m_frameCount1 = 0;
	}
	if (m_player1.m_maxWidth <= m_indexWidth1)
	{
		m_indexHight1++;
		m_indexWidth1 = 0;
		m_frameCount1 = 0;
	}
	if (m_player1.m_maxHight <= m_indexHight1)
	{
		m_indexHight1 = 0;
	}
	// 2P�̃A�j���[�V����
	m_frameCount2++;
	if (m_player2.m_animFrame <= m_frameCount2)
	{
		m_indexWidth2++;
		m_frameCount2 = 0;
	}
	if (m_player2.m_maxWidth <= m_indexWidth2)
	{
		m_indexHight2++;
		m_indexWidth2 = 0;
		m_frameCount2 = 0;
	}
	if (m_player2.m_maxHight <= m_indexHight2)
	{
		m_indexHight2 = 0;
	}
}

void SelectUI::SelectCursor(int cursor, int selectNum)
{
	if (cursor == 0)
	{
		// �����Ȃ��[����
		m_temp.m_imgWidth = m_dino.m_imgWidth;
		m_temp.m_imgHight = m_dino.m_imgHight;
		m_temp.m_imgSize = m_dino.m_imgSize;
		m_temp.m_posY = m_dino.m_posY;
		m_temp.m_maxWidth = m_dino.m_maxWidth;
		m_temp.m_maxHight = m_dino.m_maxHight;
		m_temp.m_animFrame = m_dino.m_animFrame;
		m_temp.m_handle = m_dinoHandle;
	}
	if (cursor == 1)
	{
		// �G���t����
		m_temp.m_imgWidth = m_elf.m_imgWidth;
		m_temp.m_imgHight = m_elf.m_imgHight;
		m_temp.m_imgSize = m_elf.m_imgSize;
		m_temp.m_posY = m_elf.m_posY;
		m_temp.m_maxWidth = m_elf.m_maxWidth;
		m_temp.m_maxHight = m_elf.m_maxHight;
		m_temp.m_animFrame = m_elf.m_animFrame;
		m_temp.m_handle = m_elfHandle;
	}
	if (cursor == 2)
	{
		// ����ɂ���
		m_temp.m_imgWidth = m_kinnniku.m_imgWidth;
		m_temp.m_imgHight = m_kinnniku.m_imgHight;
		m_temp.m_imgSize = m_kinnniku.m_imgSize;
		m_temp.m_posY = m_kinnniku.m_posY;
		m_temp.m_maxWidth = m_kinnniku.m_maxWidth;
		m_temp.m_maxHight = m_kinnniku.m_maxHight;
		m_temp.m_animFrame = m_kinnniku.m_animFrame;
		m_temp.m_handle = m_kinnikuHandle;
	}
	if (cursor == 3)
	{
		// ����
		m_temp.m_imgWidth = m_witch.m_imgWidth;
		m_temp.m_imgHight = m_witch.m_imgHight;
		m_temp.m_imgSize = m_witch.m_imgSize;
		m_temp.m_posY = m_witch.m_posY;
		m_temp.m_maxWidth = m_witch.m_maxWidth;
		m_temp.m_maxHight = m_witch.m_maxHight;
		m_temp.m_animFrame = m_witch.m_animFrame;
		m_temp.m_handle = m_witchHandle;
	}
	if (selectNum == 1)
	{
		m_player1 = m_temp;
	}
	else
	{
		m_player2 = m_temp;
	}
}
