#pragma once
#include"Vec2.h"
class SelectUI
{
private:
	// �\����
	struct  AnimeData
	{
		float m_posY = 0;// �ʒu
		int m_imgWidth = 0;// �؂��镝
		int m_imgHight = 0;// �؂��鍂��
		int m_imgSize = 0;// �摜�̑傫���i�g�嗦�j
		int m_handle = -1;// �摜

		int m_maxWidth = 0;
		int m_maxHight = 0;
		int m_animFrame = 0;
	};
public:

	SelectUI();
	virtual ~SelectUI();

	void Init();
	void Update();
	void Draw();

	void InitLoad();
	void InitChar();
	void UpdateCursor(int cursor1, int cursor2) { m_cursor1 = cursor1; m_cursor2 = cursor2; }
	void UpdateAnimation();
	void SelectCursor(int cursor, int selectNum);

private:
	int m_wallHandle;
	int m_frameHandle;
	int m_dinoHandle;
	int m_elfHandle;
	int m_kinnikuHandle;
	int m_witchHandle;

	AnimeData m_temp;
	AnimeData m_player1;
	AnimeData m_player2;
	AnimeData m_dino;
	AnimeData m_elf;
	AnimeData m_kinnniku;
	AnimeData m_witch;

	int m_frameCount1;
	int m_indexWidth1;
	int m_indexHight1;
	int m_frameCount2;
	int m_indexWidth2;
	int m_indexHight2;

	int m_cursor1;
	int m_cursor2;
	int m_wallOffset;
	int m_waitFrame;


};

