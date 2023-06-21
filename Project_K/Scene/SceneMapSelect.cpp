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
	const char* kDinoFile = "Data/Image/UI/StageSelect/Dino.bmp";
	const char* kElfFile = "Data/Image/UI/StageSelect/Elf.bmp";
	const char* kMachoFile = "Data/Image/UI/StageSelect/Macho.bmp";
	const char* kWizardFile = "Data/Image/UI/StageSelect/Wizard.bmp";
	const char* kRandFile = "Data/Image/UI/StageSelect/RandStage.png";

	// �t�H���g���
	const char* kFont = "HGP�s����";
}

SceneMapSelect::SceneMapSelect() :
	m_bgHandle(-1),
	m_handle(-1),
	m_font(-1),
	m_mapNum(1)
{
	m_font = CreateFontToHandle(kFont, 140, -1, -1);// �g�p����t�H���g
}

SceneMapSelect::~SceneMapSelect()
{
	DeleteGraph(m_stageHandle);
	DeleteGraph(m_bgHandle);
	DeleteGraph(m_handle);
}

void SceneMapSelect::Init()
{
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
			if (m_mapNum == 5)
			{
				m_mapNum = GetRand(4) + 1;
			}

			return (new SceneCharacterSelect(m_mapNum));
		}
	}

	if (!IsFading())
	{
		if (Pad::IsTrigger(PAD_INPUT_1, 1))
		{
			StartFadeOut();
		}
	}

	if (Pad::IsTrigger(PAD_INPUT_UP, 1))
	{
		if (m_mapNum < 5)
		{
			m_mapNum++;
		}
	}
	else if (Pad::IsTrigger(PAD_INPUT_DOWN, 1))
	{
		if (m_mapNum > 1)
		{
			m_mapNum--;
		}
	}

	// �}�b�v�̏��
	enum StageState
	{
		DinoStage = 1,	// �����X�e�[�W
		ElfStage,		// �G���t�X�e�[�W
		MachoStage,		// �}�b�`���X�e�[�W
		WizardStage,	// �����X�e�[�W
		RandStage,		// �����_���X�e�[�W
	};

	switch (m_mapNum)
	{
	case static_cast<int> (DinoStage):		// �����X�e�[�W
		m_handle = LoadGraph(kDinoFile);
		break;
	case static_cast<int> (ElfStage):		// �G���t�X�e�[�W
		m_handle = LoadGraph(kElfFile);
		break;
	case static_cast<int> (MachoStage):		// �}�b�`���X�e�[�W
		m_handle = LoadGraph(kMachoFile);
		break;
	case static_cast<int> (WizardStage):	// �����X�e�[�W
		m_handle = LoadGraph(kWizardFile);
		break;
	case static_cast<int> (RandStage) :		// �����_���X�e�[�W
		m_handle = LoadGraph(kRandFile);
	default:
		break;
	}

	return this;
}

void SceneMapSelect::Draw()
{
	DrawString(0, 0, "MapSelect", Color::kWhite);
	DrawFormatString(0, 15, 0xffffff, "MapNum = %d", m_mapNum);

	DrawGraph(0, 0, m_bgHandle, true);

	DrawBox(30, 175, 765, 190, 0x00ffff, true);

	DrawFormatStringToHandle(30, 75, 0x800000, m_font, "Select Stage");

	if (m_mapNum == 1)
	{
		DrawBox(855, 49, 855 + kFrameSizeX, 49 + kFrameSizeY, 0xffffff, true);
		DrawExtendGraph(50, 300, 658, 642, m_handle, true);
	}
	else if (m_mapNum == 2)
	{
		DrawBox(855, 395, 855 + kFrameSizeX, 395 + kFrameSizeY, 0xffffff, true);
		DrawExtendGraph(50, 300, 658, 642, m_handle, true);
	}
	else if (m_mapNum == 3)
	{
		DrawBox(855, 737, 855 + kFrameSizeX, 737 + kFrameSizeY, 0xffffff, true);
		DrawExtendGraph(50, 300, 658, 642, m_handle, true);
	}
	else if (m_mapNum == 4)
	{
		DrawBox(877 + kFrameSizeX, 233, 877 + kFrameSizeX * 2, 233 + kFrameSizeY, 0xffffff, true);
		DrawExtendGraph(50, 300, 658, 642, m_handle, true);
	}
	else if (m_mapNum == 5)
	{
		DrawBox(877 + kFrameSizeX, 574, 877 + kFrameSizeX * 2, 574 + kFrameSizeY, 0xffffff, true);
		DrawExtendGraph(50, 300, 658, 642, m_handle, true);
	}
	DrawGraph(0, 0, m_stageHandle, true);

	SceneBase::DrawFade();
}

void SceneMapSelect::ChooseNum()
{
}
