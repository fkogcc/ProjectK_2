#pragma once
#include "../../Util/Vec2.h"
#include "../../Util/game.h"
#include "../Stage/StageBase.h"
#include<vector>

class DinoStage : public StageBase
{
public:
	DinoStage();

	void Init();
	void Update();
	void Draw();

	int MapRead();	// csv�t�@�C���̓ǂݍ���

	struct MapInfo
	{
		Vec2 m_pos;		// �}�b�v�̍��W
		int m_chipNo;	// �}�b�v�`�b�v�̔ԍ�
	};

private:
	Vec2 m_pos;

	std::vector<MapInfo> m_data;// vector�^��2�����z��ϐ�
};

