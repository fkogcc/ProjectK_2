#pragma once
#include "../../Util/Vec2.h"
#include "../../Util/game.h"
#include<vector>
#include "../Stage/StageBase.h"

namespace
{
	constexpr int kStartX = 0;
	constexpr int kStartY = 700;
	constexpr int kEndX = Game::kScreenWidth;
	constexpr int kEndY = 700;
}

class StageBase;

class Stage : public StageBase
{
public:
	Stage();
	virtual ~Stage();

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

	std::vector<MapInfo> m_data;
};

