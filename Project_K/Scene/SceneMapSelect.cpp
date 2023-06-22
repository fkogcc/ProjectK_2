#include "SceneMapSelect.h"
#include "SceneCharacterSelect.h"
#include "SceneTitle.h"
#include "../Object/Stage/StageBase.h"

namespace
{
	// �g���̃T�C�Y
	constexpr int kFrameSizeX = 500;
	constexpr int kFrameSizeY = 290;

	//**** �e�N�X�`����� ****//
	const char* kRandFile = "Data/Image/UI/StageSelect/RandStage.png";
	const char* kDinoFile = "Data/Image/UI/StageSelect/Dino.bmp";
	const char* kElfFile = "Data/Image/UI/StageSelect/Elf.bmp";
	const char* kMachoFile = "Data/Image/UI/StageSelect/Macho.bmp";
	const char* kWizardFile = "Data/Image/UI/StageSelect/Wizard.png";

	// �t�H���g���
	const char* kFont = "HGP�s����";
}

SceneMapSelect::SceneMapSelect() :
	// �R���X�g���N�^������
	m_bgHandle(-1),
	m_font(-1),
	m_mapNum(0)
{
	m_handle[0] = LoadGraph(kRandFile);		// �����_���X�e�[�W
	m_handle[1] = LoadGraph(kDinoFile);		// �����X�e�[�W
	m_handle[2] = LoadGraph(kElfFile);		// �G���t�X�e�[�W
	m_handle[3] = LoadGraph(kMachoFile);	// �}�b�`���X�e�[�W
	m_handle[4] = LoadGraph(kWizardFile);	// �����X�e�[�W

	// �g�p����t�H���g
	m_font = CreateFontToHandle(kFont, 140, -1, -1);
}

SceneMapSelect::~SceneMapSelect()
{
	// �n���h���̍폜
	DeleteGraph(m_stageHandle);
	DeleteGraph(m_bgHandle);

	for (int i = 0; i < 5; i++)
	{
		DeleteGraph(m_handle[i]);
	}
}

void SceneMapSelect::Init()
{
	// �O���t�B�b�N�n���h���̃��[�h
	m_stageHandle = LoadGraph("Data/Image/UI/StageSelect/ManyStage.png");
	m_bgHandle = LoadGraph("Data/Image/UI/StageSelect/Bg.png");
}

void SceneMapSelect::End()
{

}

SceneBase* SceneMapSelect::Update()
{
	if (IsFading())
	{
		m_isFadeOut = IsFadingOut();
		SceneBase::UpdateFade();

		if (!IsFading() && m_isFadeOut)
		{
			if (m_mapNum == 0)
			{
				m_mapNum = GetRand(3) + 1;
			}

			return (new SceneCharacterSelect(m_mapNum));
		}
	}

	// 
	if (!IsFading())
	{
		if (Pad::IsTrigger(PAD_INPUT_1, 1))
		{
			StartFadeOut();
		}
	}

	// �J�[�\���ړ�����(���l�ŊǗ�)
	if (Pad::IsTrigger(PAD_INPUT_UP, 1))
	{
		if (m_mapNum > 0)
		{
			m_mapNum--;
		}
		else
		{
			m_mapNum = 4;
		}
	}
	else if (Pad::IsTrigger(PAD_INPUT_DOWN, 1))
	{
		if (m_mapNum < 4)
		{
			m_mapNum++;
		}
		else
		{
			m_mapNum = 0;
		}

	}

	return this;
}

void SceneMapSelect::Draw()
{
	// �f�o�b�O�\��
	DrawString(0, 0, "MapSelect", Color::kWhite);

	// ���F�̔w�i�`��
	DrawGraph(0, 0, m_bgHandle, true);

	// �wStage Select�x�����`��
	DrawBox(30, 175, 765, 190, 0x00ffff, true);

	// �e�L�X�g�`��
	DrawFormatStringToHandle(30, 75, 0x800000, m_font, "Select Stage");

	// ���݃J�[�\���I������Ă���X�e�[�W�̊g��\���̕`��
	DrawExtendGraph(50, 300, 658, 642, m_handle[m_mapNum], true);

	// �X�e�[�W�I�����̘g���`��
	switch (m_mapNum)
	{
	case 0:
		DrawBox(855, 49, 855 + kFrameSizeX, 49 + kFrameSizeY, 0xffffff, true);
		break;
	case 1:
		DrawBox(855, 410, 855 + kFrameSizeX, 410 + kFrameSizeY, 0xffffff, true); 
		break;
	case 2:
		DrawBox(855, 737, 855 + kFrameSizeX, 737 + kFrameSizeY, 0xffffff, true); 
		break;
	case 3:
		DrawBox(877 + kFrameSizeX, 233, 877 + kFrameSizeX * 2, 233 + kFrameSizeY, 0xffffff, true);
		break;
	case 4:
		DrawBox(877 + kFrameSizeX, 574, 877 + kFrameSizeX * 2, 574 + kFrameSizeY, 0xffffff, true);
		break;
	default:
		break;
	}

	// �e�X�e�[�W�̏k���`��
	DrawGraph(0, 0, m_stageHandle, true);
	printfDx("%d", m_mapNum);

	// �t�F�[�h�A�E�g����
	SceneBase::DrawFade();
}

void SceneMapSelect::ChooseNum()
{
}
