#include <Dxlib.h>
#include<vector>
#include<iostream>
#include<cassert>
#include "DinoStage.h"
#include "../../Util/game.h"
#include "../Stage/StageBase.h"

namespace
{
	// �e�N�X�`�����
	const char* kFileName = "Data/Image/Stage/Dino/Dino.png";
	const char* kBgFileName = "Data/Image/Stage/Dino/DinoBg.png";

	// �}�b�v�`�b�v��̃T�C�Y
	constexpr int kMapChipSize = 64;

	// �}�b�v�̃^�e���R�̃}�b�v�`�b�v�̐�
	constexpr int kMapHeight = 16;
	constexpr int kMapWidth = 30;
}

DinoStage::DinoStage() :
	m_pos(0, 700)
{
}

void DinoStage::Init()
{
	m_handle = LoadGraph(kFileName, false);
	m_bgHandle = LoadGraph(kBgFileName, false);
}

void DinoStage::Update()
{
	MapRead();
}

void DinoStage::Draw()
{
	DrawExtendGraph(0, 0, Game::kScreenWidth, Game::kScreenHeight, m_bgHandle, false);

	for (auto& data : m_data)
	{
		int scrX = data.m_chipNo % 16;
		int scrY = data.m_chipNo / 16;
		DrawRectGraph(static_cast<int>(data.m_pos.x), static_cast<int>(data.m_pos.y),
			scrX * kMapChipSize, scrY * kMapChipSize,
			kMapChipSize, kMapChipSize,
			m_handle,
			true, false);
	}
}

int DinoStage::MapRead()
{
	// csv�t�@�C����ǂݍ���Ő����̔z��ɂ�����

	FILE* fp;

	errno_t error = fopen_s(&fp, "Data/Image/Stage/Dino/DinoMap.csv", "r");

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
