#pragma once
#include "../../Util/Vec2.h"
#include "../../Util/game.h"

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

	int GetStartX() const { return kStartX; }	// 始点座標Xの取得
	int GeStartY() const { return kStartY; }	// 始点座標Yの取得
	int GetEndX() const { return kEndX; }		// 終点座標Xの取得
	int GetEndY() const { return kEndY; }		// 終点座標Yの取得

private:
	Vec2 m_pos;


};

