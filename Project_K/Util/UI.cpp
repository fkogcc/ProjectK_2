#include "UI.h"
#include "DxLib.h"
#include"game.h"

namespace
{
	const int kWidthGauge = 100;
	const int kHightGauge = 40;
	const int kTimeBoxSize = 50;// ���Ԃ�\������ꏊ�̃{�b�N�X�̃T�C�Y
	const int kCenter = Game::kScreenWidth / 2;// �^�񒆂̈ʒu
	const char* kFont = "HGP�s����";
	int kTextFont = 0;

	const char* kPlayerCursorHandle1 = "Data/Image/UI/1P.png";
	const char* kPlayerCursorHandle2 = "Data/Image/UI/2P.png";
}

UI::UI(int Hp1, int Hp2) :
	m_boxPos(kCenter, 90),	// ���Ԃ�\������{�b�N�X�̏�����
	m_timeCount(99 * 60),// ���Ԃ�}��^�C�}�[
	m_time(0),// �\�����鎞��
	m_letter("%d")// ����
{
	m_font = CreateFontToHandle(kFont, 70, -1, -1);// �g�p����t�H���g�A�T�C�Y
	kTextFont = CreateFontToHandle(kFont, 40, -1, -1);// �g�p����t�H���g�A�T�C�Y
	// 1P�̏�����
	m_ui1.m_pos = { m_boxPos.x - kTimeBoxSize,80 };
	m_ui1.m_temp = Hp1;
	m_ui1.m_life = m_ui1.m_temp;
	m_ui1.m_lower = m_ui1.m_life;
	m_ui1.m_countFrame = 50;// �^�C�}�[�̏�����
	m_ui1.m_attackFlag = false;// �U���������邽�߂̃t���O
	// 2P�̏�����
	m_ui2.m_pos = { m_boxPos.x + kTimeBoxSize,80 };
	m_ui2.m_temp = Hp2;
	m_ui2.m_life = m_ui2.m_temp;
	m_ui2.m_lower = m_ui2.m_life;
	m_ui2.m_countFrame = 50;// �^�C�}�[�̏�����
	m_ui2.m_attackFlag = false;// �U���������邽�߂̃t���O

	//�n���h�����[�h
	playerCursorHandle1 = LoadGraph(kPlayerCursorHandle1);
	playerCursorHandle2 = LoadGraph(kPlayerCursorHandle2);
}

void UI::Update()
{
	HpUpdate();
	FontUpdate();
}

void UI::Draw()
{
	HpDraw();
	FontDraw();
}

void UI::HpUpdate()
{
	m_ui1.m_countFrame++;//�^�C�}�[�̃J�E���g
	m_ui2.m_countFrame++;//�^�C�}�[�̃J�E���g
	if (m_ui1.m_temp >= 0)
	{
		m_ui1.m_life--;// ������茸�炷
		if (m_ui1.m_life < m_ui1.m_temp)
		{
			m_ui1.m_life = m_ui1.m_temp;
		}
	}
	if (m_ui2.m_temp >= 0)
	{
		m_ui2.m_life--;// ������茸�炷
		if (m_ui2.m_life < m_ui2.m_temp)
		{
			m_ui2.m_life = m_ui2.m_temp;
		}
	}
	if (m_ui1.m_countFrame >= 40)
	{
		m_ui1.m_lower = m_ui1.m_life;// ����HP������HP�����킹��
		m_ui1.m_countFrame = 0;
	}

	if (m_ui2.m_countFrame >= 40)
	{
		m_ui2.m_lower = m_ui2.m_life;// ����HP������HP�����킹��
		m_ui2.m_countFrame = 0;
	}
	if (m_ui1.m_attackFlag)// �U������������J�E���g�𐔂��Ȃ�
	{
		m_ui1.m_countFrame = 0;
	}
	if (m_ui2.m_attackFlag)// �U������������J�E���g�𐔂��Ȃ�
	{
		m_ui2.m_countFrame = 0;
	}
	if (m_ui1.m_life <= 0)
	{
		m_ui1.m_lower = 0;
		m_ui1.m_life = 0;
	}
	if (m_ui2.m_life <= 0)
	{
		m_ui2.m_lower = 0;
		m_ui2.m_life = 0;
	}
}

void UI::HpDraw()
{
	SetDrawBlendMode(DX_BLENDMODE_MULA, 150);			// ���₷���悤�ɂ�����ƍ��t�B���^�[�������Ă�
	// �`��
	DrawBox(static_cast<int>(m_boxPos.x) - kTimeBoxSize, static_cast<int>(m_boxPos.y) - kTimeBoxSize,
		static_cast<int>(m_boxPos.x) + kTimeBoxSize, static_cast<int>(m_boxPos.y) + kTimeBoxSize,
		0x000000, true);
	DrawBox(static_cast<int>(m_ui1.m_pos.x), static_cast<int>(m_ui1.m_pos.y),
		static_cast<int>(m_ui1.m_pos.x) - (5 * 100), static_cast<int>(m_ui1.m_pos.y) + kHightGauge, 0x000000, true);
	DrawBox(static_cast<int>(m_ui2.m_pos.x), static_cast<int>(m_ui2.m_pos.y),
		static_cast<int>(m_ui2.m_pos.x) + (5 * 100), static_cast<int>(m_ui2.m_pos.y) + kHightGauge, 0x000000, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);			//�ʏ�`��ɖ߂�

	//����HP�̕\��
	DrawBox(static_cast<int>(m_ui1.m_pos.x), static_cast<int>(m_ui1.m_pos.y),
		static_cast<int>(m_ui1.m_pos.x) - (5 * m_ui1.m_lower), static_cast<int>(m_ui1.m_pos.y) + kHightGauge, 0xff0000, true);
	DrawBox(static_cast<int>(m_ui2.m_pos.x), static_cast<int>(m_ui2.m_pos.y),
		static_cast<int>(m_ui2.m_pos.x) + (5 * m_ui2.m_lower), static_cast<int>(m_ui2.m_pos.y) + kHightGauge, 0xff0000, true);
	//����HP�̕\��
	DrawBox(static_cast<int>(m_ui1.m_pos.x), static_cast<int>(m_ui1.m_pos.y),
		static_cast<int>(m_ui1.m_pos.x) - (5 * m_ui1.m_life), static_cast<int>(m_ui1.m_pos.y) + kHightGauge, 0x00ff00, true);
	DrawBox(static_cast<int>(m_ui2.m_pos.x), static_cast<int>(m_ui2.m_pos.y),
		static_cast<int>(m_ui2.m_pos.x) + (5 * m_ui2.m_life), static_cast<int>(m_ui2.m_pos.y) + kHightGauge, 0x00ff00, true);
	DrawBox(static_cast<int>(m_ui1.m_pos.x), static_cast<int>(m_ui1.m_pos.y),
		static_cast<int>(m_ui1.m_pos.x) - (5 * 100), static_cast<int>(m_ui1.m_pos.y) + kHightGauge, 0x000000, false);
	DrawBox(static_cast<int>(m_ui2.m_pos.x), static_cast<int>(m_ui2.m_pos.y),
		static_cast<int>(m_ui2.m_pos.x) + (5 * 100), static_cast<int>(m_ui2.m_pos.y) + kHightGauge, 0x000000, false);

	DrawBox(static_cast<int>(m_boxPos.x) - kTimeBoxSize, static_cast<int>(m_boxPos.y) - kTimeBoxSize,
		static_cast<int>(m_boxPos.x) + kTimeBoxSize, static_cast<int>(m_boxPos.y) + kTimeBoxSize, 0x000000, false);
}

void UI::FontUpdate()
{
	// ���Ԃ����炷
	m_timeCount--;
	if (m_timeCount < 0)
	{
		m_timeCount = 0;// 0��肿�����Ⴍ�Ȃ�Ȃ��悤��
	}
	if (m_time < 10)
	{
		m_letter = "0%d";// �ꌅ��ɂȂ�����0��\��������
	}
}

void UI::FontDraw()
{
	m_time = m_timeCount / 60;
	// �ԃt�H���g�̕\��
	DrawFormatStringToHandle((Game::kScreenWidth -
		GetDrawStringWidthToHandle(m_letter, 2, m_font)) / 2 + 5,
		100 - 35, 0x800000, m_font, m_letter, m_time);
	// �t�H���g�̕\��
	DrawFormatStringToHandle((Game::kScreenWidth -
		GetDrawStringWidthToHandle(m_letter, 2, m_font)) / 2,
		100 - 40, 0x7fffff, m_font, m_letter, m_time);

	// �Ƃ��イ�ł�
	//DrawFormatStringToHandle(850,
	//	80, 0xffafaf, kTextFont, "1P");
	//DrawFormatStringToHandle(1020,
	//	80, 0xffafaf, kTextFont, "2P");
}


void UI::DrawPlayerCursor(Vec2 playerPos1, Vec2 playerPos2)
{
	DrawGraph(static_cast<int>(playerPos1.x) - 50, static_cast<int>(playerPos1.y) - 120,
		playerCursorHandle1, true);

	DrawGraph(static_cast<int>(playerPos2.x) - 50, static_cast<int>(playerPos2.y) - 120,
		playerCursorHandle2, true);
}
