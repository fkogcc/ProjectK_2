#include "StageBase.h"
#include<cassert>
#include <Dxlib.h>
#include "../../Util/game.h"

namespace
{	
	//**** �e�N�X�`����� ****//
	// �����X�e�[�W
	const char* kDinoFile = "Data/Image/Stage/Dino/Dino.png";
	const char* kDinoBgFile = "Data/Image/Stage/Dino/DinoBg.png";
	const char* kDinoFilePath = "Data/Image/Stage/Dino/DinoMap.csv";
	// �G���t�X�e�[�W
	const char* kElfFile = "Data/Image/Stage/Elf/Elf.png";
	const char* kElfBgFile = "Data/Image/Stage/Elf/Background.png";
	const char* kElfFilePath = "Data/Image/Stage/Elf/Elf.csv";

	// �}�b�`���X�e�[�W
	const char* kMachoFile = "Data/Image/Stage/macho/macho.png";
	const char* kMachoBgFile = "Data/Image/Stage/macho/Background_0.png";
	const char* kMachoFilePath = "Data/Image/Stage/macho/macho.csv";

	// �����X�e�[�W
	const char* kWizardFile = "Data/Image/Stage/Wizard/Wizard.png";
	const char* kWizardBgFile = "Data/Image/Stage/Wizard/WizardBg0.png";
	const char* kWizardFilePath = "Data/Image/Stage/Wizard/Wizard.csv";

	//**** �}�b�v��� ****//
	// �}�b�v�`�b�v��̃T�C�Y
	constexpr int kMapChipSize = 64;

	// �}�b�v�̃^�e���R�̃}�b�v�`�b�v�̐�
	constexpr int kMapHeight = 16;
	constexpr int kMapWidth = 30;
}

StageBase::StageBase(int StageNo):
	m_handle(-1),
	m_bgHandle(-1),
	m_subPos(-1),
	m_startX(0),
	m_startY(700),
	m_endX(Game::kScreenWidth),
	m_endY(0),
	m_stageNo(StageNo),
	m_filePath("")
{
}

StageBase::~StageBase()
{
}

void StageBase::Init()
{
	// �}�b�v�̏��
	enum StageState
	{
		DinoStage = 1,	// �����X�e�[�W
		ElfStage,		// �G���t�X�e�[�W
		MachoStage,		// �}�b�`���X�e�[�W
		WizardStage,	// �����X�e�[�W
	};

	switch (m_stageNo)
	{
	case static_cast<int> (DinoStage) :	// �����X�e�[�W
		m_handle = LoadGraph(kDinoFile);
		m_bgHandle = LoadGraph(kDinoBgFile);
		m_filePath = kDinoFilePath;
		m_subPos = 0;
		break;
	case static_cast<int> (ElfStage):		// �G���t�X�e�[�W
		m_handle = LoadGraph(kElfFile);
		m_bgHandle = LoadGraph(kElfBgFile);
		m_filePath = kElfFilePath;
		m_subPos = 0;
		break;
	case static_cast<int> (MachoStage):	// �}�b�`���X�e�[�W
		m_handle = LoadGraph(kMachoFile);
		m_bgHandle = LoadGraph(kMachoBgFile);
		m_filePath = kMachoFilePath;
		m_subPos = 0;
		break;
	case static_cast<int> (WizardStage):	// �����X�e�[�W
		m_handle = LoadGraph(kWizardFile);
		m_bgHandle = LoadGraph(kWizardBgFile);
		m_filePath = kWizardFilePath;
		m_subPos = 0;
		break;
	default:
		break;
	}

	assert(m_handle != -1);
	assert(m_bgHandle != -1);
	MapRead();
}

void StageBase::Update()
{
}

void StageBase::Draw()
{
	DrawExtendGraph(0, 0 - m_subPos, Game::kScreenWidth, Game::kScreenHeight - m_subPos, m_bgHandle, false);

	for (auto& data : m_data)
	{
		int scrX = data.m_chipNo % 16;
		int scrY = data.m_chipNo / 16;
		DrawRectGraph(static_cast<int>(data.m_pos.x), static_cast<int>(data.m_pos.y) + 10,
			scrX * kMapChipSize, scrY * kMapChipSize,
			kMapChipSize, kMapChipSize,
			m_handle,
			true, false);

		printfDx("%d\n", static_cast<int>(data.m_pos.y));
	}

	
}

int StageBase::MapRead()
{
	if (m_filePath == "") return 0;

	FILE* fp;

	// csv�t�@�C����ǂݍ���Ő����̔z��ɂ�����
	
	errno_t error = fopen_s(&fp, m_filePath, "r");

	// 1�������ǂݍ���ŕ\��
	int chr;

	// �t�@�C������1�������ǂݍ���Ńt�@�C���̏I���܂Ń��[�v
	std::vector<int> dataTbl;
	// ���̗v�f��
	int wNum = -1;	// ���m��
	// ���̗v�f��������悤
	int tempW = 0;

	int tempNum = 0;

	while (true)
	{
		chr = fgetc(fp);	// 1�����ǂݍ���
		// ��؂蕶������������
		if (chr == ',' ||
			chr == '\n' ||
			chr == EOF)
		{
			// dataTbl�Ƀf�[�^������
			dataTbl.push_back(tempNum);
			tempNum = 0;

			// �t�@�C���̏I�[�ɗ�����I��
			if (chr == EOF)
			{
				break;
			}
			else if (chr == ',')
			{
				tempW++;	// �v�f��������
			}
			else     // chr == '\n'
			{
				tempW++;	// �v�f��������
				if (wNum < 0)
				{
					wNum = tempW;		// �v�f���m��
				}
				else
				{
					//  assert(wNum == tempW);	// ���̗v�f���͌Œ�Ȃ̂ň������assert
				}
				tempW = 0;
			}

			// �܂��I����ĂȂ��̂ő����ēǂݍ���
			continue;
		}

		// �f�[�^�͐����݂̂̂͂�
		assert(chr >= '0' && chr <= '9');

		// �����Ȃ̂͊m��
		// ������𐔒l�ɕϊ�������

		tempNum = (tempNum * 10) + chr - '0';

		// �f�[�^�̋�؂肪�����������_�ł����܂ł��f�[�^�̂ЂƂ܂Ƃ܂�
	}

	MapInfo mapinfo;
	// m_data��dataTbl�̒��g�����Ă�
	for (int i = 0; i < dataTbl.size(); i++)
	{
		int X = (i % kMapWidth) * kMapChipSize;
		int Y = (i / kMapWidth) * kMapChipSize;

		Vec2 pos = { static_cast<float>(X),static_cast<float>(Y) };

		mapinfo.m_pos = pos;
		mapinfo.m_chipNo = dataTbl[i];

		m_data.push_back(mapinfo);
	}

	// dataTbl�ɐ����������������Ă��邩�`�F�b�N
	int count = 0;
	for (auto& num : dataTbl)
	{
		if (count % wNum == 0)
		{
			printf("\n");
		}
		else
		{
			printf(",");
		}
		printf("%d, ", num);
		count++;
	}

	// �t�@�C�������
	fclose(fp);

	return 0;
}
