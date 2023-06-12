#pragma once
#include "../../Util/Vec2.h"
#include "../../Util/game.h"
#include<vector>

namespace
{
	constexpr int kStartX = 0;
	constexpr int kStartY = 700;
	constexpr int kEndX = Game::kScreenWidth;
	constexpr int kEndY = 700;
}

class WizardStage
{
public:
	WizardStage();
	virtual ~WizardStage();

	void Init();
	void Update();
	void Draw();

	int MapRead();	// csv�t�@�C���̓ǂݍ���

	int GetStartX() const { return kStartX; }	// �n�_���WX�̎擾
	int GeStartY() const { return kStartY; }	// �n�_���WY�̎擾
	int GetEndX() const { return kEndX; }		// �I�_���WX�̎擾
	int GetEndY() const { return kEndY; }		// �I�_���WY�̎擾

	// �O������̃X�e�[�W�Z���N�g�ԍ���setter
	int const GetSelectNum() const { m_selectNum; }

	struct MapInfo
	{
		Vec2 m_pos;		// �}�b�v�̍��W
		int m_chipNo;	// �}�b�v�`�b�v�̔ԍ�
	};

private:
	Vec2 m_pos;
	int m_handle;	// �O���t�B�b�N�n���h��
	int m_bgHandle;	// �w�i�p�O���t�B�b�N�n���h��

	int m_selectNum;	// �O�������int�^���l���i�[���邽�߂̕ϐ�

	std::vector<MapInfo> m_data;// vector�^��2�����z��ϐ�
};

