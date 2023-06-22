#include "SceneMapSelect.h"
#include "SceneCharacterSelect.h"
#include "SceneTitle.h"
#include "../Object/Stage/StageBase.h"
#include "../Util/Sound.h"

namespace
{
	// ˜gü‚ÌƒTƒCƒY
	constexpr int kFrameSizeX = 500;
	constexpr int kFrameSizeY = 290;

	//**** ƒeƒNƒXƒ`ƒƒî•ñ ****//
	const char* kRandFile = "Data/Image/UI/StageSelect/RandStage.png";
	const char* kDinoFile = "Data/Image/UI/StageSelect/Dino.bmp";
	const char* kElfFile = "Data/Image/UI/StageSelect/Elf.bmp";
	const char* kMachoFile = "Data/Image/UI/StageSelect/Macho.bmp";
	const char* kWizardFile = "Data/Image/UI/StageSelect/Wizard.png";

	// ƒtƒHƒ“ƒgî•ñ
	const char* kFont = "HGPs‘‘Ì";
}

SceneMapSelect::SceneMapSelect() :
	// ƒRƒ“ƒXƒgƒ‰ƒNƒ^‰Šú‰»
	m_bgHandle(-1),
	m_font(-1),
	m_mapNum(0)
{
	m_handle[0] = LoadGraph(kRandFile);		// ƒ‰ƒ“ƒ_ƒ€ƒXƒe[ƒW
	m_handle[1] = LoadGraph(kDinoFile);		// ‹°—³ƒXƒe[ƒW
	m_handle[2] = LoadGraph(kElfFile);		// ƒGƒ‹ƒtƒXƒe[ƒW
	m_handle[3] = LoadGraph(kMachoFile);	// ƒ}ƒbƒ`ƒ‡ƒXƒe[ƒW
	m_handle[4] = LoadGraph(kWizardFile);	// –‚—ƒXƒe[ƒW

	// Žg—p‚·‚éƒtƒHƒ“ƒg
	m_font = CreateFontToHandle(kFont, 140, -1, -1);
}

SceneMapSelect::~SceneMapSelect()
{
	// ƒnƒ“ƒhƒ‹‚Ìíœ
	DeleteGraph(m_stageHandle);
	DeleteGraph(m_bgHandle);

	for (int i = 0; i < 5; i++)
	{
		DeleteGraph(m_handle[i]);
	}
}

void SceneMapSelect::Init()
{
	// ƒOƒ‰ƒtƒBƒbƒNƒnƒ“ƒhƒ‹‚Ìƒ[ƒh
	m_stageHandle = LoadGraph("Data/Image/UI/StageSelect/ManyStage.png");
	m_bgHandle = LoadGraph("Data/Image/UI/StageSelect/Bg.png");
	// BGM Ä¶
	Sound::startBgm(Sound::SelectBgm, 200);
}

void SceneMapSelect::End()
{
	// BGM ’âŽ~
	Sound::stopBgm(Sound::SelectBgm);
}

SceneBase* SceneMapSelect::Update()
{
	// BGM ƒ‹[ƒv
	Sound::loopBgm(Sound::SelectBgm);

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

	// ƒJ[ƒ\ƒ‹ˆÚ“®ˆ—(”’l‚ÅŠÇ—)
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
	// ƒfƒoƒbƒO•\Ž¦
	DrawString(0, 0, "MapSelect", Color::kWhite);

	// ®F‚Ì”wŒi•`‰æ
	DrawGraph(0, 0, m_bgHandle, true);

	// wStage Selectx‰ºü•`‰æ
	DrawBox(30, 175, 765, 190, 0x00ffff, true);

	// ƒeƒLƒXƒg•`‰æ
	DrawFormatStringToHandle(30, 75, 0x800000, m_font, "Select Stage");

	// Œ»ÝƒJ[ƒ\ƒ‹‘I‘ð‚³‚ê‚Ä‚¢‚éƒXƒe[ƒW‚ÌŠg‘å•\Ž¦‚Ì•`‰æ
	DrawExtendGraph(50, 300, 658, 642, m_handle[m_mapNum], true);

	// ƒXƒe[ƒW‘I‘ðŽž‚Ì˜gü•`‰æ
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

	// ŠeƒXƒe[ƒW‚Ìk¬•`‰æ
	DrawGraph(0, 0, m_stageHandle, true);
	printfDx("%d", m_mapNum);

	// ƒtƒF[ƒhƒAƒEƒgˆ—
	SceneBase::DrawFade();
}

void SceneMapSelect::ChooseNum()
{
}
