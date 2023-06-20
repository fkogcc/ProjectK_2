#pragma once
#include"Vec2.h"

class SelectUI
{
private:
	// �\����
	struct  AnimeData// �e�L�����N�^�������
	{
		float m_posY = 0;// �ʒu
		int m_imgWidth = 0;// �؂��镝
		int m_imgHight = 0;// �؂��鍂��
		float m_imgSize = 0;// �摜�̑傫���i�g�嗦�j
		int m_handle = -1;// �摜

		int m_maxWidth = 0;// �A�j���[�V�����̉��̍ő�l
		int m_maxHight = 0;// �A�j���[�V�����̏c�̍ő�l
		int m_animFrame = 0;// �A�j���[�V�����̑��x�i�t���[�����j
		const char* m_text = 0;// �e�L�X�g�i�L�������j
		int m_font = 0;// �g�p����t�H���g
	};
public:

	SelectUI();// �R���X�g���N�^
	virtual ~SelectUI();// �f�X�g���N�^

	void Init();// ������
	void Update();// �X�V����
	void Draw();// �`�揈��

	void InitLoad();// ���[�h����
	void InitFont();// ���[�h����
	void InitChar();// �L�����N�^�̏���������
	void SetCursor(int cursor1, int cursor2) { m_cursor1 = cursor1; m_cursor2 = cursor2; }// �J�[�\�����󂯎��֐�
	void SetCursorFlag(bool cursorFlag1, bool cursorFlag2) { m_cursorFlag1 = cursorFlag1; m_cursorFlag2 = cursorFlag2; }// �J�[�\���̃t���O���󂯎��
	void UpdateAnimation();// �A�j���[�V��������
	void DrawChar();// �L�����N�^�̕`�揈��
	void DrawLetter();//�e�L�X�g�̕`�揈��
	void SelectCursor(int cursor, int selectNum);//�I�΂�Ă���J�[�\���ɂ���ď�����ς���

private:
	//�摜������ϐ�
	int m_frameHandle;// �g
	int m_dinoHandle;// ��������
	int m_elfHandle;// �G���t����
	int m_kinnikuHandle;// �ؓ�����
	int m_witchHandle;// ����

	AnimeData m_temp;// �ꎞ�I�ɕۑ�����p�̕ϐ�
	AnimeData m_player1;// 1P
	AnimeData m_player2;// 2P
	AnimeData m_dino;// ��������
	AnimeData m_elf;// �G���t����
	AnimeData m_kinnniku;// �ؓ�����
	AnimeData m_witch;// ����

	int m_frameCount1;// 1P�̃A�j���[�V�����p�t���[��
	int m_indexWidth1;// 1P�̃A�j���[�V�����p�c
	int m_indexHight1;// 1P�̃A�j���[�V�����p��
	int m_frameCount2;// 2P�̃A�j���[�V�����p�t���[��
	int m_indexWidth2;// 2P�̃A�j���[�V�����p�c
	int m_indexHight2;// 2P�̃A�j���[�V�����p��

	int m_cursor1;// �J�[�\���̈ʒu�ۑ�1P�p
	int m_cursor2;// �J�[�\���̈ʒu�ۑ�2P�p
	bool m_cursorFlag1;// �J�[�\���̃t���O�ۑ�1P�p
	bool m_cursorFlag2;// �J�[�\���̃t���O�ۑ�2P�p
};