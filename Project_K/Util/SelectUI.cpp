#include "SelectUI.h"
#include"game.h"
#include"DrawFunctions.h"
#include"DxLib.h"
#include"FontFunction.h"

namespace
{
	int kBottomStandard = Game::kScreenHeight - 150; // ���̊���i�I���v���C���[�̈ʒu�����ō��킹��j
	int kSelectFont = 0;

	// ��ł��ꂢ�ɂ��남�o�J
	int kDinoFont = 0;
	int kElfFont = 0;
	int kKinFont = 0;
	int kWitchFont = 0;
	const char* kSelectText = "character select";

	const char* kDinoText = "�����Ȃ��[";
	const char* kElfText = "Elf";
	const char* kKinText = "����ɂ���";
	const char* kWitchText = "Witch";

	int kColor1P = 0xffffff;
	int kColor2P = 0xffffff;
}

SelectUI::SelectUI() :
	m_wallHandle(0),
	m_frameHandle(0),
	m_dinoHandle(0),
	m_elfHandle(0),
	m_kinnikuHandle(0),
	m_witchHandle(0),
	m_frameCount1(0),
	m_indexWidth1(0),
	m_indexHight1(0),
	m_frameCount2(0),
	m_indexWidth2(0),
	m_indexHight2(0),
	m_cursor1(0),
	m_cursor2(0),
	m_selectFont()
{
	font::MyFontPath("Data/Font/Valentina-Regular.ttf");
	kSelectFont = CreateFontToHandle("Valentina", 100, -1, -1);

	font::MyFontPath("Data/Font/851letrogo_007.ttf");
	kDinoFont = CreateFontToHandle("851���g���S", 50, -1, -1);
	font::MyFontPath("Data/Font/Valentina-Regular.ttf");
	kElfFont = CreateFontToHandle("Valentina", 50, -1, -1);;
	font::MyFontPath("Data/Font/kkm_analogtv.ttf");
	kKinFont = CreateFontToHandle("KKM-�A�i���O�e���r�t�H���g", 50, -1, -1);
	font::MyFontPath("Data/Font/Utusi Star Normal.otf");
	kWitchFont = CreateFontToHandle("Utusi Star", 50, -1, -1);
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

	// �t�H���g�̃f���[tp
	DeleteFontToHandle(m_selectFont);
	DeleteFontToHandle(kSelectFont);
}

void SelectUI::Init()
{
	InitLoad();// �摜�̃��[�h
	InitChar();// �L�����N�^�̏���������
}

void SelectUI::Update()
{
	SelectCursor(m_cursor1, 1);// �J�[�\���ɂ���ăA�b�v�f�[�g
	SelectCursor(m_cursor2, 2);// �J�[�\���ɂ���ăA�b�v�f�[�g 
	UpdateAnimation();// �A�j���[�V����
}

void SelectUI::Draw()
{
	DrawChar();
	DrawLetter();

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

	m_selectFont = kSelectFont;// �g�p����t�H���g�A�T�C�Y
}

void SelectUI::InitChar()
{
	// �킩��ɂ��������̏������Ȃ̂ł��ꂢ�ɂ�����

	// P1�̏�����
	m_player1.m_imgWidth = 0;
	m_player1.m_imgHight = 0;
	m_player1.m_imgSize = 0;
	m_player1.m_posY = 0;
	m_player1.m_maxWidth = 0;
	m_player1.m_maxHight = 0;
	m_player1.m_animFrame = 0;
	m_player1.m_text = kDinoText;
	m_player1.m_font = kDinoFont;
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
	m_dino.m_text = kDinoText;
	m_dino.m_font = kDinoFont;


	// �G���t����̏�����
	m_elf.m_imgWidth = 288;
	m_elf.m_imgHight = 128;
	m_elf.m_imgSize = 7;
	float elfPos = kBottomStandard - (m_elf.m_imgHight * m_elf.m_imgSize / 2);
	m_elf.m_posY = elfPos;
	m_elf.m_maxWidth = 12;
	m_elf.m_maxHight = 0;
	m_elf.m_animFrame = 5;
	m_elf.m_text = kElfText;
	m_elf.m_font = kElfFont;

	// ����ɂ���̏�����
	m_kinnniku.m_imgWidth = 18;
	m_kinnniku.m_imgHight = 23;
	m_kinnniku.m_imgSize = 10;
	float kinPos = kBottomStandard - (m_kinnniku.m_imgHight * m_kinnniku.m_imgSize / 2);
	m_kinnniku.m_posY = kinPos;
	m_kinnniku.m_maxHight = 0;
	m_kinnniku.m_maxWidth = 2;
	m_kinnniku.m_animFrame = 60;
	m_kinnniku.m_text = kKinText;
	m_kinnniku.m_font = kKinFont;

	// �����̏�����
	m_witch.m_imgWidth = 48;
	m_witch.m_imgHight = 48;
	m_witch.m_imgSize = 6;
	float witchPos = kBottomStandard - (m_witch.m_imgHight * m_witch.m_imgSize / 2);
	m_witch.m_posY = witchPos;
	m_witch.m_maxWidth = 1;
	m_witch.m_maxHight = 8;
	m_witch.m_animFrame = 15;
	m_witch.m_text = kWitchText;
	m_witch.m_font = kWitchFont;

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

void SelectUI::DrawChar()
{
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

void SelectUI::DrawLetter()
{
	// �L�����N�^�[�Z���N�g�̕\��
	DrawStringToHandle((Game::kScreenWidth -
		GetDrawStringWidthToHandle(kSelectText, 16, m_selectFont)) / 2,
		100 - 35, kSelectText, 0x800000, m_selectFont);

	int a = GetDrawStringWidthToHandle(kSelectText, 12, m_player1.m_font) / 2;

	// 1P�̖��O�\��
	DrawStringToHandle(400 - a,
		300, m_player1.m_text, kColor1P, m_player1.m_font);
	// 1P�̖��O�\��
	DrawStringToHandle(Game::kScreenWidth - 400,
		300, m_player2.m_text, kColor2P, m_player2.m_font);
	//// 1P�̖��O�\��
	//DrawStringToHandle((400 -
	//	GetDrawStringWidthToHandle(kCharText1P, 12, m_char1PFont)) / 2,
	//	500, kCharText1P, 0x800000, m_char1PFont);
	//// 1P�̖��O�\��
	//DrawStringToHandle((Game::kScreenWidth  -
	//	GetDrawStringWidthToHandle(kCharText1P, 12, m_char1PFont)) / 2,
	//	500, kCharText1P, 0x800000, m_char1PFont);
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
		m_temp.m_text = m_dino.m_text;
		m_temp.m_font = m_dino.m_font;
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
		m_temp.m_text = m_elf.m_text;
		m_temp.m_font = m_elf.m_font;
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
		m_temp.m_text = m_kinnniku.m_text;
		m_temp.m_font = m_kinnniku.m_font;
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
		m_temp.m_text = m_witch.m_text;
		m_temp.m_font = m_witch.m_font;
	}
	if (selectNum == 1)
	{
		m_player1 = m_temp;
	}
	else
	{
		m_player2 = m_temp;
	}
	if (m_cursorFlag1)
	{
		kColor1P = 0xff0000;
	}
	else
	{
		kColor1P = 0xffffff;
	}
	if (m_cursorFlag2)
	{
		kColor2P = 0x0000ff;
	}
	else
	{
		kColor2P = 0xffffff;
	}
}