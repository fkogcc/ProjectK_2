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

class DinoStage
{
public:
	DinoStage();
	virtual ~DinoStage();

	void Init();
	void Update();
	void Draw();

	int MapRead();	// csv�t�@�C���̓ǂݍ���

	int GetStartX() const { return kStartX; }	// �n�_���WX�̎擾
	int GeStartY() const { return kStartY; }	// �n�_���WY�̎擾
	int GetEndX() const { return kEndX; }		// �I�_���WX�̎擾
	int GetEndY() const { return kEndY; }		// �I�_���WY�̎擾

	struct MapInfo
	{
		Vec2 m_pos;		// �}�b�v�̍��W
		int m_chipNo;	// �}�b�v�`�b�v�̔ԍ�
	};

private:
	Vec2 m_pos;
	int m_handle;	// �O���t�B�b�N�n���h��
	int m_bgHandle;	// �w�i�p�O���t�B�b�N�n���h��

	std::vector<MapInfo> m_data;// vector�^��2�����z��ϐ�
};

