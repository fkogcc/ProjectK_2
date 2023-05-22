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

class Stage
{
public:
	Stage();
	virtual ~Stage();

	void Init();
	void Update();
	void Draw();

	int GetStartX() const { return kStartX; }	// �n�_���WX�̎擾
	int GeStartY() const { return kStartY; }	// �n�_���WY�̎擾
	int GetEndX() const { return kEndX; }		// �I�_���WX�̎擾
	int GetEndY() const { return kEndY; }		// �I�_���WY�̎擾

private:
	Vec2 m_pos;

	int m_handle;

	std::vector<int> m_data;
};

