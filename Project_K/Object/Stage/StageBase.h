#pragma once
#include "../../Util/Vec2.h"
#include "../../Util/game.h"
#include "../Stage/StageBase.h"
#include<vector>

class StageBase
{
public :
	StageBase(int StageNo);			// �R���X�g���N�^
	virtual ~StageBase();	// �f�X�g���N�^

	void Init();	// ������
	void Update();	// �X�V
	void Draw();	// �`��

	int MapRead();	// �}�b�v�̓ǂݍ���

	int GetStartX() const { return m_startX; }	// �n�_���WX�̎擾
	int GetStartY() const { return m_startY; }	// �n�_���WY�̎擾
	int GetEndX() const { return m_endX; }		// �I�_���WX�̎擾
	int GetEndY() const { return m_endY; }		// �I�_���WY�̎擾

	struct MapInfo
	{
		Vec2 m_pos;		// �}�b�v�̍��W
		int m_chipNo=0;	// �}�b�v�`�b�v�̔ԍ�
	};

protected :
	std::vector<MapInfo> m_data;// vector�^��2�����z��ϐ�

	int m_handle;	// �O���t�B�b�N�n���h��
	int m_bgHandle;	// �w�i�p�O���t�B�b�N�n���h��
	int m_subPos;	// �}�b�`���O���t�B�b�N�n���h���̍��W����

	int m_startX;	// �n�_�̍��WX
	int m_startY;	// �n�_�̍��WY
	int m_endX;		// �I�_�̍��WX
	int m_endY;		// �I�_�̍��WY

	int m_stageNo;			// �X�e�[�W�̔ԍ�
	const char* m_filePath;	// �X�e�[�W��csv�p�X
};

