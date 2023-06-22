#pragma once
#include"Vec2.h"
class StageBase;		// �X�e�[�W

class SelectUI
{
private:
	// �\����
	struct  CharData// �e�L�����N�^�������
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

	void Init(int StageNo);// ������
	void Update();// �X�V����
	void Draw();// �`�揈��

	void InitLoad();// ���[�h����
	void InitFont();// ���[�h����
	void InitChar();// �L�����N�^�̏���������
	void SetCursor(int cursor1, int cursor2) { m_cursor1 = cursor1; m_cursor2 = cursor2; }// �J�[�\�����󂯎��֐�
	void SetCursorFlag(bool cursorFlag1, bool cursorFlag2) { m_cursorFlag1 = cursorFlag1; m_cursorFlag2 = cursorFlag2; }// �J�[�\���̃t���O���󂯎��
	void UpdateAnimation();// �A�j���[�V��������
	void UpdateChar(int cursor, int selectNum);//�I�΂�Ă���J�[�\���ɂ���ď�����ς���
	void UpdateCursor();// �J�[�\���̈ړ�����
	void DrawChar();// �L�����N�^�̕`�揈��
	void DrawLetter();//�e�L�X�g�̕`�揈��
	void DrawCursor();//	�J�[�\���̕\��

private:
	StageBase* m_pStageBase;	// �X�e�[�W�Z���N�g�V�[��

	CharData m_temp;// �ꎞ�I�ɕۑ�����p�̕ϐ�
	CharData m_player1;// 1P
	CharData m_player2;// 2P
	CharData m_dino;// ��������
	CharData m_elf;// �G���t����
	CharData m_kinnniku;// �ؓ�����
	CharData m_witch;// ����

private:
	//�摜������ϐ�
	int m_frameHandle;// �g
	int m_buttonHandle;// �ڂ���
	int m_dinoHandle;// ��������
	int m_elfHandle;// �G���t����
	int m_kinnikuHandle;// �ؓ�����
	int m_witchHandle;// ����

	// �A�j���[�V�����֌W
	int m_frameCount1;// 1P�̃A�j���[�V�����p�t���[��
	int m_indexWidth1;// 1P�̃A�j���[�V�����p�c
	int m_indexHight1;// 1P�̃A�j���[�V�����p��
	int m_frameCount2;// 2P�̃A�j���[�V�����p�t���[��
	int m_indexWidth2;// 2P�̃A�j���[�V�����p�c
	int m_indexHight2;// 2P�̃A�j���[�V�����p��
	int m_buttonAnimframe;// button�̃A�j���[�V�����p�t���[��
	int m_animInterval;//button�̃A�j���[�V�������n�܂�܂ł�interval
	int m_buttonIndexWidth;//button�̉摜��ύX����

	int m_centerPos1P;// 1P�̖��O�̒��S�ʒu���擾����
	int m_centerPos2P;// 2P�̖��O�̒��S�ʒu���擾����

	int m_cursor1;// �J�[�\���̈ʒu�ۑ�1P�p
	int m_cursor2;// �J�[�\���̈ʒu�ۑ�2P�p
	bool m_cursorFlag1;// �J�[�\���̃t���O�ۑ�1P�p
	bool m_cursorFlag2;// �J�[�\���̃t���O�ۑ�2P�p

	int m_cursolHeight;// �J�[�\����Y�̈ʒu
};